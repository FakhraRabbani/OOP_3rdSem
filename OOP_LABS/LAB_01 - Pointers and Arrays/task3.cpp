// Implement the following function named arrayByPointer that accept a pointer to float and an integer to hold the size.
// void arrayByPointer(float* ptrArray, int size);
// The parameters ptrArray and size holds starting address and the size of an array respectively. 
// The function should display memory address of each array location along with its contents clearly. You are not allowed to use 
// subscript operator [] in arrayByPointer function.
// In main function declare an array of size 10. Fill the array with arbitrary values and then passes it to arrayByPointer function along 
// with its size.

#include<iostream>

using namespace std;

void arrayByPointer(float* ptrA, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Memory address: " << (ptrA + i) << "\tContent: " << *(ptrA + i)  << endl;
	}
}
int main()
{
	float arr[10] = { 0.25, 1.2, 2.0, 3.1, 4.0, 5.2, 6.5, 7.1, 8.0, 9.0 };
	arrayByPointer(arr, 10);

	
	return 0;
}
