#include <complex>

#pragma once

// ����� ���������� ����������� ���������.
class quadratic_equation
{
private:
	double a, b, c;

public:
	// ����������� � �����������.
	quadratic_equation(double a, double b, double c) { this->a = a;	this->b = b; this->c = c; }
	// ����������� �� ���������.
	quadratic_equation() : quadratic_equation(0.0, 0.0, 0.0) {}

	// ������ ������� � �������� ����� ������.
	double get_a() const { return a; }
	double get_b() const { return b; }
	double get_c() const { return c; }

	// ������ ��������� �������� ����� ������.
	void set_a(double a) { this->a = a; }
	void set_b(double b) { this->b = b; }
	void set_c(double c) { this->c = c; }

	// ����� ��������� ������� ����������� ���������.
	void solve(std::complex<double>& x1, std::complex<double>& x2);
};