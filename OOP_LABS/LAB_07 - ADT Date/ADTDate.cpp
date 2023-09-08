// Write a class named Date having following functionalities
// 1. The class should have following three private data members.
// 1. An integer named day that holds the day number of the month.
// 2. An integer named month that holds the month number of the year.
// 3. An integer named year that holds the year number.
// Value should only be assigned to day, if it is in between 1 (default value) and 31 both inclusive.
// Value should only be assigned to month, if it is in between 1 (default value) and 12 both inclusive.
// Value should only be assigned to year, if it is in greater than or equal to 1900 (default value).
// 2. Provide the implementation of mutators for all the data members (day, month and year) of the class.
// 3. Provide the implementation of accessors for all the data members (day, month and year) of the class.
// 4. Provide the implementation of following constructors and a destructor
// 1. The constructor should accept the Date’s day, month and year as arguments. These values should be assigned to the
// object’s appropriate member variables.
// 2. The constructor should accept the Date’s month and year as arguments. These values should be assigned to the object’s
// appropriate member variables. The day data member should be assigned to the default value.
// 3. A default constructor that initializes all the data members of the class with default values.
// 5. Provide the implementation of following overloaded operators
// 1. stream insertion (<<) to display the date in the form April 05, 2023
// 2. stream extraction (>>) should prompt the user for a date to be stored in a Date object. The operator should ask the user
// to enter the date in the following format; dd/mm/yyyy.
// 3. pre-increment (++) should increment the day data member of the object
// 4. post-increment (++) should increment the day data member of the object
// 5. pre-decrement (--) should decrement the day data member of the object
// 6. post-decrement (--) should decrement the day data member of the object
// 7. subtraction (-) binary should subtract the one date from another and return the number of days between two dates. For
// example, if April 10, 2023, is subtracted from April 18, 2023, the result will be 8.
// 8. addition (+) unary should return true, if the date is a public holiday (5 Feb, 23 March, 1 May etc. etc.), false otherwise.
// 6. The class should detect the following conditions and handle them accordingly:
// 1. When a date is set to the last day of the month and incremented, it should become the first day of the following month.
// 2. When a date is set to December 31 and incremented, it should become January 1 of the following year.
// 3. When a day is set to the first day of the month and decremented, it should become the last day of the previous month.
// 4. When a date is set to January 1 and decremented, it should become December 31 of the previous year.
// 7. Once you have written the class, write main function and test its functionality by creating some objects of Date.


#include<iostream>

using namespace std;

class Date
{
	int day;
	int month;
	int year;

public:

	//Mutators

	void setDay(int d)
	{
		if (d >= 1 && d <= 31)
			this->day = d;
		else
			this->day = 1;
    }

	void setMonth(int m)
	{
		if (m >= 1 && m <= 12)
			this->month = m;
		else
			this->month = 1;
	}

	void setYear(int y)
	{
		if (y >= 1900)
			this->year = y;
		else
			this->year = 1900;
    }

	//ACCESSORS

	int getDay() const
	{
		return this->day;
	}

	int getMonth() const
	{
		return this->month;
	}

	int getYear() const
	{
		return this->year;
	}

	//Constructors

	Date(int d, int m, int y)
	{
		cout << "Parameterized Constructor";

		setDay(d);
		setMonth(m);
		setYear(y);
	}

	Date(int m, int y)
	{
		cout << "Parameterized Constructor";

		this->day = 1;
		setMonth(m);
		setYear(y);
	}

	Date()
	{
		cout << "Default Constructor" << endl;

		this->day = 1;
		this->month = 1;
		this->year = 1900;
	}

	//Overloaded Operators

	friend ostream& operator <<(ostream& print, const Date& obj);

	friend istream& operator >>(istream& input, Date& obj);

    //PRE-INCREMENT

	Date& operator++()
	{
		if (day == 31 && month == 12)
		{
			day = 1;
			month = 1;
			year++;
		}
		else if (day == 31)
		{
			day = 1;
			month++;
		}
		else
		{
			day++;
		}
		return *this;
	}

    //POST-INCREMENT

	Date operator++(int)
	{
		Date oldState = *this;
		++(*this);
		return oldState;
	}

    //PRE- DECREMENT

	Date& operator--()
	{
		if (day == 1 && month == 1)
		{
			day = 31;
			month = 12;
			year--;
		}
		else if (day == 1)
		{
			month--;
			if (month == 2)
			{
				if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
				{
					day = 29;
				}
				else
				{
					day = 28;
				}
			}
			else if (month == 4 || month == 6 || month == 9 || month == 11)
			{
				day = 30;
			}
			else
			{
				day = 31;
			}
		}
		else
		{
			day--;
		}
		return *this;
	}

	//POST -DECREMENT

	Date operator--(int)
	{
		Date temp = *this;
		--(*this);
		return temp;
	}

	//SUBTRACTION BINARY OPERATOR
	int operator-(const Date& obj)
	{
		int i = year - (obj.year);
		if (i < 0)
		{
			i = i * (-1);
		}
		int j = month - (obj.month);
		if (j < 0)
		{
			j = j * (-1);
		}
		int k = day - (obj.day);
		if (k < 0)
		{
			k = k * (-1);
		}

		return (k + (j * 30) + (i * 365));
		
	}	

	//ADDITION UNARY OPERATOR
	bool operator+()
	{
		if ((day == 5 && month == 2) || (day == 23 && month == 3) || (day == 1 && month == 5) || (day == 14 && month == 8) || (day == 9 && month == 11) || (day == 25 && month == 12) || ((day == 9 || day == 10) && month == 9))
			return true;
		else
			return false;

	}

};

ostream& operator <<(ostream& print, const Date& obj)
{
	string m[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

	int i = (obj.month) - 1;

	print << "\n" << m[i] << "" << obj.day << "," << obj.year << endl;

	return print;
}

istream& operator >>(istream& input, Date& obj)
{
	
	cout << "Enter date: ";
	input >> obj.day;
	obj.setDay(obj.day);

	cout << "Enter month: ";
	input >> obj.month;
	obj.setMonth(obj.month);

	cout << "Enter year: ";
	input >> obj.year;
	obj.setYear(obj.year);

	return input;

}

int main()
{
	Date d1(28, 2, 2022), d2, d3(3, 2004), d4(25, 11, 2004);

	cout << d1;
	cout << d2;
	cout << d3;

	cin >> d2;
	cout << d2;


	if (+d2)
		cout << "d2 is public holiday" << endl;
	else
		cout << "d2 is not a public holiday" << endl;

	cout << "Number of days: " << d1 - d2 << endl;

	cout << ++d1;
	cout << d2++;

	cout << --d3;
	cout << d4--;

	return 0;
}