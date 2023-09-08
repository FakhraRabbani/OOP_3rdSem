
#include<iostream>

using namespace std;

//Template Function

/*

//Single Template

template<class t>
t add(t var1, t var2)
{
	return var1 + var2;
}
*/

// Double template (explicit call)

template<class t1, class t2>
t1 add(t1 var1, t2 var2)
{
	return var1 + var2;
}

template <class arrayType>
void printArray(const arrayType ar[], const int size)
{
	for (int i = 0; i < size; i++)
		cout << ar[i] << endl;
}

int main()
{

	/*
	//Realtive calls

	cout << add(1, 2) << endl;
	cout << add(1.5, 2.5) << endl;
	cout << add(0.01f, 0.2f) << endl;

	//Absolute calls

	cout << add<int>(1, 2) << endl;
	cout << add<double>(1.5, 2.5) << endl;
	cout << add<float>(0.01f, 0.2f) << endl;

	cout << add<float>(1, 1.2f) << endl;
	cout << add<int>(1, 1.2f) << endl;
	*/

	
	//cout << add<float>(1, 2);
	//cout << add<int>(5, 'A');


	int arr[3] = { 1, 2 , 3 };
	printArray(arr, 3);



	return 0;
}