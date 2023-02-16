#include "CppUnitTest.h"
#include "..\quadratic-equation-testing\quadratic-equation.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

const int accuracy = 1e-10;

namespace testing
{
	TEST_CLASS(qe_constructor_testing)
	{
	public:
		// ���� �� �������� ������ ������������ �� ���������.
		TEST_METHOD(ConstructorTest)
		{
			quadratic_equation qe;

			Assert::IsTrue(qe.get_a() == 0, L"Assert IsTrue a");
			Assert::IsTrue(qe.get_b() == 0, L"Assert IsTrue b");
			Assert::IsTrue(qe.get_c() == 0, L"Assert IsTrue c");
		}

		// ���� �� �������� ������ ������������.
		TEST_METHOD(ParameterConstructorTest)
		{
			double a = 1, b = 2, c = 3;
			quadratic_equation qe(a, b, c);

			Assert::IsTrue(qe.get_a() == a, L"Assert IsTrue a");
			Assert::IsTrue(qe.get_b() == b, L"Assert IsTrue b");
			Assert::IsTrue(qe.get_c() == c, L"Assert IsTrue c");
		}
	};

	TEST_CLASS(qe_solver_testing)
	{
	public:
		// ������, ����� ������������ ����� 0.
		TEST_METHOD(SolverTest1)
		{
			double a = 1, b = 2, c = 3;
			quadratic_equation qe(a, b, c);
			std::complex<double> x1, x2;
			qe.solve(x1, x2);

			Assert::IsTrue(x1.real() == -1, L"Assert IsTrue x1");
			Assert::IsTrue(x2.real() == -1, L"Assert IsTrue x2");
		}

		// ������, ����� ������������ �������������, � ����� �����.
		TEST_METHOD(SolverTest2)
		{
			double a = -1, b = 7, c = 8;
			quadratic_equation qe(a, b, c);
			std::complex<double> x1, x2;
			qe.solve(x1, x2);

			Assert::IsTrue(x1.real() == -1, L"Assert IsTrue x1");
			Assert::IsTrue(x2.real() == 8, L"Assert IsTrue x2");
		}

		// ������, ����� ������������ �������������, � ����� �������.
		TEST_METHOD(SolverTest3)
		{
			double a = 9, b = -6, c = 1;
			quadratic_equation qe(a, b, c);
			std::complex<double> x1, x2;
			qe.solve(x1, x2);

			Assert::IsTrue(x1.real() == 1. / 3, L"Assert IsTrue x1");
			Assert::IsTrue(x2.real() == 1. / 3, L"Assert IsTrue x2");
		}

		// ������, ����� ������������ ������������� � ����� �����������.
		TEST_METHOD(SolverTest4)
		{
			double a = 2, b = 2, c = 1;
			quadratic_equation qe(a, b, c);
			std::complex<double> x1, x2;
			qe.solve(x1, x2);

			Assert::IsTrue(x1.real() == -0.5 && x1.imag() == 0.5, L"Assert IsTrue x1");
			Assert::IsTrue(x2.real() == -0.5 && x2.imag() == -0.5, L"Assert IsTrue x2");
		}
	};
}
