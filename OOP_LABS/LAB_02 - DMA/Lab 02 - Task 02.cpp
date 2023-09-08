// Write a program that performs the following tasks
// 1. Ask the user to enter size of an integer array.
// 2. Allocate memory to an array based on the size provided by user.
// 3. Initialize the array content by reading them from user.
// 4. Calculate and display the sum of array elements.
// 5. Free any memory resources allocated by the program before exit

#include "iostream"

using namespace std;

int main()
{
	//to hold the size of array
	int size = 0;

	cout << "How many values you want to enter? ";
	cin >> size;

	cout << endl;

	//allocating memory on runtime (on heap)
	int* pa = new int[size];

	//getting input from user
	for (int i = 0; i < size; i++)
	{
		cout << "Enter value " << (i + 1) << " = ";
		cin >> pa[i];	//or cin >> *(pa + 1)
	}

	//to hold the sum of array elements
	int sum = 0;

	//calculating the sum of array elements
	for (int i = 0; i < size; i++)
	{
		sum = sum + pa[i];	//or sum = sum + *(pa + i)
	}

	//displaying the sum of array elements
	cout << "\nSum of values = " << sum << endl;

	//freeing the memory resources allocated on heap
	delete[] pa;

	return 0;
}