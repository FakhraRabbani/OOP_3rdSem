
 //******PRE-POST INCREMENT

/*

#include<iostream>

using namespace std;

class Algebra
{
	int a, b;
public:

	Algebra()
	{
		cout << "Default Constructor" << endl;
		this->a = 0;
		this->b = 0;

	}

	Algebra(int a, int b)
	{
		cout << "Parameterized Constructor" << endl;
		this->a = a;
		this->b = b;
	}

	Algebra(const Algebra& obj)
	{
		cout << "Copy constructor" << endl;

		this->a = obj.a;
		this->b = obj.b;

	}

	~Algebra()
	{
		cout << "Destructor" << endl;
	}


	void print() const
	{
		cout << "a: " << a << "\tb: " << b << endl;
	}

	//*********PRE-INCREMENT**********

	Algebra operator++()
	{
		++a;
		++b;
		return *this;
	}

	//*********POST-INCREMENT**********

	Algebra operator++(int)
	{
		Algebra oldState(*this);
		a++;
		b++;
		return oldState;
	}

	
	
};

int main()
{

	Algebra o1(5, 6), o2(1, 5), o3(1, 1);
	
	o2 = ++o1;
	o2.print();
	o1.print();

	o2 = o3++;
	o2.print();
	o3.print();

	return 0;
}
*/



















//********Friend Function********
/*
#include<iostream>

using namespace std;

class Algebra
{
	int a, b;
public:

	Algebra()
	{
		cout << "Default Constructor" << endl;
		this->a = 0;
		this->b = 0;

	}

	Algebra(int a, int b)
	{
		cout << "Parameterized Constructor" << endl;
		this->a = a;
		this->b = b;
	}

	Algebra(const Algebra& obj)
	{
		cout << "Copy constructor" << endl;

		this->a = obj.a;
		this->b = obj.b;

	}

	~Algebra()
	{
		cout << "Destructor" << endl;
	}


	void print() const
	{
		cout << "a: " << a << "\tb: " << b << endl;
	}

	
	friend void hello();

	friend Algebra operator+(const int val, const Algebra& obj);

};

//5+obj 

Algebra operator+(const int val, const Algebra& obj)
{
	Algebra temp(val + obj.a, val + obj.b);
	return temp;
}

void hello()
{
	Algebra hello(1, 2);
	cout << hello.a << endl;
}
int main()
{

	Algebra o1(5, 6), o2(1, 5), o3(1, 1);

	Algebra s = 9 + o1;
	s.print();

	hello();

	return 0;
}
*/



























//*************Stream Insertion - Stream Extraction Operator********


#include<iostream>

using namespace std;

class Algebra
{
	int a, b;
public:

	Algebra()
	{
		cout << "Default Constructor" << endl;
		this->a = 0;
		this->b = 0;

	}

	Algebra(int a, int b)
	{
		cout << "Parameterized Constructor" << endl;
		this->a = a;
		this->b = b;
	}

	Algebra(const Algebra& obj)
	{
		cout << "Copy constructor" << endl;

		this->a = obj.a;
		this->b = obj.b;

	}

	~Algebra()
	{
		cout << "Destructor" << endl;
	}


	void print() const
	{
		cout << "a: " << a << "\tb: " << b << endl;
	}



	friend ostream& operator<<(ostream& print, const Algebra& obj);
	friend istream& operator>>(istream& input, Algebra& obj);
};

ostream& operator<<(ostream& print, const Algebra& obj)
{
	print << "a: " << obj.a << "\tb: " << obj.b << endl;
	return print;
}

istream& operator>>(istream &input,Algebra& obj)
{
	cout << "Enter a: ";
	input >> obj.a;

	cout << "Enter b: ";
	input >> obj.b;

	return input;

}
int main()
{

	Algebra o1(5, 6), o2(1, 5), o3(1, 1);

	cout << o1 << o2 << o3 << endl; 

	cin >> o1;
	cout << o1;

	return 0;
}