// Implement the following function named subtractByPointer that accept three pointers to double.
// void subtractByPointer(double* ptrA, double* ptrB, double* ptrR);
// The function should calculate the difference of the contents of memory locations pointed by first two pointers (ptrA and ptrB) and 
// store the difference in third (ptrR). The function should not display anything.
// In main function asks the user to input two doubles and then passes them to subtractByPointer function. The result of subtraction
// should be displayed on the screen. The main function should not perform any calculations.

#include<iostream>

using namespace std;

void subtractByPointer(double *ptrA, double *ptrB, double *ptrR)
{
	*ptrR = *ptrA - *ptrB;
}
int main()
{
	double a;
	double b;

	cout << "Enter a: ";
	cin >> a;

	cout << "Enter b: ";
	cin >> b;

	double res;

	subtractByPointer(&a, &b, &res);

	cout << "The result of subtraction is: " << res << endl;
	return 0;
}
