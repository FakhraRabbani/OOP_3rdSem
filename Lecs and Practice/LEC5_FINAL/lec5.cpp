#include<iostream>

using namespace std;

class Integer
{
	int* number;

public:

	Integer()
	{
		cout << "Default Constructor" << endl;
		number = new int(0);
	}

	Integer(int number)
	{
		cout << "Parameterized Constructor" << endl;
		this -> number = new int(number);
	}

	~Integer()
	{
		cout << "Destructor" << endl;
		delete number;
	}

	void print() const
	{
		cout << "Number: " << *(this->number) << endl;
	}

	void input()
	{
		cout << "Enter Number: ";
		cin >> *(this->number);
	}

	int getNumber() const
	{
		return *number;
	}

	void setNumber(int number)
	{
		*(this->number) = number;
	}

	Integer(const Integer& obj)
	{
		cout << "Copy Constructor" << endl;
		this->number = new int;
		*this->number = *(obj.number);

		//this->number = new int(*(obj.number));
	}

	Integer operator=(const Integer& obj)
	{
		if (this != &obj)
		{
			*this->number = *(obj.number);
		}
		return *this;
	}
};

int main()
{

	Integer o1;
	Integer o2(5);
	Integer o3(o2);

	o1.input();

	o1.print();
	o2.print();
	o3.print();

	Integer o4;
	o4 = o2;
	o4.print();

	return 0;
}