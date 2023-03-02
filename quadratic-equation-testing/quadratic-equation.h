#include <complex>

#pragma once

enum RESULT_QE {
	NOT_QUADRATIC_EQUATION,
	ONE_ROOT,
	TWO_ROOTS_NOT_COMPLEX,
	TWO_ROOTS_COMPLEX
};

// The implementation class of the quadratic equation.
class quadratic_equation
{
private:
	double a, b, c;

	// A function that generates a random floating-point number with specified precision.
	double getRandomNumber(double min, double max, int precision);

public:
	// Constructor with parameters.
	quadratic_equation(double a, double b, double c) { this->a = a;	this->b = b; this->c = c; }
	// The default constructor.
	quadratic_equation() : quadratic_equation(0., 0., 0.) {}

	// Methods for accessing private fields of the class.
	double get_a() const { return a; }
	double get_b() const { return b; }
	double get_c() const { return c; }

	// Methods for changing the closed fields of the class.
	void set_a(double a) { this->a = a; }
	void set_b(double b) { this->b = b; }
	void set_c(double c) { this->c = c; }
	void setRandom_abc(double min, double max, int precision);

	// A method for obtaining a solution to a quadratic equation.
	RESULT_QE solve(std::complex<double>& x1, std::complex<double>& x2);
};