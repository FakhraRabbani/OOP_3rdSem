// Implement the following function named getMinMax that accept a pointer to integer and an integer to hold the size. The function 
// accepts two additional pointers to integers to store the minimum and maximum element exist in the array.
// void getMinMax(int* ptrArray, int size, int* ptrMin, int* ptrMax);
// The parameters ptrArray and size holds starting address and the size of an array respectively. 
// The function determines the minimum and maximum number exist in the array pointed by ptrArray and places them to the memory 
// locations pointed by parameters ptrMin and ptrMax respectively. The function should not display anything.
// In main function declare an array of size 10. Fill the array with arbitrary values and then passes it to getMinMax function along with 
// its size. Display the minimum and maximum number clearly on the screen. The main function should not perform any calculations.


#include<iostream>

using namespace std;

void getMinMax(int* ptrArray, int size, int *ptrMin, int *ptrMax)
{

	*ptrMax = *ptrArray;
	*ptrMin = *ptrArray;

	for (int i = 0; i < size; i++)
	{
		if (*(ptrArray + i) > *ptrMax)
		{
			*ptrMax = *(ptrArray + i);
		}		
	}

	for (int i = 0; i < size; i++)
	{
		if (*(ptrArray + i) < * ptrMin)
		{
			*ptrMin = *(ptrArray + i);
		}
	}
	
	
}
int main()
{
	int arr[10] = { 10, 11, 2, 3, -15, 5 , 6, 15, 8, 9};
	
	int min, max;
	getMinMax(arr, 10, &min, &max);

	cout << "Minimun value is: " << min << endl;
	cout << "Maximum value is: " << max << endl;

	return 0;
}
