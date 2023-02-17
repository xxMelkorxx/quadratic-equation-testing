#include <complex>

#pragma once

enum RESULT_QE {
	NOT_LINEAR,
	ONE_ROOT,
	TWO_ROOTS_NOT_COMPLEX,
	TWO_ROOTS_COMPLEX
};

//  ласс реализации квадратного уравнени€.
class quadratic_equation
{
private:
	double a, b, c;

	// ‘ункци€, котора€ генерирует случайное число с плавающей зап€той и указанной точностью
	// ‘ункци€ получает 3 параметра:
	// - min - нижний предел;
	// - max - верхний предел;
	// - precision - точность, количество знаков после зап€той.
	double getRandomNumber(double min, double max, int precision);

public:
	//  онструктор с параметрами.
	quadratic_equation(double a, double b, double c) { this->a = a;	this->b = b; this->c = c; }
	//  онструктор по умолчанию.
	quadratic_equation() : quadratic_equation(0., 0., 0.) {}

	// ћетоды доступа к закрытым пол€м класса.
	double get_a() const { return a; }
	double get_b() const { return b; }
	double get_c() const { return c; }

	// ћетоды изменени€ закрытых полей класса.
	void set_a(double a) { this->a = a; }
	void set_b(double b) { this->b = b; }
	void set_c(double c) { this->c = c; }
	void setRandom_abc(double min, double max, int precision);

	// ћетод получени€ решени€ квдаратного уравнени€.
	RESULT_QE solve(std::complex<double>& x1, std::complex<double>& x2);
};