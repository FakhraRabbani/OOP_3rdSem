#include<iostream>
#include<string>
using namespace std;

class Employee
{
private:

	string name;
	int id;
	string department;
	string position;

public:

	Employee(string Name, int ID, string Department, string Position)
	{

		name = Name;
		id = ID;
		department = Department;
		position = Position;

		cout << "Parameterized Constructor." << endl;
	}

	Employee(string Name, int ID)
	{

		name = Name;
		id = ID;
		department = "";
		position = "";

		cout << "Parameterized" << endl;
	}

	Employee()
	{

		name = "";
		id = 0;
		department = "";
		position = "";

		cout << "Default Constructor" << endl;

	}

	Employee(const Employee& obj)
	{

		name = obj.name;
		id = obj.id;
		department = obj.department;
		position = obj.position;

		cout << "Copy Constructor" << endl;

	}

	~Employee()
	{

		cout << "Destructor executed." << endl;

	}

	void setName(string Name)
	{
		name = Name;
	}

	string getName()
	{
		return name;
	}


	void setID(int ID)
	{
		if (ID > 0)
			id = ID;
		else
			id = 0;
	}

	int getID()
	{
		return id;
	}

	void setDept(string Dept)
	{
		department = Dept;
	}

	string getDept()
	{
		return department;
	}

	void setPosition(string Position)
	{
		position = Position;
	}

	string getPosition()
	{
		return position;
	}

	void setinfo(string Name, int ID, string Department, string Position)
	{

		setName(Name);
		setID(ID);
		setDept(Department);
		setPosition(Position);

	}

	void getinfo()
	{
		cout << "Plz enter employee name: ";
		getline(cin, name);
		//cin >> name;
		setName(name);

		cout << "Plz enter employee id: ";
		cin >> id;
		setID(id);
		cin.ignore();

		cout << "Plz enter the name of department where employee works: ";
		getline(cin, department);
		//cin >> department;
		setDept(department);

		cout << "Plz enter employee position(employee's job title): ";
		getline(cin, position);
		//cin >> position;
		setPosition(position);
		
	}

	void putinfo()
	{
		cout << name << "\t\t\t" << id << "\t\t\t" << department << "\t\t" << position << endl;
	}
};
int main()
{

	Employee obj1, obj2;
	//Creating Objects through default constructor

	Employee obj3("Fakhra Rabbani", 2004, "Information Technology", "Assistant Professor");
	Employee obj4("Meerab Khan", 2002);
	//Creating objects through parameterized constructor

	Employee obj5(obj3);
	//Creating Object through copy constructor

	obj1.getinfo();
    obj2.getinfo();

	//obj3.getinfo();

	obj4.setDept("Computer Science");
	obj4.setPosition("Lecturer");

	//obj5.getinfo();

	cout << "Name" << "\t\t\t\t" << "Id Number" << "\t\t" << "Department" << "\t\t\t" << "Position" << endl;

	obj1.putinfo();
	obj2.putinfo();
	obj3.putinfo();
	obj4.putinfo();
	obj5.putinfo();

	return 0;

}