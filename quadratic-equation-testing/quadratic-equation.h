#include <complex>

#pragma once

// Класс реализации квадратного уравнения.
class quadratic_equation
{
private:
	double a, b, c;

public:
	// Конструктор с параметрами.
	quadratic_equation(double a, double b, double c) { this->a = a;	this->b = b; this->c = c; }
	// Конструктор по умолчанию.
	quadratic_equation() : quadratic_equation(0.0, 0.0, 0.0) {}

	// Методы доступа к закрытым полям класса.
	double get_a() const { return a; }
	double get_b() const { return b; }
	double get_c() const { return c; }

	// Методы изменения закрытых полей класса.
	void set_a(double a) { this->a = a; }
	void set_b(double b) { this->b = b; }
	void set_c(double c) { this->c = c; }

	// Метод получения решения квдаратного уравнения.
	void solve(std::complex<double>& x1, std::complex<double>& x2);
};