
#include<iostream>

using namespace std;

class Array
{

	int* arr;
	int size;

public:

	Array()
	{
		cout << "Default Constructor" << endl;

		size = 5;
		
		arr = new int[size];

		for (int i = 0; i < size; i++)
		{
			arr[i] = 0;
		}
		

		//arr = new int[size] {0, 0, 0, 0, 0};

	}

	Array(int size)
	{
		cout << "Parameterized Constructor" << endl;

		this->size = size;

		arr = new int[size];

		for (int i = 0; i < size; i++)
			arr[i] = 0;
	}

	Array(int size, int p[])
	{
		cout << "Parameterized Constructor" << endl;

		this->size = size;

		arr = new int[size];

		for (int i = 0; i < size; i++)
			arr[i] = p[i];
	}

	Array(const Array& obj)
	{
		cout << "Deep Copy Constructor" << endl;

		size = obj.size;

		arr = new int[size];

		for (int i = 0; i < size; i++)
			arr[i] = obj.arr[i];
	}

	~Array()
	{
		cout << "Destructor" << endl;

		delete[] arr;
	}

	
	Array operator=(const Array& obj)
	{
		if (this != &obj)
		{
			if (size == obj.size)
			{
				for (int i = 0; i < size; i++)
					arr[i] = obj.arr[i];
			}
		}

		return *this;
	}

	/*
	Array operator=(const Array& obj)
	{
		if (this != &obj)
		{
			delete[]arr;
			size = obj.size;
			arr = new int[size];

			for (int i = 0; i < size; i++)
				arr[i] = obj.arr[i];
			
		}

		return *this;
	}
	*/

	void print()
	{
		for (int i = 0; i < size; i++)
			cout << arr[i];
		cout << endl;
	}
};

int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };

	Array a1, a2(10), a3(5, arr);

	a1.print();
	a2.print();
	a3.print();

	a1 = a3;
	a1.print();
	a3.print();

	
	return 0;
}