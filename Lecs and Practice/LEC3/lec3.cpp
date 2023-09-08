
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

	Algebra operator+(const Algebra& obj) const
	{
		return Algebra(a + obj.a, b + obj.b);
	}

	Algebra operator-(const Algebra& obj) const
	{
		return Algebra(a - obj.a, b - obj.b);
	}

	Algebra operator*(const Algebra& obj) const
	{
		return Algebra(a * obj.a, b * obj.b);
	}

	Algebra operator/(const Algebra& obj) const
	{
		return Algebra(a / obj.a, b / obj.b);
	}

	Algebra operator%(const Algebra& obj) const
	{
		return Algebra(a % obj.a, b % obj.b);
	}

	// ***************************ASSIGMENT ARITHMETIC OPERATOR*****************************// a+=b;


	Algebra operator+=(const Algebra& obj)
	{
		this->a = this->a + obj.a;
		this->b = this->b + obj.b;
		return *this;
	}

	Algebra operator-=(const Algebra& obj)
	{
		this->a = this->a - obj.a;
		this->b = this->b - obj.b;
		return *this;
	}

	Algebra operator*=(const Algebra& obj)
	{
		this->a = this->a * obj.a;
		this->b = this->b * obj.b;
		return *this;
	}

	Algebra operator/=(const Algebra& obj)
	{
		this->a = this->a / obj.a;
		this->b = this->b / obj.b;
		return *this;
	}

	Algebra operator%=(const Algebra& obj)
	{
		this->a = this->a % obj.a;
		this->b = this->b % obj.b;
		return *this;
	}

	//******

	Algebra operator+(const int value) const
	{
		return Algebra(a + value, b + value);
	}

	Algebra operator-(const int value) const
	{
		return Algebra(a - value, b - value);
	}

	Algebra operator*(const int value) const
	{
		return Algebra(a * value, b * value);
	}

	Algebra operator/(const int value) const
	{
		return Algebra(a / value, b / value);
	}

	Algebra operator%(const int value) const
	{
		return Algebra(a % value, b % value);
	}




	//******Comaprison operators

	bool operator==(const Algebra& obj) const
	{
		return(a == obj.a && b == obj.b);
	}
	
	bool operator!=(const Algebra& obj) const
	{
		return!(a == obj.a && b == obj.b);
		//return!(*this == obj);
	}

	//************UNARY OPERATOR****

	Algebra operator-()  //Negate
	{
		return Algebra(-a, -b);
	}

	Algebra operator+()
	{
		Algebra temp;
		if (a < 0)
			temp.a = a * -1;
		if (b < 0)
			temp.b = b * -1;
		return temp;
	
	}

	Algebra operator!()
	{
		return Algebra(a * -1, b * -1);  //State Change
	}

};

int main()
{

	Algebra o1(5, 6), o2(1, 5), o3(1, 1), i(5,6) , k(-4,5);


	//Unary Operator
	Algebra s = -o1;
	s.print();
	o1.print();

	Algebra p = +s;
	p.print();

	Algebra f = !k;
	f.print();



	//Comparison operator

	if (o1 != i)
		cout << "Diff State" << endl;
	else
		cout << "Same state" << endl;

	if (o1 == i)
		cout << "Same State" << endl;
	else
		cout << "Diff state" << endl;
	
	//Arithmetic Assigment operator


	//o1 += o2;	//o1 = o1 + o2;   	//o1.operator+=(o2);
	//o1.print();
	//o2.print();

	o1 *= o2 *= o3;
	o1.print();
	o2.print();
	o3.print();

	o1 += o2 += o3;
	o1.print();
	o2.print();
	o3.print();


	//Adding value to object

	Algebra r;
	r = i + 2;
	r.print();

	Algebra d;
	d = i * 4;
	d.print();

	return 0;
}