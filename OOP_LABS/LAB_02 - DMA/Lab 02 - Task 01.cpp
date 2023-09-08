// Write a program that performs the following tasks
// 1. Declare two float pointers named ptrX and ptrY and initialize them with NULL.
// 2. Create two variables with values 4.5 and 9.3 on heap memory segment and assign their addresses to ptrX and ptrY respectively.
// Now print the following information:
// 1. The address of ptrX, value of ptrX and the value of memory location where it points to.
// 2. The address of ptrY, value of ptrY and the value of memory location where it points to.
// Free the resources allocated on heap memory segment

#include "iostream"

using namespace std;

int main()
{
	//creating two pointers 
	float* ptrX = NULL, * ptrY = NULL;

	//allocating memory on heap
	ptrX = new float(4.5f);
	ptrY = new float(9.3f);

	//displaying the required information
	cout << "&ptrX = " << &ptrX << " ptrX = " << ptrX << " *ptrX = " << *ptrX << endl;
	cout << "&ptrY = " << &ptrY << " ptrY = " << ptrY << " *ptrY = " << *ptrY << endl;

	//freeing the memory resources occupied on heap
	delete ptrX, ptrY;

	return 0;
}