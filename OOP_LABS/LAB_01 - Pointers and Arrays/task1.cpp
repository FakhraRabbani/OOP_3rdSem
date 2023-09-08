
//Write a program that performs the following tasks
//1. Declare integer variables named x and y and initialize them with 2 and 8 respectively.
//2. Declare pointer variables ptrX and ptrY and initialize them with the addresses of x and y respectively.
//Now print the following information:
//1. The address of x and the value of x.
//2. The address of ptrX, value of ptrX and the value of memory location where it points to.
//3. The address of y and the value of y.
//4. The address of ptrY, value of ptrY and the value of memory location where it points to.

#include<iostream>

using namespace std;

int main()
{
	int x = 2;
	int y = 8;

	int* ptrX = &x;
	int* ptrY = &y;

	cout << "Address of x is: " << &x << endl;
	cout << "Value of x is: " << x << endl;

	cout << "Address of ptrX is: " << &ptrX << endl;
	cout << "Value of ptrX is: " << ptrX << endl;
	cout << "Value of memory location where it points to(x): " << *ptrX << endl;
	
	cout << endl;

	cout << "Address of y  is: " << &y << endl;
	cout << "Value of y is: " << y << endl;

	cout << "Address of ptrY is: " << &ptrY << endl;
	cout << "Value of ptrY is: " << ptrY << endl;
	cout << "Value of memory location where it points to(y): " << *ptrY << endl;




	return 0;
}
