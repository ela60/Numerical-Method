// C++ program for implementation of Regular Falsi Method for
// solving equations
#include<bits/stdc++.h>
using namespace std;
#define MAX_ITER 1000000

// An example function whose solution is determined using
// Regular Falsi Method. The function is x^3 - x^2 + 2
double func(double x)
{
	return x*x*x - x*x + 2;
}

// Prints root of func(x) in interval [a, b]
void regulaFalsi(double a, double b)
{
	if (func(a) * func(b) >= 0)
	{
		cout << "You have not assumed right a and b\n";
		return;
	}

	double c = a; // Initialize result

	for (int i=0; i < MAX_ITER; i++)
	{
		// Find the point that touches x axis
		c = (a*func(b) - b*func(a))/ (func(b) - func(a));

		// Check if the above found point is root
		if (func(c)==0)
			break;

		// Decide the side to repeat the steps
		else if (func(c)*func(a) < 0)
			b = c;
		else
			a = c;
	}
	cout << "The value of root is : " << c;
}

// Driver program to test above function
int main()
{
	// Initial values assumed
	double a =-200, b = 300;
	regulaFalsi(a, b);
	return 0;
}
