// Implement following function named pairWiseSum
// int* pairWiseSum(const int ar[], const int size, int& newArraySize);
// The parameters ar and size holds an array and its size respectively.
// The function should return a pointer to newly created array which contains sum of the pairs of elements together, starting with 
// elements at index 0 with 1, 2 with 3, 4 with 5 and so on. Store the size of new array in parameter newArraySize. keep the last 
// element as it is If the size of ar is odd. It should store 0 (zero) in newArraySize and return NULL if ar has no elements. The function
// should not display anything.
// For example, the input array with values 
// {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} results in the output array as {3, 7, 11, 15, 19}.
// {1, 2, 3, 4, 5, 6, 7, 8, 9} results in the output array as {3, 7, 11, 15, 9}.
// In main function declare arrays of different sizes. Fill the arrays with arbitrary values and then pass them to pairWiseSum function
// along with their sizes and all the required parameters. Display contents of the arrays returned by function pairWiseSum if any, 
// otherwise display appropriate message. Don’t forget to free the memory resource allocated by the program, if any.

#include<iostream>
#include<string>
using namespace std;

int* pairWiseSum(const int ar[], const int size, int& newArraySize)
{
	int newSize = (size / 2) + 1;

	if (ar == NULL)
	{
		return NULL;
	}

	int* p = new int[newSize];
		  
   for (int i = 0; i < size; i = i + 2)
   {
	   if (size % 2 != 0)
	   {
		   if (i == size - 1)
		   {
			   p[newArraySize] = ar[size - 1];
			   newArraySize++;
			   break;
		   }
	   }
	   p[newArraySize] = ar[i] + ar[i + 1];
	   newArraySize++;

	}

	return p;
}
int main()
{
	
	int arrA[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int arrB[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	int sizeA = 0;
	int sizeB = 0;

	int *p1 = pairWiseSum(arrA, 10, sizeA);
	int *p2 = pairWiseSum(arrB, 9, sizeB);

	cout << "Array A: " << endl;

	for (int i = 0; i < sizeA; i++)
	{
		cout << p1[i] << "\t";
	}
	cout << endl;

	cout << "Array B: " << endl;

	for (int i = 0; i < sizeA; i++)
	{
		cout << p2[i] << "\t";
	}

	delete[] p1;
	delete[] p2;
	
	return 0;
}
