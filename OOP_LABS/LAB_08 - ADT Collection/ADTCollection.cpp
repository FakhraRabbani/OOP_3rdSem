// Write a class named Collection that can hold a group of negative integers and zero as the default value.
// 1. This class should have two private data members:
// a. An integer pointer called data that holds an array of integers allocated dynamically based on the specified size.
// b. An integer called size represents the number of elements in the array.
// 2. Implement the following constructors and a destructor for the Collection class:
// a. A constructor that accepts an integer argument to represent the size of the array and initializes it as an empty collection,
// meaning all elements in the array are set to zero.
// b. An additional constructor that receives an array of integers and its size as arguments and uses the array to initialize a
// collection object.
// c. A copy constructor that initializes a collection object with an existing object.
// d. A destructor that frees any memory resources occupied by the collection object.
// 3. Implement the following non-static member functions and operators for the Collection class:
// • getSize(): Returns the size of the collection.
// • setElement(int i, int k): Inserts a new integer k at index i in the collection, if possible. Otherwise, give an appropriate error
// message.
// • countElement(int key): Accepts an integer key as an argument and returns the total occurrences of it in the collection.

// • Assignment operator (=): Copies the data of the right-hand-side object to the left-hand-side object. If the size of the left-
// hand-side object is different from the right-hand-side object, reallocate the memory for the left-hand-side object based on

// the size of the right-hand-side object and then copy the data. Don't forget to update the size of the left-hand-side object.
// • getSubCollection(int start_index, int end_index): This member function takes two integer parameters start_index and
// end_index as arguments and returns a new Collection that contains all the values in the left-hand-side object from
// start_index to end_index, both inclusive. If the requested sub-collection cannot be created, it displays an appropriate error
// message and returns a Collection object consisting of NULL with its size set to 0.
// • Stream insertion operator (<<): Allows the user to input data for the collection.
// • Stream extraction operator (>>): Displays the contents of the collection on the screen.
// • Addition operator (+): Performs the addition of two collections (left-hand-side and right-hand-side) and returns the result.
// If the two collections have different sizes, it displays an appropriate error message and returns a Collection object consisting
// of NULL with its size set to 0. Otherwise, the function adds the corresponding elements of both collections and stores the
// result in a new Collection object, which it returns.
// • Subscript ([]) for non-const objects. If the index is out of bounds, it displays an appropriate error message and returns 99,
// Without exiting the program.
// • Subscript ([]) for const objects. If the index is out of bounds, it displays an appropriate error message and returns 99,
// Without exiting the program.
// • Unary minus operator (−): Returns true if all the elements of the collection are negative or zero, false otherwise.
// 4. Once you have written the class, write the main function and test its functionality by creating some objects of Collection.


#include<iostream>

using namespace std;

class Collection
{

	int* data;
	int size;

public:

	//CONSTRUCTORS

	Collection(int size)
	{
		cout << "Parameterized Constructor" << endl;

		this->size = size;

		data = new int[size];

		for (int i = 0; i < size; i++)
			data[i] = 0;
	}

	Collection(int *d, int size)
	{
		cout << "Parameterized Constructor..." << endl;

		this->size = size;

		data = new int[size];

		for (int i = 0; i < size; i++)
		{
			data[i] = d[i];
		}
	}

	Collection(const Collection& d)
	{
		cout << "Copy Constructor" << endl;

		size = d.size;

		data = new int[size];

		for (int i = 0; i < size; i++)
			data[i] = d.data[i];
	}

	//DESTRUCTOR

	~Collection()
	{
		cout << "Destructor" << endl;

		delete[] data;
	}

	//MEMBER FUNCTIONS AND OPERATORS

	int getSize() const
	{
		return this->size;
	}

	void setElement(int i, int k)
	{
		if (i >= 0 && i < size)
			data[i] = k;
		else
			cout << "Index is out of bounds" << endl;
		
	}

	int countElement(int key) 
	{
		int count = 0;

		for (int i = 0; i < size; i++)
		{
			if (data[i] == key)
				count++;
		}

		return count;
	}

	Collection operator=(const Collection& d)
	{
		if (this != &d)
		{
			if (size != d.size)
			{
				delete[] data;
				size = d.size;
				data = new int[size];
			}

				for (int i = 0; i < size; i++)
					data[i] = d.data[i];	
		}

		return *this;
	}

	Collection getSubCollection(int start_index, int end_index)
	{
		if (start_index >= 0 && start_index <= end_index && end_index < size)
		{
			int s;
			s = (end_index - start_index) + 1;

			Collection sub_data(s);

			for (int i = 0; i < s; i++)
			{
				sub_data.data[i] = data[i + start_index];
			}

			return sub_data;
		}
		else
		{
			cout << "Sub-Collection can't be created" << endl;
			return Collection(0);
		}

	}

	friend istream& operator >> (istream& input, Collection& obj);
	friend ostream& operator << (ostream& print, const Collection& obj);

	Collection operator+(const Collection& obj) const
	{		
		if (size == obj.size)
		{
			Collection res(size);

			for (int i = 0; i < size; i++)
			{
				res.data[i] = data[i] + obj.data[i];
			}
			return res;
		}
		else
		{
			cout << "Sizes are not same, Error" << endl;
			return Collection(0);
		}
	}

	int operator[](int index) const
	{
		if (index >= 0 && index < size)
		{
			return data[index];
		}
		else
		{
			cout << "Index is out of bounds" << endl;
			return 99;
		}
	}

	int& operator[](int index) 
	{
		if (index >= 0 && index < size)
		{
			return data[index];
		}
		else
		{
			cout << "Index is out of bounds.." << endl;
			static int temp = 99;
			return temp;
		}
	}

	bool operator-()
	{
		for (int i = 0; i < size; i++)
		{
			if (data[i] > 0)
				return false;
		}
		return true;
	}
};

istream& operator >> (istream& input, Collection& obj)
{
	cout << "Enter array elements: " << endl;
	for (int i = 0; i < obj.size; i++)
	{
		cout << "Enter element of index " << i << endl;
		input >> obj.data[i];
	}
	return input;
}

ostream& operator << (ostream& print, const Collection& obj)
{
	print << "Data: " << endl;
	for (int i = 0; i < obj.size; i++)
	{
		print<< obj.data[i] << ", ";
	}
	return print;
}

int main()
{

	int arr[3] = { 1, 2, 3 };

	Collection d1(5), d2(4), d3(5), d4(d2), d(arr, 3);

	cout << "d: " << d << endl;

	//getSize
	cout << "Size of d1: " << d1.getSize() << endl;

	cout << "d4: " << d4 << endl;

	cout << "For d1: " << endl;
	cin >> d1;
	cout << "d1: " << d1 << endl;

	//Sub-Collection
	cout << d1.getSubCollection(1, 3) << endl;
	
	//Set Element
	d1.setElement(3, 10);
	cout << "After setting, d1: " << d1 << endl;

	cout << "For d3: " << endl;
	cin >> d3;
	cout << "d3: " << d3 << endl;

	//Count element
	cout << d3.countElement(1) << endl;

	cout << "d2: " << d2 << endl;

	//Subscript operator
	cout << "d1[5]: " << d1[5] << endl;
	cout << "d1[2]: " << d1[2] << endl;

	d4[2] = 5;
	cout << "d4: " << d4 << endl;

	//Addition operator
	cout << "d1 + d3: " <<  d1 + d3 << endl;

	//Unary minus operator
	cout << "-d1: " << - d1 << endl;
	cout << "-d2: " << - d2 << endl;
	cout << "-d3: " << - d3 << endl;

	//Assigment operator
	d1 = d2;
	cout << "After assigning d2 to d1, d1: " << d1 << endl;
	cout << "d2: " << d2 << endl;

	
	
	
	
	return 0;
}