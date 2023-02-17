#include <complex>

#pragma once

enum RESULT_QE {
	NOT_LINEAR,
	ONE_ROOT,
	TWO_ROOTS_NOT_COMPLEX,
	TWO_ROOTS_COMPLEX
};

// ����� ���������� ����������� ���������.
class quadratic_equation
{
private:
	double a, b, c;

	// �������, ������� ���������� ��������� ����� � ��������� ������� � ��������� ���������
	// ������� �������� 3 ���������:
	// - min - ������ ������;
	// - max - ������� ������;
	// - precision - ��������, ���������� ������ ����� �������.
	double getRandomNumber(double min, double max, int precision);

public:
	// ����������� � �����������.
	quadratic_equation(double a, double b, double c) { this->a = a;	this->b = b; this->c = c; }
	// ����������� �� ���������.
	quadratic_equation() : quadratic_equation(0., 0., 0.) {}

	// ������ ������� � �������� ����� ������.
	double get_a() const { return a; }
	double get_b() const { return b; }
	double get_c() const { return c; }

	// ������ ��������� �������� ����� ������.
	void set_a(double a) { this->a = a; }
	void set_b(double b) { this->b = b; }
	void set_c(double c) { this->c = c; }
	void setRandom_abc(double min, double max, int precision);

	// ����� ��������� ������� ����������� ���������.
	RESULT_QE solve(std::complex<double>& x1, std::complex<double>& x2);
};