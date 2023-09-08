// Write a generic class named Array that can hold an array of any valid data type (int, float, char etc...).
// 1. The class should have following two private data members.
// a. A generic pointer called data that holds an array of given data type allocated dynamically according to the specified size.
// b. An integer called size represents the number of elements in the array.
// 2. Implement the following constructors and a destructor:
// a. A default constructor that allocates an array of size 5 and initializes it to the so-called "empty array," i.e., an array whose
// array representation contains all zeroes.
// b. A constructor that accepts an integer as argument to represent the size of an array and initializes it to the so-called "empty
// array," i.e., an array whose array representation contains all zeroes.
// c. A copy constructor initializes an array object with an already existing object.
// d. A destructor to free any memory resources occupied by the array object.
// 3. Implement the following non-static member functions and operators:
// • getSize returns the size of array.
// • setElement that inserts a new element k at index i (both passed as argument) into an array, if possible, otherwise give an
// appropriate error message.
// • countElement accepts a key as argument and counts and returns the total occurrences of it in an array.
// • Assignment (=): Copies the data of the right-hand-side object to the left-hand-side object. If the size of the left-hand-side
// object is different from the right-hand-side object, reallocate the memory for the left-hand-side object based on the size
// of the right-hand-side object and then copy the data. Don't forget to update the size of the left-hand-side object.
// • getSubArray This member function takes two integer parameters start_index and end_index as arguments and returns a
// new Collection that contains all the values in the left-hand-side object from start_index to end_index, both inclusive. If the
// requested sub-collection cannot be created, it displays an appropriate error message and returns a Collection object
// consisting of NULL with its size set to 0.
// • Arithmetic binary (+) that inserts contents of right-hand-side object at the end of left-hand-side object and return the
// result. The function should not make any changes in left/right-hand-side object.
// • Stream insertion (<<) to take input from user for the data of an array.
// • Stream extraction (>>) to display the contents of data on the screen of an array.
// • Comparison (==) that determines whether two arrays are equal or not. The operator should return true if both the arrays
// (left-hand-side and right-hand-side) are equal, false otherwise.
// • Subscript ([]) for non-const objects. If the index is out of bounds, it displays an appropriate error message and returns −1,
// Without exiting the program.
// • Subscript ([]) for const objects. If the index is out of bounds, it displays an appropriate error message and returns −1,
// Without exiting the program.
// 4. Once you have written the class, write the main function and test its functionality by creating some objects of Array.


#include<iostream>

using namespace std;

template<typename t>
class Array
{
	t* data;
	int size;

public:

	Array()
	{
		cout << "Default Constructor" << endl;

		this->size = 5;
		data = new t[size];

		for (int i = 0; i < size; i++)
			data[i] = 0;
	}

	Array(int size)
	{
		cout << "Parameterized Constructor" << endl;

		this->size = size;
		data = new t[size];

		for (int i = 0; i < size; i++)
			data[i] = 0;
	}

	Array(const Array& obj)
	{
		cout << "Copy Constructor" << endl;

		this->size = obj.size;
		data = new t[size];

		for (int i = 0; i < size; i++)
			data[i] = obj.data[i];
	}

	~Array()
	{
		cout << "Destructor" << endl;

		delete[] data;
	}

	int getSize()const
	{
		return this->size;
	}

	void setElement(t k, int i)
	{
		if (i >= 0 && i < size)
			data[i] = k;
		else
			cout << "ERROR!! Index is out of bounds!" << endl;

	}

	int countElement(t key)
	{
		int count = 0;

		for (int i = 0; i < size; i++)
		{
			if (data[i] == key)
				count++;
		}

		return count;
	}

	Array operator=(const Array& d)
	{
		if (this != &d)
		{
			if (size != d.size)
			{
				delete[] data;
				size = d.size;
				data = new t[size];
			}

			for (int i = 0; i < size; i++)
				data[i] = d.data[i];
		}

		return *this;
	}

	Array getSubArray(int start_index, int end_index)
	{
		if (start_index >= 0 && start_index <= end_index && end_index < size)
		{
			int s;
			s = (end_index - start_index) + 1;

			Array sub_data(s);

			for (int i = 0; i < s; i++)
			{
				sub_data.data[i] = data[i + start_index];
			}

			return sub_data;
		}
		else
		{
			cout << "Sub-Array can't be created" << endl;
			Array temp(0);
			return temp;
		}

	}

	Array operator+(const Array& obj) const
	{
		int s = this->size + obj.size;

		Array res(s);

		for (int i = 0; i < this->size; i++)
		{
			res.setElement(data[i], i);

		}

		for (int i = 0; i < obj.size; i++)
		{
			res.setElement(obj.data[i], i + size);

		}

		return res;
	}

	friend istream& operator >> (istream& input, Array& obj)
	{
		cout << "Enter array elements: " << endl;

		for (int i = 0; i < obj.size; i++)
		{
			cout << "Enter element of index " << i << endl;
			input >> obj.data[i];
		}
		return input;
	}

	friend ostream& operator << (ostream& print, const Array& obj)
	{
		print << "Data: " << endl;
		print << "[ ";

		for (int i = 0; i < obj.size; i++)
		{
			print << obj.data[i] << ", ";
		}
		print << " ]" << endl;

		return print;
	}

	bool operator==(const Array& obj)const
	{
		if (this->size != obj.size)
			return false;

		for (int i = 0; i < size; i++)
		{
			if (data[i] != obj.data[i])
				return false;
		}
		return true;
	}

	t& operator[](int index)
	{
		if (index >= 0 && index < size)
		{
			return data[index];
		}
		else
		{
			cout << "Index is out of bounds.." << endl;
			static t temp;
			temp = -1;
			return temp;
		}
	}

	t operator[](int index) const
	{
		if (index >= 0 && index < size)
		{
			return data[index];
		}
		else
		{
			cout << "Index is out of bounds" << endl;
			return -1;
		}
	}

	
};

int main()
{

	Array<int>ar3, ar4(10);

	cin >> ar4;
	cout << ar4;

	Array<int>ar5(ar4);

	cout << ar5;

	//Assigment operator
	ar3 = ar5;
	cout << ar3;

	//getSize
	cout << "Size of ar5: " << ar5.getSize() << endl;

	//countElement	
	cout << "Count of 5 in ar3: " << ar3.countElement(5) << endl;

	//setElement
	ar4.setElement(9, 4);
	ar4.setElement(5, 12);

	cout << "After setting element, ar4:  " << ar4;

	//getSubArray
	cout << "SubArray of ar5 : " << ar5.getSubArray(4, 7) << endl;
	cout << "SubArray of ar4 : " << ar4.getSubArray(4, 12) << endl;

	//arithmetic binary operator
	cout << "ar3 + ar4: " << ar3 + ar4 << endl;

	//comparison operator
	if (ar3 == ar5)
		cout << "ar3 and ar5 are equal" << endl;
	else
		cout << "ar3 and ar5 are not equal" << endl;

	if (ar3 == ar4)
		cout << "ar3 and ar4 are equal" << endl;
	else
		cout << "ar3 and ar4 are not equal" << endl;

	//subscript operator
	ar5[4] = 55;
	cout << "ar5[4]: " << ar5[4] << endl;

	cout << "ar3[9]: " << ar3[9] << endl;

	ar4[13] = 55;
	cout << "ar4[13]: " << ar4[13] << endl;

	cout << "ar4[12]" << ar4[12] << endl;


	


	return 0;
}