#include <math.h>
#include "CppUnitTest.h"
#include "..\quadratic-equation-testing\quadratic-equation.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testing
{
	TEST_CLASS(qe_constructor_testing)
	{
	public:
		// “ест на проверку работы конструктора по умолчанию.
		TEST_METHOD(ConstructorTest)
		{
			quadratic_equation qe;

			Assert::IsTrue(qe.get_a() == 0, L"Assert a");
			Assert::IsTrue(qe.get_b() == 0, L"Assert b");
			Assert::IsTrue(qe.get_c() == 0, L"Assert c");
		}

		// “ест на проверку работы конструктора.
		TEST_METHOD(ParameterConstructorTest)
		{
			double a = 1, b = 2, c = 3;
			quadratic_equation qe(a, b, c);

			Assert::IsTrue(qe.get_a() == a, L"Assert a");
			Assert::IsTrue(qe.get_b() == b, L"Assert b");
			Assert::IsTrue(qe.get_c() == c, L"Assert c");
		}
	};

	TEST_CLASS(qe_solver_testing)
	{
	public:
		TEST_METHOD(SolverTest1)
		{
			double a = 1, b = 2, c = 1;
			quadratic_equation qe(a, b, c);
			std::complex<double> x1, x2;
			qe.solve(x1, x2);

			Logger::WriteMessage(L"—лучай, когда дискриминант равен 0, а корень целый.");
			Assert::IsTrue(x1.real() == -1);
			Assert::IsTrue(x1 == x2);
		}

		TEST_METHOD(SolverTest2)
		{
			double a = 9, b = -6, c = 1;
			quadratic_equation qe(a, b, c);
			std::complex<double> x1, x2;
			qe.solve(x1, x2);

			Logger::WriteMessage(L"—лучай, когда дискриминант равен 0, а корень дробный.");
			Assert::IsTrue(x1.real() == 1. / 3);
			Assert::IsTrue(x1 == x2);
		}

		TEST_METHOD(SolverTest3)
		{
			double a = -1, b = 7, c = 8;
			quadratic_equation qe(a, b, c);
			std::complex<double> x1, x2;
			qe.solve(x1, x2);

			Logger::WriteMessage(L"—лучай, когда дискриминант положительный, а корни целые.");
			Assert::IsTrue(x1.real() == -1);
			Assert::IsTrue(x2.real() == 8);
		}

		TEST_METHOD(SolverTest4)
		{
			double a = 2, b = 2, c = 1;
			quadratic_equation qe(a, b, c);
			std::complex<double> x1, x2;
			qe.solve(x1, x2);

			Logger::WriteMessage(L"—лучай, когда дискриминант отрицательный, а корни комплексные.");
			Assert::IsTrue(x1.real() == -0.5 && x1.imag() == 0.5);
			Assert::IsTrue(x2.real() == -0.5 && x2.imag() == -0.5);
		}

		TEST_METHOD(SolverTest5)
		{
			double a = 2, b = 0, c = 0;
			quadratic_equation qe(a, b, c);
			std::complex<double> x1, x2;
			qe.solve(x1, x2);

			Logger::WriteMessage(L"—лучай, когда параметры b = 0, c = 0.");
			Assert::IsTrue(x1 == std::complex<double>(0, 0));
			Assert::IsTrue(x1 == x2);
		}

		TEST_METHOD(SolverTest6)
		{
			double a = 1, b = 2, c = 0;
			quadratic_equation qe(a, b, c);
			std::complex<double> x1, x2;
			qe.solve(x1, x2);

			Logger::WriteMessage(L"—лучай, когда параметр c = 0.");
			Assert::IsTrue(x1.real() == 0);
			Assert::IsTrue(x2.real() == -2);
		}

		TEST_METHOD(SolverTest7)
		{
			double a = 1, b = 0, c = -4;
			quadratic_equation qe(a, b, c);
			std::complex<double> x1, x2;
			qe.solve(x1, x2);

			Logger::WriteMessage(L"—лучай, когда параметр b = 0.");
			Assert::IsTrue(x1.real() == 2);
			Assert::IsTrue(x2.real() == -2);
		}

		TEST_METHOD(SolverTest8)
		{
			double a = 0, b = 2, c = -2;
			quadratic_equation qe(a, b, c);
			std::complex<double> x1, x2;
			qe.solve(x1, x2);

			Logger::WriteMessage(L"—лучай, когда a == 0 && b != 0 && c != 0 - линейное уравнение.");
			Assert::IsTrue(x1.real() == 1);
			Assert::IsTrue(x1 == x2);
		}

		//TEST_METHOD(SolverTest9)
		//{
		//	double a = 0, b = 0, c = 0;
		//	quadratic_equation qe(a, b, c);
		//	std::complex<double> x1, x2;
		//	//qe.solve(x1, x2);

		//	Logger::WriteMessage(L"—лучай, когда a == 0 && (b == 0 || c == 0) - отсутствует решение.");
		//	Assert::ExpectException<std::exception>(qe.solve(x1, x2), L"fdfd");
		//}

		TEST_METHOD(RandomParameterSolverTest1)
		{
			double a, b, c;
			srand(time(NULL));
			while (true) {
				a = -1 + (double)rand() / (double)(RAND_MAX / 2);
				b = -1 + (double)rand() / (double)(RAND_MAX / 2);
				c = -1 + (double)rand() / (double)(RAND_MAX / 2);
				if (a != 0) break;
			}
			quadratic_equation qe(a, b, c);
			std::complex<double> x1, x2;
			qe.solve(x1, x2);
			double result = pow((a * x1 * x1 + b * x2 + c).real(), 2) + pow((a * x1 * x1 + b * x2 + c).imag(), 2);

			Logger::WriteMessage(L"ѕроверка, когда при случайно заданых параметрах \n в диапазонах (-1, 1) и а != 0, \n уравнени€ равно 0.");
			Assert::IsTrue(result == 0);
		}

		TEST_METHOD(RandomParameterSolverTest2)
		{
			const double accuracy = 1e-20;	// “очность.
			double a, b, c;
			srand(time(NULL));
			while (true) {
				a = -1 + (double)rand() / (double)(RAND_MAX / 2);
				b = -1 + (double)rand() / (double)(RAND_MAX / 2);
				c = -1 + (double)rand() / (double)(RAND_MAX / 2);
				if (a != 0) break;
			}
			quadratic_equation qe(a, b, c);
			std::complex<double> x1, x2;
			qe.solve(x1, x2);
			double result = pow((a * x1 * x1 + b * x2 + c).real(), 2) + pow((a * x1 * x1 + b * x2 + c).imag(), 2);

			Logger::WriteMessage(L"ѕроверка, когда при случайно заданых параметрах \n в диапазонах (-1, 1) и а != 0, \n уравнени€ равно 0 с указанной точностью.");
			Assert::IsTrue(result <= accuracy || result >= -accuracy);
		}
	};
}