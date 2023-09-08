// Create a class IntegerSet for which each object can hold integers in the range 0 through Size − 1. A set is represented internally
// as an array of ones and zeros.
// ➢ Array element a[ i ] is 1 if integer i is in the set. ➢ Array element a[ i ] is 0 if integer i is not in the set.
// For Example, the following set contains values 0, 1, 3, 4, 7 and 9.
// 0 1 2 3 4 5 6 7 8 9
// 1 1 0 1 1 0 0 1 0 1
// The class should have the following two private data members.
// 1. An integer pointer that holds a reference of an array created dynamically according to the specified size.
// 2. A constant integer to hold the maximum size of the array.
// Provide the implementation of following constructors and a destructor.
// 1. A constructor who accepts an integer that represents the size of a set and initializes it to the so-called "empty set," i.e., a
// set whose array representation contains all zeroes.
// 2. A copy constructor initializes a set object with an already existing object.
// 3. A destructor to free any memory resources occupied by the set object.
// Overload following operators.
// 1. Stream insertion (<<) prints a set as a list of numbers separated by spaces. Print only those elements that are present in
// the set (i.e., their position in the array has a value of 1). Print - - - for an empty set.
// 2. Assignment (=) which copies the data of one object to another and avoids self-assignment. The copy should only be made
// if both the objects are the same sizes.
// 3. Equal (==) that determines whether two sets are equal or not. The operator should return true if both the sets are equal,
// false otherwise.
// 4. Logical NOT (!) create and return a new set which contains the reverse of left-hand-side object, i.e., all the 1s exist in the
// set converted to 0s and vice versa.
// Provide the following non-static member functions for the common set operations.
// 1. insertElement that inserts a new integer k (passed as argument) into a set by setting a[ k ] to 1 if possible, else displays an
// error message.
// 2. deleteElement that deletes an integer k (passed as argument) by setting a[ k ] to 0 if possible, and displays an error message
// otherwise.
// 3. unionOfSets that creates a third set that is the set-theoretic union of two existing sets (i.e., an element of the third set's
// array is set to 1 if that element is 1 in either or both existing sets, and an element of the third set's array is set to 0 if that
// element is 0 in each of the existing sets).
// 4. intersectionOfSets which creates a third set which is the set-theoretic intersection of two existing sets (i.e., an element
// of the third set's array is set to 0 if that element is 0 in either or both existing sets, and an element of the third set's array
// is set to 1 if that element is 1 in each of the existing sets).
// 5. findElement that searches an integer key (passed as argument) in a set and return true if the key exists in the set, false
// otherwise.


#include<iostream>

using namespace std;

class IntegerSet
{
	int* p;
	const int size;

public:

	//Constructors

	IntegerSet(int s) : size(s)
	{
		cout << "Parameterized Constructor" << endl;

		p = new int[size];

		for (int i = 0; i < size; i++)
			p[i] = 0;
	}

	IntegerSet(const IntegerSet& obj) : size(obj.size)
	{
		cout << "Copy Constructor" << endl;

		p = new int[size];
		
		for (int i = 0; i < size; i++)
			p[i] = obj.p[i];
	}

	//Destructor

	~IntegerSet()
	{
		cout << "Destructor" << endl;
		
		delete[] p;
	}

	//Operator - Overloading

	friend ostream& operator<< (ostream& print, const IntegerSet& obj);

	//Assigment Operator

	IntegerSet operator=(const IntegerSet& obj)
	{
		if (this != &obj)
		{
			if (size == obj.size)
			{
				for (int i = 0; i < size; i++)
					p[i] = obj.p[i];
			}
		}

		return *this;
	}

	//Equal Operator

	bool operator == (const IntegerSet& obj)const
	{
		if (size != obj.size)
		{
			return false;
		}
		else
		{
			for (int i = 0; i < size; i++)
			{
				if (p[i] != obj.p[i])
					return false;
			}
			return true;
		}
	}

	//Logical Not Operator

	IntegerSet operator!()
	{
		IntegerSet obj(size);

		for (int i = 0; i < size; i++)
		{
			if (p[i] == 1)
				obj.p[i] = 0;
			else
				obj.p[i] = 1;
		}
		
		return obj;
	}

	//Member Functions

	//Insert Element

	void insertElement(int k)
	{	

		if (k >= 0 && k < size)
			p[k] = 1;
		else
			cout << "Error" << endl;
			
	}

	//Delete Element

	void deleteElement(int k)
	{		

		if (k >= 0 && k < size)
			p[k] = 0;
		else
			cout << "Error" << endl;
			
	}

	//Union Of Sets

	IntegerSet unionOfSets(const IntegerSet& obj)
	{

		IntegerSet u_obj(size);
		
		for (int i = 0; i < size; i++)
		{
			if (p[i] == 0 && obj.p[i] == 0)
				u_obj.p[i] = 0;
			else
				u_obj.p[i] = 1;

		}

		return u_obj;

	}

	//Intersection Of Sets

	IntegerSet intersectionOfSets(const IntegerSet& obj)
	{
		IntegerSet i_obj(size);

		for (int i = 0; i < size; i++)
		{
			if (p[i] == 1 && obj.p[i] == 1)
				i_obj.p[i] = 1;
			else
				i_obj.p[i] = 0;

		}
		
		return i_obj;
	
	}

	bool findElement(int key)
	{
		if (key < 0 || key >= size)
		{
			cout << "Error" << endl;
			return false;							
		}		
		else
		{
			return  (p[key] == 1);				
		}
	}
};

	
ostream& operator<< (ostream& print, const IntegerSet& obj)
{
	print << "\n";

	bool empty = true;

	print << "{";

	for (int i = 0; i < obj.size; i++)
	{
		if (obj.p[i] == 1)
		{
			print << i << " ";
			empty = false;
		}
			
	}

	if (empty)
	{
		print << "---";
	}
	print << "}";

	return print;

}

int main()
{
	IntegerSet s1(5), s2(5), s3(6);

	//insertElement

	s1.insertElement(0);
	s1.insertElement(1);
	s1.insertElement(2);
	s1.insertElement(3);
	s1.insertElement(4);

	s2.insertElement(0);
	s2.insertElement(2);
	s2.insertElement(6);

	s3.insertElement(1);
	s3.insertElement(2);
	s3.insertElement(3);
	s3.insertElement(4);

	IntegerSet s4(s2);

	//Assigment operator

	IntegerSet s5(6);
	s5 = s3;

	cout << "Integer Set s5: " << s5 << endl;

	IntegerSet s6(3);
	s6 = s1;

	cout << "Integer Set s6: " << s6 << endl;

	cout << "Integer Set 1: " << s1 << endl;
	cout << "Integer Set 2: " << s2 << endl;
	cout << "Integer Set 3: " << s3 << endl;
	cout << "Integer Set 4: " << s4 << endl;

	//Equal operator

	if (s1 == s2)
		cout << "s1 and s2 are equal" << endl;
	else
		cout << "s1 and s2 are not equal" << endl;

	if (s2 == s4)
		cout << "s2 and s4 are equal" << endl;
	else
		cout << "s2 and s4 are not equal" << endl;

	//Logical Not operator

	cout << "!s2: " << !s2 << endl;

	//Delete Element
	s5.deleteElement(2);
	cout << "After deleting element, s5: " << s5 << endl;

	IntegerSet s7(5);
	IntegerSet s8(s1);

	s7.insertElement(0);
	s7.insertElement(1);
	s7.insertElement(4);

	cout << "s7: " << s7 << endl;
	cout << "s8: " << s8 << endl;

	//Union of Sets

	cout << "Union of s1 and s2: " << s1.unionOfSets(s2) << endl;
	cout << "Union of s2 and s7: " << s2.unionOfSets(s7) << endl;

	//Intersection of Sets

	cout << "Intersection of s1 and s2: " << s1.intersectionOfSets(s2) << endl;
	cout << "Intersection of s2 and s7: " << s2.intersectionOfSets(s7) << endl;
	cout << "Intersection of s1 and s8: " << s1.intersectionOfSets(s8) << endl;
	
	//find element

	if (s1.findElement(2))
	{
		cout << "Key exists in s1 at index 2" << endl;
	}
	else
	{
		cout << "Key does not exist in s1 at index 2" << endl;
	}
	
	if (s1.findElement(10))
	{
		cout << "Key exists in s1 at index 10" << endl;
	}
	else
	{
		cout << "Key does not exist in s1 at index 10" << endl;
	}

	if (s2.findElement(3))
	{
		cout << "Key exists in s2 at index 3" << endl;
	}
	else
	{
		cout << "Key does not exist in s2 at index 3" << endl;
	}
	


	return 0;
}