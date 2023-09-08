 
#include<iostream>

using namespace std;

template<typename t>
class Algebra
{
	t a, b;

public:

	Algebra()
	{
		cout << "Default Constructor" << endl;
		a = b = 0;
	}

	Algebra(t a, t b)
	{
		cout << "Parameterized Constructor" << endl;
		
		this->a = a;
		this->b = b;
	}

	void print()
	{
		cout << a << "\t" << b << endl;
	}

	void input();

	friend istream& operator>>(istream& in, Algebra& obj)
	{
		cin >> obj.a >> obj.b;
		return in;
	}

	friend ostream& operator<<(ostream& out, const Algebra& obj);

};

template<typename t>
ostream& operator<<(ostream& out, const Algebra<t>& obj)
{
	out << obj.a << " " << obj.b;
	return out;
}

template<typename t>
void Algebra<t>::input()
{
	cout << "Enter a : ";
	cin >> a;

	cout << "Enter b : ";
	cin >> b;
}

int main()
{
	Algebra<int>o1;
	Algebra<float>o2;
	Algebra<char>o3;

	Algebra<float>obj(1.1f, 1.2f);

	Algebra<char>objc;
	objc.input();
	objc.print();

	cin >> obj;

	return 0;
}