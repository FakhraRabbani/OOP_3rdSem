// Implement following function named getEvenOdd that accept an array ar along with its size n_ar
// void getEvenOdd(const int ar[], const int n_ar, int* &even, int& n_even, int* &odd, int& n_odd);
// The parameters ptrArray and size holds starting address and the size of an array respectively.
// The function gets all the even and odd numbers from the array ar and place them into a newly created arrays pointed by parameter 
// even and odd respectively. Store the sizes of even and odd arrays into n_even and n_odd respectively. It should store 0 (zero) and 
// NULL in parameters n_even/n_odd and even/odd respectively, if ar has no even/odd numbers. The function should not display
// anything.
// In main function declare an array of size 10. Fill the array with arbitrary values and then pass it to getEvenOdd function along with 
// its size and all the required parameters. After the execution of function display contents of the arrays pointed by even and odd.
// Display appropriate message(s), if even and/or odd arrays are empty. Don’t forget to free the memory resource allocated by the 
// program, if any.

#include "iostream"

using namespace std;

void getEvenOdd(const int ar[], const int n_ar, int*& even, int& n_even, int*& odd, int& n_odd)
{
	//make sure both holds 0
	n_even = n_odd = 0;

	//calculating the count of even and odd numbers of ar
	for (int i = 0; i < n_ar; i++)
	{
		if (ar[i] % 2 == 0)
			n_even++;
		else
			n_odd++;
	}

	//allocating memory (dynamically on heap) to even array which holds even numbers of ar only if there are some even
	if (n_even > 0)
	{
		even = new int[n_even];

		//copying even elements in respective arrays from ar
		for (int i = 0, j = 0; i < n_ar; i++)
		{
			if (ar[i] % 2 == 0)
			{
				even[j] = ar[i];
				j++;
			}
		}
	}

	//allocating memory (dynamically on heap) to even array which holds odd numbers of ar only if there are some odd
	if (n_odd > 0)
	{
		odd = new int[n_odd];

		//copying even elements in respective arrays from ar
		for (int i = 0, j = 0; i < n_ar; i++)
		{
			if (ar[i] % 2 != 0)
			{
				odd[j] = ar[i];
				j++;
			}
		}
	}
}

int main()
{
	int n_arEven = 0;	//holds the size of even number array returned by the function
	int* arEven = NULL;	//holds address of even number array allocated by function

	int n_arOdd = 0;	//holds the size of odd number array returned by the function
	int* arOdd = NULL;	//holds address of odd number array allocated by function

	int ar1[] = { 11, 2, 3, 5, 8, 9, 7, 1 };			//initializing ar1 array
	int ar1_size = sizeof(ar1) / sizeof(ar1[0]);	//size of array ar1

	//calling the funcion and getting the addresses of new arrays in arEven and arOdd along with their sizes n_arEven and n_arOdd respectively
	getEvenOdd(ar1, ar1_size, arEven, n_arEven, arOdd, n_arOdd);

	//display the contents of arEven if any
	if (arEven == NULL)	//or if(n_arEven == 0)
		cout << "No Even Numbers Exist in the Array!" << endl;
	else
	{
		cout << "Even Numbers Exist in the Array: ";
		for (int i = 0; i < n_arEven; i++)
		{
			cout << arEven[i] << "\t";	//or *(arEven + 1)
		}
	}

	//display the contents of arOdd if any
	if (arOdd == NULL)	//or if(n_arOdd == 0)
		cout << "No Odd Numbers Exist in the Array!" << endl;
	else
	{
		cout << endl << "Odd Numbers Exist in the Array: ";
		for (int i = 0; i < n_arOdd; i++)
		{
			cout << arOdd[i] << "\t";	//or *(arOdd + 1)
		}
	}

	//freeing the memory resources if any allocated on heap for arEven by getEvenOdd function
	if (arEven != NULL)	//or if(n_arEven != 0)
		delete[] arEven;

	//freeing the memory resources if any allocated on heap for arOdd by getEvenOdd function
	if (arOdd != NULL)	//or if(n_arOdd != 0)
		delete[] arOdd;

	return 0;
}