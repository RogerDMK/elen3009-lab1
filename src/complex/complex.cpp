// complex.cpp
// Multiplying complex numbers

#include <iostream>	// contains the definition of cout, endl
#include <complex>	// contains the complex class definition

// Exercise 3.1 Any line of text/code between two forward slashes and the end of line will be ignored by the compiler,therefore will not execute

using namespace std; // cout, endl, complex are all part of this namespace
using complx = complex<float>;
int main()
{
	auto num1 = complx{2.0, 2.0};  // use auto for type deduction
	auto num2 = complx{4.0, -2.0}; // use uniform initialisation syntax (curly braces)

	auto answer = num1 * num2; // type deduced for 'answer' is: complex<float>

	cout << "The answer is: " << answer << endl;
	cout << "Or in a more familiar form: " << answer.real()
			<< " + " << answer.imag() << "j"
			<< endl	<< endl;

	// answer++;

	return 0;
}

