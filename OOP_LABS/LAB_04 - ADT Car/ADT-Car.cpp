// Write a class named Car that has the following:
// 1. The class should have following three private data members
// 1. An integer named yearModel that holds the car’s year model.
// 2. A string named make that holds the make of the car.
// 3. An integer named speed that holds the car’s current speed.
// 2. Provide the implementation of following constructors and a destructor
// 1. The constructor should accept the car’s year model and make as arguments. These values should be assigned to the 
// object’s yearModel and make member variables. The constructor should also assign 0 to the speed member variables.
// 2. A copy constructor to initialize a car’s object with already existing object.
// 3. A destructor that does nothing except displaying a simple message “Destructor executed…” on the screen.
// 3. Provide the implementation of appropriate accessor functions to get the values stored in an object’s yearModel, make, and 
// speed member variables.
// 4. Provide the implementation of appropriate mutator functions to set the values of object’s yearModel, make, and speed
// member variables.
// 5. Provide the implementation of following member functions
// 1. setCar method accepts car’s year model, make and speed as arguments and assigns them to the appropriate member 
// variables.
// 2. getCar method to initialize the data of a car taken from the user.
// 3. putCar method to display the information of a particular car.
// 4. accelerate should add 5 to the speed member variable each time it is called.
// 5. brake should subtract 5 from the speed member variable each time it is called.
// 6. Test the functionality of Car class by creating its five objects to hold the following data in main function,
// Year Model Make Speed
// 2021 Suzuki Alto 40
// 2015 Toyota Camry 45
// 2011 Honda Accord 80
// 2012 Toyota Prius 60
// 2018 Daihatsu Boon 55
// The program should store this data in the five objects and then display the data for each car on the screen in the appropriate format.

#include "iostream"
#include "string"
using namespace std;

class Car
{
private:
	int yearModel;
	string make;
	int speed;
public:
	
	// Constructors
	

		//Perameterized
	Car(int y, string m, int s)
	{
		set_yearModel(y);
		set_make(m);
		set_speed(s);
	}

		// copy Constructor
	Car(const Car& obj)
	{
		this->yearModel = obj.yearModel;
		this->make = obj.make;
		this->speed = obj.speed;
	}

	// Destructors

	~Car()
	{
		cout << "Destructor Exexuted" << endl;
	}


	// Setters
	
	void set_yearModel(int yearModel)
	{
		this->yearModel = yearModel;
	}
	
	void set_make(string make)
	{
		this->make = make;
	}
	
	void set_speed(int speed)
	{
		this->speed = speed;
	}

	// Getters

	int get_yearModel()
	{
		return this->yearModel;
	}

	string get_make()
	{
		return this->make;
	}

	int get_speed()
	{
		return this->speed;
	}

	// Other Member Functions

	void setCar(int yearModel, string make, int speed)
	{
		set_yearModel(yearModel);
		set_make(make);
		set_speed(speed);
	}
	
	void getCar()
	{
		int m, s;
		string str;
		cout << "Enter model of Car : ";
		cin >> m;
		cout << "Enter speed of Car : ";
		cin >> s;
		cout << "Enter make of car(string) : ";
		getline(cin, str);
		set_yearModel(m);
		set_speed(s);
		set_make(str);
	}

	void putCar()
	{
		cout << "Car Year Model : " << get_yearModel() << "\tSpeed : " << get_speed() << "\tCar Make : " << get_make() << endl;
	}
	
	void accelerate()
	{
		set_speed(get_speed() + 5);
	}

	void brake()
	{
		set_speed(get_speed() - 5);
	}

};

int main()
{
	Car car1(2021, "Suzuki Alto", 40);
	Car car2(2015, "Toyota Camry", 45);
	Car car3(2011, "Honda Accord", 80), car4(2012, "Toyota Prius", 60);
	Car car5(2018, "Daihatsu Boon", 55);
	
	// car1.set_speed(52);

	car1.putCar();
	car2.putCar();
	car3.putCar();
	car4.putCar();
	car5.putCar();



	return 0;
}