// Cuboids are three-dimensional shapes having different measurements in each dimension say height, width, and depth. Cuboids
// shapes are often used for boxes, cupboards, rooms, buildings, etc. So, keeping in the mind the importance of Cuboids you must
// implement a class Cuboids with following functionalities.
// 1. The class should have following three private data members to which value should only be assigned to them when it is greater
// than 0 and lesser than 35.00, 1 otherwise no matter to which dimension.
// 1. A float named height that holds the cuboids’ height.
// 2. A float named width that holds the cuboids’ width.
// 3. A float named depth that holds the cuboids’ depth.
// 2. Provide the implementation of mutators for all the data members (width, height, and depth) of the class.
// 3. Provide the implementation of accessors for all the data members (width, height, and depth) of the class.
// 4. Provide the implementation of following constructors and a destructor
// 1. A constructor that accepts cuboids’ height, width and depth as arguments and assigns them to the appropriate member
// variables.
// 2. A constructor that accepts cuboids’ height and width as arguments and assigns them to the appropriate member variables.
// The depth field should be assigned the default value.
// 3. A default constructor that initializes all the data members of the class with default values.
// 4. A copy constructor to initialize a cuboids’ object with already existing object.
// 5. A destructor that does nothing except displaying a simple message “Destructor executed...” on the screen.
// 5. Provide the implementation of following member functions
// 1. setCuboids method accepts cuboids’ height, width and depth as arguments and assigns them to the appropriate member
// variables.
// 2. getCuboids method to initialize the data of a cuboids taken from the user.
// 3. putCuboids method to display the information of a particular cuboids.
// 4. getSurfaceArea method provide the facility to calculate the surface area of a cuboids that is
// 2(height ∗ width) + 2(height ∗ depth) + 2(width ∗ depth)

// 5. getVolume method provide the facility to calculate the volume of a cuboids that is height ∗ width ∗ depth
// 6. getSpaceDiagonal method provide the facility to calculate the space diagonal of a cuboids that is

// √height
// 2 + width
// 2 +depth
// 2

// 7. putCuboidsInfo method should display all the dimensions, surface area, volume, and space diagonal of a cuboids.
// 6. Test the functionality of Cuboids class by creating few objects of it in main function.


#include<iostream>
#include<cmath>
using namespace std;

class Cuboids
{

private:

	float height;
	float width;
	float depth;

public:

	//Setters

	void setHeight(float h)
	{
		if (h > 0.00 && h < 35.00)
			height = h;
		else
			height = 1;
	}

	void setWidth(float w)
	{
		if (w > 0.00 && w < 35.00)
			width = w;
		else
			width = 1;
	}

	void setDepth(float d)
	{
		if (d > 0.00 && d < 35.00)
			depth = d;
		else
			depth = 1;
	}

	//Getters

	float getHeight()
	{
		return height;
	}

	float getWidth()
	{
		return width;
	}

	float getDepth()
	{
		return depth;
	}

	//Constructors

	Cuboids(float h1, float w1, float d1)
	{
		cout << "Parameterized Constructor." << endl;

		setHeight(h1);
		setWidth(w1);
		setDepth(d1);

	}

	Cuboids(float h2, float w2)
	{
		cout << "Parameterized Constructor." << endl;

		setHeight(h2);
		setWidth(w2);
		depth = 0.0;

	}

	Cuboids()
	{
		cout << "Default Constructor." << endl;

		height = 0.0;
		width = 0.0;
		depth = 0.0;

	}

	Cuboids(const Cuboids& obj)
	{
		cout << "Copy Constructor." << endl;

		height = obj.height;
		width = obj.width;
		depth = obj.depth;

	}

	//Destructor

	~Cuboids()
	{
		cout << "Destructor executed..." << endl;
	}

	//Member Functions


	void setCuboids(float h, float w, float d)
	{
		height = h;
		width = w;
		depth = d;

	}

	void getCuboids()
	{

		cout << "Enter height of cuboids: ";
		cin >> height;
		setHeight(height);

		cout << "Enter width of cuboids: ";
		cin >> width;
		setWidth(width);

		cout << "Enter depth of cuboids: ";
		cin >> depth;
		setDepth(depth);
	}

	void putCuboids()
	{
		cout << "Height: " << getHeight() << "\tWidth: " << getWidth() << "\tDepth: " << getDepth() << endl;
	}

	float getSurfaceArea()
	{
		return( 2 * (height * width)) + (2 * (height * depth)) + (2 * (width * depth));
	}

	float getVolume()
	{
		return (height * width * depth);
	}

	float getSpaceDiagonal()
	{
		return sqrt((height * height) + (width * width) + (depth * depth));
	}

	void putCuboidsinfo()
	{
		cout << getHeight() << "\t" << getWidth() << "\t" << getDepth() << "\t" << getSurfaceArea() << "\t\t" << getVolume() << "\t " << getSpaceDiagonal() << endl;
	}
};
int main()
{

	Cuboids obj1;
	Cuboids obj2(1.2, 3.4);
	Cuboids obj3(1.5, 6.5, 4.0);
	Cuboids obj4(obj3);

	cout << "For Cuboid 1: " << endl;
	obj1.getCuboids();

	obj2.setDepth(5.4);

	//Displaying Info

	cout << "Information of cuboid1: " << endl;
	obj1.putCuboids();


	cout << "Information of cuboid2: " << endl;
	obj2.putCuboids();


	cout << "Information of cuboid3: " << endl;
	obj3.putCuboids();


	cout << "Information of cuboid4: " << endl;
	obj4.putCuboids();

	cout << "ALL INFO: " << endl;

	cout << "Height" << "\tWidth" << "\tDepth" << "\tSurfaceArea" << "\tVolume" <<  "\tSpace Diagonal" << endl;

	obj1.putCuboidsinfo();
	obj2.putCuboidsinfo();
	obj3.putCuboidsinfo();
	obj4.putCuboidsinfo();

	return 0;

}
