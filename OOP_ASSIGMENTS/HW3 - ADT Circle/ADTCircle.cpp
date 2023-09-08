// Write a Circle class with following functionalities.
// 1. The class should have following four private data members.
// 1. An integer named x that holds the x-axis of a circle.
// 2. An integer named y that holds the y-axis of a circle.
// 3. A float named radius that holds the radius of a circle.
// 4. A static constant double named PI that holds the pi’s value i.e., 3.141593.
// Value should only be assigned to data members x and y when it is greater than or equal –50 and lesser than or equal to 50, 0
// otherwise and to radius when it is greater than or equal 1 and lesser than or equal to 10, 5 otherwise.
// 2. Provide the implementation of accessors and mutators for all the data members of class.
// 3. Provide the implementation of following constructors and a destructor.
// 1. A constructor that accepts Circle’s x, y coordinates and radius as arguments and assigns them to the appropriate member
// variables.
// 2. A constructor that accepts Circle’s x, y coordinates as arguments and assigns them to the appropriate member variables.
// The radius field should be assigned the default value.
// 3. A constructor that accepts Circle’s x coordinates and radius as arguments and assigns them to the appropriate member
// variables. The y coordinates should be assigned the default value.
// 4. A default constructor that initializes all the data members of the class with default values.
// 5. A copy constructor to initialize a circle’s object with already existing object.
// 6. A destructor that does nothing except displaying a simple message “Destructor executed...” on the screen.
// 4. Provide the implementation of following member functions.
// 1. setCircle method accepts Circle’s x, y coordinates and radius as arguments and assigns them to the appropriate member
// variables.
// 2. getCircle method to initialize the data of a circle taken from the user.
// 3. putCircle method to display the information of a particular circle.
// 4. getArea method calculate and return the area of a circle that is PI ∗ radius2
// 5. getDiameter method calculate and return the diameter of a circle that is radius ∗ 2
// 6. getCircumference method calculate and return the circumference of a circle that is 2 ∗ PI ∗ radius
// 7. addCircle method should accept two circle objects and return their sum.
// 8. isEqual method should accept two circle object and return true if they are having same state, false otherwise.
// 9. findCircle method should accept an array of Circle objects and return the index of the array, which is equal to left hand
// side object, –1 otherwise.
// 10. updateObjects method should accept an array of Circle objects with its size and update the radius of all those objects to
// the radius of left-hand side object exist in the array having same x, y coordinates as of left-hand side object.
// 5. Test the functionality of Circle class by creating few objects of it in main function.


#include<iostream>

using namespace std;

class Circle
{
	int x, y;
	float radius;
	static const double Pi;

public:

	//Mutators

	void setX(int x)
	{
		if (x >= -50 && x <= 50)
		{
			this->x = x;
		}
		else
		{
			this->x = 0;
		}
	}

	void setY(int y)
	{
		if (y >= -50 && y <= 50)
		{
			this->y = y;
		}
		else
		{
			this->y = 0;
		}
	}

	void setRadius(float r)
	{
		if (r >= 1 && r <= 10)
		{
			this->radius = r;
		}
		else
		{
			this->radius = 5;
		}
	}

	//Accessors

	int getX() const
	{
		return this->x;
	}

	int getY() const
	{
		return this->y;
	}

	float getRadius() const
	{
		return this->radius;
	}

	//Constructor

	Circle(int x, int y, float radius)
	{
		
		cout << "Parameterized Constructor" << endl;
		setX(x);
		setY(y);
		setRadius(radius);

	}

	Circle(int x, int y)
	{

		cout << "Parameterized Constructor." << endl;
		setX(x);
		setY(y);
		this->radius = 5;

	}

	Circle(int x, float radius)
	{

		cout << "Parameterized Constructor.." << endl;
		setX(x);
		setRadius(radius);
		this->y = 0;

	}

	Circle()
	{

		cout << "Default Constructor" << endl;
		this->x = 0;
		this->y = 0;
		this->radius = 5;

	}

	Circle(const Circle& obj)
	{

		cout << "Copy Constructor" << endl;
		this->x = obj.x;
		this->y = obj.y;
		this->radius = obj.radius;

	}

	//Destructor

	~Circle()
	{
		cout << "Destructor executed..." << endl;
	}

	//Member Functions

	void setCircle(int x, int y, float radius)
	{
		setX(x);
		setY(y);
		setRadius(radius);
	}

	void getCircle()
	{
		cout << "Enter value of x-axis of circle: ";
		cin >> x;
		setX(x);

		cout << "Enter value of y-axis of circle: ";
		cin >> y;
		setY(y);

		cout << "Enter radius of circle: ";
		cin >> radius;
		setRadius(radius);
	}

	void putCircle()const
	{
		cout << "x: " << x << "\t" << "y: " << y << "\t" << "radius: " << radius << endl;
	}

	float getArea()const
	{
		return Pi * radius * radius;
	}

	float getDiameter()const
	{
		return radius * 2;
	}

	float getCircumference()const
	{
		return 2 * Pi * radius;
	}

	Circle addCircle(const Circle& obj)const
	{
		return Circle(x + obj.x, y + obj.y, radius + obj.radius);
	}

	bool isEqual(const Circle& obj)const
	{
		if (this->x == obj.x && this->y == obj.y && this->radius == obj.radius)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

    int findCircle(const Circle arr[], const int size)const
	{
		for (int i = 0; i < size; i++)
		{
			if (this->x == arr[i].x && this->y == arr[i].y && this->radius == arr[i].radius)
			{
				return i;
			}				
		}
		return -1;
	 }

	void updateObjects(Circle arr[], const int size)
	{
		for (int i = 0; i < size; i++)
		{
			if (this->x == arr[i].x && this->y == arr[i].y)
			{
				arr[i].radius = this->radius;	
			}
		}
	}
};

const double Circle :: Pi = 3.141593;

int main()
{

	Circle o1(1, 2, 8.5f), o2(1, 3), o3(9, 1.5f), o4;

    o1.putCircle();
	o4.putCircle();

	o2.setRadius(7.8f);
	o2.putCircle();

	cout << "For o3 y: " << o3.getY() << endl;
	
	cout << "Area of o1 is: " << o1.getArea() << endl;
	cout << "Circumference of o2 is: " << o2.getCircumference() << endl;
	cout << "Diameter of o3 is: " << o3.getDiameter() << endl;


	cout << "ADDING O1 AND O2: " << endl;
	Circle temp = o1.addCircle(o3);
	temp.putCircle();

	cout << o1.isEqual(o4) << endl;

	cout << endl << endl;

	
	return 0;

}