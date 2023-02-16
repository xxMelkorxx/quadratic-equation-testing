#include "quadratic-equation.h"

void quadratic_equation::solve(std::complex<double>& x1, std::complex<double>& x2)
{
	if (a == 0) {
		if (b != 0) {
			// TO DO: ��������� �������� - ������ ����.
			x1 = std::complex<double>(-1. * c / b);
			x2 = x1;
		}
		else if (c == 0) {
			// TO DO: X - ����� �����.
			throw std::exception("X - ����� �����.");
		}
		else {
			// TO DO: ������� �����������.
			throw std::exception("������� �����������!");
		}
	}
	else {
		double d = b * b - 4. * a * c;
		if (d > 0) {
			x1 = std::complex<double>((-b + sqrt(d)) / (2. * a));
			x2 = std::complex<double>((-b - sqrt(d)) / (2. * a));
		}
		else if (d < 0) {
			x1 = std::complex<double>(-b / (2. * a), sqrt(abs(d)) / (2. * a));
			x2 = std::complex<double>(-b / (2. * a), -sqrt(abs(d)) / (2. * a));
		}
		else {
			x1 = std::complex<double>(-b / (2. * a), 0);
			x2 = x1;
		}
	}

}
