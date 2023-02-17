#include <math.h>
#include "CppUnitTest.h"
#include "..\quadratic-equation-testing\quadratic-equation.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testing
{
	TEST_CLASS(qe_constructor_testing)
	{
	public:
		TEST_METHOD(ConstructorTest)
		{
			quadratic_equation qe;

			Logger::WriteMessage(L"A test to check the work of the default constructor.");
			Assert::IsTrue(qe.get_a() == 0);
			Assert::IsTrue(qe.get_b() == 0);
			Assert::IsTrue(qe.get_c() == 0);
		}

		TEST_METHOD(ParameterConstructorTest)
		{
			double a = 1, b = 2, c = 3;
			quadratic_equation qe(a, b, c);

			Logger::WriteMessage(L"A test to check how the constructor works with parameters.");
			Assert::IsTrue(qe.get_a() == a);
			Assert::IsTrue(qe.get_b() == b);
			Assert::IsTrue(qe.get_c() == c);
		}

		TEST_METHOD(SetParametersTest)
		{
			double a = 1, b = 2, c = 3;
			quadratic_equation qe;
			qe.set_a(a);
			qe.set_b(b);
			qe.set_c(c);

			Logger::WriteMessage(L"A test for the operation of parameter assignment methods.");
			Assert::IsTrue(qe.get_a() == a);
			Assert::IsTrue(qe.get_b() == b);
			Assert::IsTrue(qe.get_c() == c);
		}
	};

	TEST_CLASS(qe_solver_testing)
	{
	public:
		TEST_METHOD(RandomParameterSolverTest_AbsoluteIdentity)
		{
			quadratic_equation qe;
			Logger::WriteMessage(L"Checking that: a*x*x + b*x + c == 0 (a != 0; b, c - random numbers)");
			for (int i = 0; i < 1000; i++) {
				qe.setRandom_abc(-10, 10, 3);
				std::complex<double> x1, x2;
				RESULT_QE result = qe.solve(x1, x2);
				double a = qe.get_a();
				double b = qe.get_b();
				double c = qe.get_c();

				Assert::IsTrue(result != NOT_LINEAR, L"Assert for linearity");
				Assert::IsTrue(
					a * x1 * x1 + b * x1 + c == std::complex<double>(0, 0) &&
					a * x2 * x2 + b * x2 + c == std::complex<double>(0, 0),
					L"Assert identity");
			}
		}

		TEST_METHOD(RandomParameterSolverTest_ApproxIdentity)
		{
			const double accuracy = 1e-20;

			quadratic_equation qe;
			Logger::WriteMessage(L"Checking that: -1e-10 < a*x*x + b*x + c < 1e-10 (a != 0; b, c - random numbers)");
			for (int i = 0; i < 1000; i++) {
				qe.setRandom_abc(-10, 10, 3);
				std::complex<double> x1, x2;
				RESULT_QE result = qe.solve(x1, x2);
				double a = qe.get_a();
				double b = qe.get_b();
				double c = qe.get_c();
				double magn_1 = pow((a * x1 * x1 + b * x1 + c).real(), 2) + pow((a * x1 * x1 + b * x1 + c).imag(), 2);
				double magn_2 = pow((a * x2 * x2 + b * x2 + c).real(), 2) + pow((a * x2 * x2 + b * x2 + c).imag(), 2);

				Assert::IsTrue(result != NOT_LINEAR, L"Assert for linearity");
				Assert::IsTrue((magn_1 < accuracy) && (magn_1 > -accuracy) && (magn_2 < accuracy) && (magn_2 > -accuracy), L"Assert identity");
			}
		}

		TEST_METHOD(SolverTest1)
		{
			double a = 1, b = 2, c = 1;
			quadratic_equation qe(a, b, c);
			std::complex<double> x1, x2;
			RESULT_QE result = qe.solve(x1, x2);

			Logger::WriteMessage(L"The case when the discriminantis 0 and the root is whole.");
			Assert::IsTrue(result == ONE_ROOT, L"Assert on number of roots");
			Assert::IsTrue(x1 == std::complex<double>(-1, 0));
			Assert::IsTrue(x1 == x2);
		}

		TEST_METHOD(SolverTest2)
		{
			double a = 9, b = -6, c = 1;
			quadratic_equation qe(a, b, c);
			std::complex<double> x1, x2;
			RESULT_QE result = qe.solve(x1, x2);

			Logger::WriteMessage(L"The case when the discriminant is 0 and the root is fractional.");
			Assert::IsTrue(result == ONE_ROOT, L"Assert on number of roots");
			Assert::IsTrue(x1 == std::complex<double>(1. / 3, 0));
			Assert::IsTrue(x1 == x2);
		}

		TEST_METHOD(SolverTest3)
		{
			double a = -1, b = 7, c = 8;
			quadratic_equation qe(a, b, c);
			std::complex<double> x1, x2;
			RESULT_QE result = qe.solve(x1, x2);

			Logger::WriteMessage(L"The case when the discriminant is positive and the roots are whole.");
			Assert::IsTrue(result == TWO_ROOTS_NOT_COMPLEX, L"Assert on number of roots");
			Assert::IsTrue(x1 == std::complex<double>(-1, 0));
			Assert::IsTrue(x2 == std::complex<double>(8, 0));
		}

		TEST_METHOD(SolverTest4)
		{
			double a = 2, b = 2, c = 1;
			quadratic_equation qe(a, b, c);
			std::complex<double> x1, x2;
			RESULT_QE result = qe.solve(x1, x2);

			Logger::WriteMessage(L"The case when the discriminant is negative and the roots are complex.");
			Assert::IsTrue(result == TWO_ROOTS_COMPLEX, L"Assert on number of roots");
			Assert::IsTrue(x1 == std::complex<double>(-0.5, 0.5));
			Assert::IsTrue(x2 == std::complex<double>(-0.5, -0.5));
		}

		TEST_METHOD(SolverTest5)
		{
			double a = 2, b = 0, c = 0;
			quadratic_equation qe(a, b, c);
			std::complex<double> x1, x2;
			RESULT_QE result = qe.solve(x1, x2);

			Logger::WriteMessage(L"The case when the parameters: b = 0, c = 0.");
			Assert::IsTrue(result == ONE_ROOT, L"Assert on number of roots");
			Assert::IsTrue(x1 == std::complex<double>(0, 0));
			Assert::IsTrue(x1 == x2);
		}

		TEST_METHOD(SolverTest6)
		{
			double a = 1, b = 2, c = 0;
			quadratic_equation qe(a, b, c);
			std::complex<double> x1, x2;
			RESULT_QE result = qe.solve(x1, x2);

			Logger::WriteMessage(L"The case when the parameter: c = 0.");
			Assert::IsTrue(result == TWO_ROOTS_NOT_COMPLEX, L"Assert on number of roots");
			Assert::IsTrue(x1 == std::complex<double>(0, 0));
			Assert::IsTrue(x2 == std::complex<double>(-2, 0));
		}

		TEST_METHOD(SolverTest7)
		{
			double a = 1, b = 0, c = -4;
			quadratic_equation qe(a, b, c);
			std::complex<double> x1, x2;
			RESULT_QE result = qe.solve(x1, x2);

			Logger::WriteMessage(L"The case when the parameter: b = 0.");
			Assert::IsTrue(result == TWO_ROOTS_NOT_COMPLEX, L"Assert on number of roots");
			Assert::IsTrue(x1 == std::complex<double>(2, 0));
			Assert::IsTrue(x2 == std::complex<double>(-2, 0));
		}

		TEST_METHOD(SolverTest8)
		{
			double a = 1, b = 0, c = 4;
			quadratic_equation qe(a, b, c);
			std::complex<double> x1, x2;
			RESULT_QE result = qe.solve(x1, x2);

			Logger::WriteMessage(L"The case when the parameter: b = 0, and the roots are complex.");
			Assert::IsTrue(result == TWO_ROOTS_COMPLEX, L"Assert on number of roots");
			Assert::IsTrue(x1 == std::complex<double>(0, 2));
			Assert::IsTrue(x2 == std::complex<double>(0, -2));
		}

		TEST_METHOD(SolverTest9)
		{
			double a = 0, b = 2, c = -2;
			quadratic_equation qe(a, b, c);
			std::complex<double> x1, x2;
			RESULT_QE result = qe.solve(x1, x2);

			Logger::WriteMessage(L"The case when: a == 0 && b != 0 && c != 0 - linear equation.");
			Assert::IsTrue(result == NOT_LINEAR, L"Assert for linearity");
		}
	};
}