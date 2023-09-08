     //  **********************LEC 01*******************************

/*
#include<iostream>

using namespace std;

int test()
{
	return 5;
}

int foo()
{
	int a = 3;
	return a;
}

class Algebra
{
	int a, b;

public:

	void setA(int a)
	{
		if (a > 0)
			this->a = a;
		else
			this->a = 0;
	}

	void setB(int b)
	{
		if (b > 0)
			this->b = b;
		else
			this->b = 0;
	}

	int getA()
	{
		return this->a;
	}

	int getB()
	{
		return this->b;
	}

	Algebra()
	{
		cout << "Default Constructor" << endl;
		this->a = 0;
		this->b = 0;

	}

	Algebra(int a, int b)
	{
		cout << "Parameterized Constructor" << endl;
		setA(a);
		setB(b);
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

	Algebra add(const Algebra& obj) const
	{
		return Algebra(a + obj.a, b + obj.b); //parameterized constructor will be called(anonymous object)
	}

	void print() const
	{
		cout << "a: " << a << "\tb: " << b << endl;
	}
};

int main()
{

	Algebra o1(5, 6), o2(1,2);
	
	Algebra a = o1.add(o2); //RVO(Return Value Optimization)
	a.print();

	//cout << test() << endl;

	//int b = foo();
	//cout << b << endl;

	return 0;
}
*/


















/*
#include<iostream>

using namespace std;


class Algebra
{
	int a, b;

public:

	Algebra();
	Algebra(int a, int b);
	~Algebra();
	void print() const;
	void input();
	int getA()const;

};

Algebra::Algebra()
{

	cout << "Default Constructor" << endl;
	a = 0;
	b = 0;
}

Algebra::Algebra(int a, int b)
{
	cout << "Parameterized Constructor" << endl;
	this->a = a;
	this->b = b;
}

Algebra::~Algebra()
{
	cout << "Destructor" << endl;
}

void Algebra::print() const
{
	cout << "a: " << a << "\tb: " << b << endl;
}

void Algebra::input()
{
	cin >> a;
}

int main()
{
	Algebra o1(1, 5);
	o1.print();
}
*/



/*

#include"Algebra.h"



int main()
{
	Algebra obj;
	obj.input();
	obj.print();

}
*/