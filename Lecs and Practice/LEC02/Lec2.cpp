
#include<iostream>

using namespace std;

/*
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


	void print() const
	{
		cout << "a: " << a << "\tb: " << b << endl;
	}


	//OPERATOR OVERLOADING

   Algebra operator + (const Algebra & obj) const
	{
		return Algebra(a + obj.a, b + obj.b);
	}

	Algebra operator - (const Algebra& obj) const
	{
		return Algebra(a - obj.a, b - obj.b);
	}

	Algebra operator*(const Algebra& obj) const
	{
		return Algebra(a * obj.a, b * obj.b);
	}

	Algebra operator / (const Algebra& obj) const
	{
		return Algebra(a / obj.a, b / obj.b);
	}

	Algebra operator %(const Algebra& obj) const
	{
		return Algebra(a % obj.a, b % obj.b);
	}
};

int main()
{

	Algebra o1(5, 6), o2(1, 5), o3(1, 1);
    Algebra plus, minus, multi, div, mod;

	plus = o1 + o2;	//o1.operator+(o2);	
	plus.print();

	plus = o1 + o2 + o3; // o1.operator+(o2.operator+(o3));  //CASCADING
	plus.print();


	minus = o1 - o2; //o1.operator-(o2)	
	minus.print();

	minus = o1 - o2 - o3;
	minus.print();

	
	multi = o1 * o2;	//o1.operator*(o2);	
	multi.print();

	multi = o1 * o2 * o3;	
	multi.print();


	div = o1 / o2;	//o1.operator/(o2);	
	div.print();


	div = o1 / o2 / o3;	
	div.print();


	mod = o1 % o2;	//o1.operator%(o2);	
	mod.print();

	mod = o1 % o2 % o3;	
	mod.print();


	o1 = o2;  //	o1.operator=(o2);
	o1.print();
	o2.print();


	string f1 = "fakhra";
	string f2 = "rabbani";
	cout << f1 + f2 << endl; //Concatenation
	return 0;
}

*/














//*******************ASSIGMENT OPERATOR OVERLOAD****************




#include<iostream>

using namespace std;

class Algebra
{
	int a, b;
	const int c;
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

	Algebra():c(0)
	{
		cout << "Default Constructor" << endl;
		this->a = 0;
		this->b = 0;

	}

	Algebra(int a, int b, int c) : c(c)
	{
		cout << "Parameterized Constructor" << endl;
		setA(a);
		setB(b);
	}

	Algebra(const Algebra& obj) : c(obj.c)
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
		cout << "a: " << a << "\tb: " << b << "\tc: " << c << endl;
	}

	Algebra operator=(const Algebra& obj)
	{
		if (this != &obj) //Avoid self-assigment
		{
			this->a = obj.a;
			this->b = obj.b;
		}		
		return *this;
	}
};

int main()
{

	Algebra o1(5, 6, 9), o2(1,1, 5), o3(1, 2, 1);

	o1 = o2 = o3;     //Associaitivity(right to left)	o1.operator=(o2.operator=(o3));

	//o1 = o2;
	o1.print();
	o2.print();
	o3.print();

	
	return 0;
}

//When there is constant data member-overload assigment operator and it will be nonconstant
//Avoid self - assigment (check)
//Return something for cascading