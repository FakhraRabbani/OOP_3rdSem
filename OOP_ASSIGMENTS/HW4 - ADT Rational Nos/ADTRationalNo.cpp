// Write a class for rational numbers. A rational number is “ratio-nal” number, composed of two integers with division indicated. The
// division is not carried out; it is only indicated, as in 1/2, 2/3, 15/32, 65/4, 16/5.
// You should represent rational numbers by two values.
// 1. An integer named numerator displayed above a line or before a slash.
// 2. An integer named denominator displayed below or after that line.
// Value should only be assigned to denominator if it is non-zero, 1 otherwise.
// 1. Provide the implementation of mutators for numerator and denominator data members of the class.
// 2. Provide the implementation of accessors for numerator and denominator data members of the class.
// A principle of abstract data type construction is that constructors must be present to create objects with legal values. You should
// provide constructors to make objects out of pairs of integer value.
// 1. A constructor that accepts Rational Number’s numerator and denominator as arguments and assigns them to the
// appropriate member variables.
// 2. Since every integer is also a rational number, 2/1 or 17/1, you should provide a constructor with single integer parameter
// that accept only the value of numerator as argument and assign it to the appropriate member variable.
// 3. Overload the following operators.
// 1. Stream-insertion operator (<<) to write rational numbers in the form 2/3 or 37/51 on the screen.
// 2. Stream-extraction operator (>>) to input rational numbers in the form 2/3 or 37/51 from the keyboard.
// 3. Plus (+) binary operator to perform the addition of two rational numbers.
// 4. Minus (–) binary operator to perform the subtraction of two rational numbers and returns the result.
// 5. Multiply (*) binary operator to perform the multiplication of two rational numbers and returns the result.
// 6. Divide (/) binary operator to perform the division of two rational numbers and returns the result.
// 7. Less-than (<) binary operator to perform the comparison of two rational numbers and returns the result.
// 8. Equal (==) binary operator to perform the comparison of two rational numbers and returns the result.
// 9. Minus (–) unary operator to convert a rational number into its negative form, if it is already not and returns the result.
// 10. Logical not (!) unary operator to return true if the rational number is negative, false otherwise.
// The formulas will be useful in defining functions:

// Let any sign be carried by the numerator; keep the denominator positive.


#include<iostream>

using namespace std;

class RationalNumber
{
	int numerator;
	int denominator;

public:

	//Mutators

	void setNumerator(int n)
	{
		numerator = n;
	}

	void setDenominator(int d)
	{
		if (d > 0)
			denominator = d;
		else if (d == 0)
			denominator = 1;
		else
		{
			denominator = d * -1;
			numerator = -1 * numerator;
		}
		 
	}

	//Accessors

	int getNumerator() const
	{
		return numerator;
	}

	int getDenominator() const
	{
		return denominator;
	}

	//Constructors

	RationalNumber(int n, int d)
	{
		cout << "Parameterized Constructor" << endl;

		setNumerator(n);
		setDenominator(d);

	}

	RationalNumber(int n)
	{
		cout << "Parameterized Constructor" << endl;

		setNumerator(n);
		denominator = 1;

	}

	//Overloading Operators

	friend ostream& operator << (ostream & print, const RationalNumber & r);

	friend istream& operator >> (istream& input, RationalNumber& r);

	RationalNumber operator+(const RationalNumber& r) const
	{
		return RationalNumber((this->numerator * r.denominator + this->denominator * r.numerator),(this->denominator * r.denominator));
	}

	RationalNumber operator-(const RationalNumber& r) const
	{
		return RationalNumber((this->numerator * r.denominator - this->denominator * r.numerator), (this->denominator * r.denominator));
	}

	RationalNumber operator*(const RationalNumber& r) const
	{
		return RationalNumber((this->numerator * r.numerator), (this->denominator * r.denominator));
	}

	RationalNumber operator/(const RationalNumber& r) const
	{
		return RationalNumber((this->numerator * r.denominator), (this->denominator * r.numerator));
	}

	bool operator<(const RationalNumber& r) const
	{
		return ((this->numerator * r.denominator) < (r.numerator * this->denominator));
	}

	bool operator==(const RationalNumber& r) const
	{
		return ((this->numerator * r.denominator) == (r.numerator * this->denominator));
	}

	RationalNumber operator-()
	{
		if(numerator > 0)
		return RationalNumber(-numerator, denominator);
	}

	bool operator!()
	{
		return (numerator < 0);
	}
};

ostream& operator << (ostream & print, const RationalNumber & r)
{
	print << r.numerator << "/" << r.denominator << endl;
	return print;
}

istream& operator >> (istream& input, RationalNumber& r)
{
	int n, d;
	char c;

	cout << "Enter rational no in form of p/q: "; 
	input >> n >> c >> d;  

	r.setNumerator(n);
	r.setDenominator(d);

	return input;
}


int main()
{

	RationalNumber r1(4), r2(4, 5), r3(4, 0), r4(-5, 4), r5(4, -9);

	cin >> r1;
	cout << r1;

	cout << r5 << endl;

	RationalNumber sum = r1 + r2;
	cout << "r1 + r2: " << sum;

	RationalNumber sub = r2 - r3;
	cout << "r2 - r3: " << sub;

	RationalNumber multi = r2 * r3;
	cout << "r2 * r3: " << multi;

	RationalNumber div = r2 / r3;
	cout << "r2 / r3: " << div;


	if (r2 < r3)
		cout << "r2 is less than r3" << endl;
	else
		cout << "r2 is not less than r3" << endl;

	
	if (r1 == r2)
		cout << "r1 is equal to r2" << endl;
	else
		cout << "r1 is not equal to r2" << endl;



	cout << -r4;
	cout << -r3;


	if (!r4)
		cout << "Rational number r4 is negative" << endl;
	else
		cout << "Rational number r4 is not negative" << endl;
	
	cout << "!r3: " << !r3 << endl;  //It will return 1 if r3 is negative, otherwise it will return 0

	
	return 0;
}