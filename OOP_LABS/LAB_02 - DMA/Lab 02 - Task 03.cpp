// Implement following function named getPositiveNumbers
// int* getPositiveNumbers(const int ar[], const int size, int& newArraySize);
// The parameters ar and size holds an array and its size respectively.
// The function should return a pointer to newly created array which contains only positive numbers exist in array ar and store its 
// size in parameter newArraySize. It should store 0 (zero) in newArraySize and return NULL if ar contains only negative numbers. The 
// function should not display anything.
// In main function declare an array of size 10. Fill the array with arbitrary values and then pass it to getPositiveNumbers function
// along with its size and all the required parameters. Display contents of the array returned by function getPositiveNumbers if any, 
// otherwise display a message “No Positive Numbers Exist in the Array!”. Don’t forget to free the memory resource allocated by the 
// program, if any.

#include "iostream"

using namespace std;

int* getPositiveNumbers(const int ar[], const int size, int& newArraySize)
{
	int* par = NULL;	//pointer to array allocated on heap to hold positive numbers

	if (size > 0)		//ar array has at least 1 element
	{
		//make sure it holds 0
		newArraySize = 0;

		//calculating the count of positive numbers of ar
		for (int i = 0; i < size; i++)
		{
			if (ar[i] >= 0)
				newArraySize++;
		}

		//allocating memory (dynamically on heap) to new array to hold positive numbers 
		par = new int[newArraySize];

		//copying positive numbers from ar to new array par
		for (int i = 0, j = 0; i < size; i++)
		{
			if (ar[i] >= 0)
			{
				par[j] = ar[i];
				j++;
			}
		}
	}
	
	return par;
}

int main()
{
	int posSize = 0;	//holds the size of positive number array returned by the function

	int ar1[] = { 1, -2, 3, 5, -1, 2, -7, 8 };	//initializing ar1 array
	int ar1_size = sizeof(ar1) / sizeof(ar1[0]);	//size of array ar1

	//calling the funcion and getting the address of new array in posArray and its size in posSize
	int* posArray = getPositiveNumbers(ar1, ar1_size, posSize);

	//display the contents of posArray if any
	if (posArray == NULL)	//or if(posSize == 0)
		cout << "No Positive Numbers Exist in the Array!" << endl;
	else
	{
		for (int i = 0; i < posSize; i++)
		{
			cout << posArray[i] << "\t";	//or *(posArray + 1)
		}
	}

	//freeing the memory resources if any allocated on heap for posArray by getPositiveNumbers function
	if(posArray != NULL)	//or if(posSize != 0)
		delete[] posArray;

	return 0;
}