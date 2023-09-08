// Write a class named Student that has the following:
// 1. The class should have following five private data members
// 1. An int named regNo that holds the student’s registration number. The value of registration number should fall in between 
// 501 to 565 both inclusive, 0 otherwise.
// 2. A string named firstName that holds the student’s first name.
// 3. A string named lastName that holds the student’s last name.
// 4. A string named program that holds the student’s degree program in which he/she is registered.
// 5. A float named cgpa that holds the student’s current CGPA. The value of cgpa must fall in between 0.0 and 4.00 both 
// inclusive, -1 otherwise.
// 2. Provide the implementation of mutators for all the data members (regNo, firstName, lastName, program and cgpa) of the class.
// 3. Provide the implementation of accessorsfor all the data members (regNo, firstName, lastName, program and cgpa) of the class.
// 4. Provide the implementation of following constructors and a destructor
// 1. The constructor should accept the student’s registration number, first name, last name and program as arguments. These 
// values should be assigned to the object’s appropriate member variables. The constructor should also assign -1 to the cgpa
// member variable.
// 2. The constructor should accept the student’s registration number, first name and program as arguments. These values 
// should be assigned to the object’s appropriate member variables. The constructor should also assign empty string ("") to
// last name and -1 to the cgpa member variable.
// 3. The constructor should accept the student’s registration number, first name, last name, program and cgpa as arguments. 
// These values should be assigned to the object’s appropriate member variables.
// 4. A copy constructor to initialize a student’s object with already existing object.
// 5. A destructor that do nothing except displaying a simple message “Destructor executed…” on the screen.
// 5. Provide the implementation of following member functions
// 1. set method accepts student’s registration number, first name, last name, program and cgpa as arguments and assigns 
// them to the appropriate member variables.
// 2. read method to initialize the data of a student taken from the user.
// 3. write method to display the information of a particular student.
// 4. isFirstSemester method should return true if the student is enrolled in first semester i.e., a student having CGPA -1, false
// otherwise.
// 5. getPercentage method should provide the facility to calculate and return the percentage of the students’ CGPA only if the 
// value of CGPA is greater than or equal to 0.0, otherwise return -1.
// 6. isPromoted method should return true if the students’ CGPA is greater than or equal to 2.00, false otherwise.
// 6. Once you have written the class, write main function and test its functionality by creating some objects of Student.


#include <iostream>
#include <string>
using namespace std;

class Student
{
    int regNo;
    string firstName;
    string lastName;
    string program;
    float cgpa;

public:
    int checkRegNo(int num) // for validation
    {
        if (num >= 501 && num <= 565)
            return num;
        else
            return 0;
    }

    float checkCgpa(float num) // for validation
    {
        if (num >= 0.0 && num <= 4.00)
            return num;
        else
            return -1;
    }

    Student(int regNo1, string firstName1, string lastName1, string program1, float cgpa1) // Parameterized constructor
    {
        SetregNo(regNo1);
        firstName = firstName1;
        lastName = lastName1;
        program = program1;
        Setcgpa(cgpa1);
    }

    Student(int regNo1, string firstName1, string lastName1, string program1) // Parameterized constructor with four passed parameters
    {
        SetregNo(regNo1);
        firstName = firstName1;
        lastName = lastName1;
        program = program1;
        cgpa = -1;
    }

    Student(int regNo1, string firstName1, string program1) // Parameterized constructor with three passed parameters
    {
        SetregNo(regNo1);
        firstName = firstName1;
        lastName = "";
        program = program1;
        cgpa = -1;
    }

    Student(const Student &o1) // copy constructor
    {
        regNo = o1.regNo;
        firstName = o1.firstName;
        lastName = o1.lastName;
        program = o1.program;
        cgpa = o1.cgpa;
    }

    ~Student() // destructor
    {
        cout << "Destructor executed...\n";
    }

    // PROPERTIES METHODS

    int getregNo()
    {
        return regNo;
    }
    string getfirstName() // Getters
    {
        return firstName;
    }
    string getlastName()
    {
        return lastName;
    }
    string getprogram()
    {
        return program;
    }
    float getcgpa()
    {
        return cgpa;
    }

    void SetregNo(int regNo1) // Setters
    {
        regNo = checkRegNo(regNo1);
    }
    void SetfirstName(string model1)
    {
        firstName = model1;
    }
    void SetlastName(string lastName1)
    {
        lastName = lastName1;
    }
    void Setprogram(string program1)
    {
        program = program1;
    }
    void Setcgpa(float cgpa1)
    {
        cgpa = checkCgpa(cgpa1);
    }

    // Other functions

    void set(int regNo1, string firstName1, string lastName1, string program1, float cgpa1)
    {
        SetregNo(regNo1);
        firstName = firstName1;
        lastName = lastName1;
        program = program1;
        Setcgpa(cgpa1);
    }

    void read()
    {
        cout << "Enter the Student's regNo: ";
        cin >> regNo;
        SetregNo(regNo);

        cout << "Enter the Student's firstName: ";
        cin.ignore();
        getline(cin, firstName);

        cout << "Enter the Student's lastName: ";
        // cin.ignore();
        getline(cin, lastName);

        cout << "Enter the Student's program: ";
        getline(cin, program);

        cout << "Enter the Student's cgpa: ";
        cin >> cgpa;
        Setcgpa(cgpa);
    }

    void write()
    {
        cout << regNo << "\t\t" << firstName << "\t" << lastName << "\t\t" << program << "\t" << cgpa << endl;
    }

    bool isFirstSemester()
    {
        return cgpa == -1;
    }

    float getPercentage()
    {
        if (cgpa >= 0.0)
        {
            return (cgpa / 4) * 100;
        }
        else
        {
            return -1;
        }
    }

    bool isPromoted()
    {
        return (cgpa >= 2.00);
    }
};

int main()
{
    Student first(501, "Abdullah", "Nawaz", "Computer science", 3.4); // using parameterized constructor

    Student second(501, "Tayyab", "Software Engineering"); // Using parameterized constructor with three passed parameters
    second.SetregNo(502);                                  // setting information using setters
    second.SetlastName("Ali");
    second.Setcgpa(3.9);

    Student third(502, "Abdullah", "Nawaz", "Computer science"); // Using parameterized constructor with four passed parameters
    third.set(503, "Naeem", "Ahmad", "Computer Science", 3.2);   // setting information using set function

    Student forth(first); // using copy constructor
    forth.read();         // collecting information using read function from user

    cout << endl;
    cout << "REG NUMBER\t FIRST NAME\tLAST NUMBER\t PROGRAM\t CGPA\n";
    first.write();
    second.write(); // displaying information using write function
    third.write();
    // displaying information using getters
    cout << forth.getregNo() << "\t\t" << forth.getfirstName() << "\t" << forth.getlastName() << "\t\t" << forth.getprogram() << "\t" << forth.getcgpa() << endl;
    cout << endl;

    cout << "Is the student in first semester? " << first.isFirstSemester() << endl;
    cout << "Percentage of the student is: " << first.getPercentage() << "%" << endl;
    cout << "Is the student in promoted? " << first.isPromoted() << endl;

    return 0;
}