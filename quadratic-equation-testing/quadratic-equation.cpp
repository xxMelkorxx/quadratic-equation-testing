#include <random>
#include "quadratic-equation.h"

RESULT_QE quadratic_equation::solve(std::complex<double>& x1, std::complex<double>& x2)
{
	if (a == 0) return NOT_QUADRATIC_EQUATION;
	else {
		double d = b * b - 4. * a * c;		// Calculation of the discriminant.
		if (d > 0) {
			x1 = std::complex<double>((-b + sqrt(d)) / (2. * a));
			x2 = std::complex<double>((-b - sqrt(d)) / (2. * a));
			return TWO_ROOTS_NOT_COMPLEX;
		}
		else if (d < 0) {
			x1 = std::complex<double>(-b / (2. * a), sqrt(abs(d)) / (2. * a));
			x2 = std::complex<double>(-b / (2. * a), -sqrt(abs(d)) / (2. * a));
			return TWO_ROOTS_COMPLEX;
		}
		else {
			x1 = std::complex<double>(-b / (2. * a), 0);
			x2 = x1;
			return ONE_ROOT;
		}
	}
}

void quadratic_equation::setRandom_abc(double min, double max, int precision)
{
	while (true) {
		this->a = getRandomNumber(min, max, precision);
		if (a != 0) break;
	}
	this->b = getRandomNumber(min, max, precision);
	this->c = getRandomNumber(min, max, precision);
}

std::random_device rd;
std::mt19937 gen(rd());
double quadratic_equation::getRandomNumber(double min, double max, int precision)
{
	std::uniform_int_distribution<> dist;
	double value;
	value = dist(gen) % (int)pow(10, precision);
	value = min + (value / pow(10, precision)) * (max - min);
	return value;
}