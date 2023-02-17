#include <iostream>
#include "quadratic-equation.h"
using namespace std;

int main()
{
	quadratic_equation qe;
	for (int i = 0; i < 100; i++) {
		qe.setRandom_abc(-10, 10, 3);
		std::complex<double> x1(0, 0), x2(0, 0);
		RESULT_QE result = qe.solve(x1, x2);
		double a = qe.get_a();
		double b = qe.get_b();
		double c = qe.get_c();
		cout << a << '\t' << b << '\t' << c << '\t' 
			<< a * x1 * x1 + b * x1 + c << '\t'
			<< a * x2 * x2 + b * x2 + c << endl;
	}

	return 0;
}