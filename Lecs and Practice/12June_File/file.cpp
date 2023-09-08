
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main()
{

	//Creation of file through constructor
	/*

	ofstream obj("test.txt");

	if (!obj)
	{
		cerr << "File creation failed" << endl;
		exit(0);
	}

	cout << "OK" << endl;

	obj.close();

	*/

    
	//Creation of file through open function


	/*
	ofstream obj;
	obj.open("open.txt");

	if (!obj)
	{
		cerr << "File creation failed" << endl;
		exit(0);
	}

	cout << "OK" << endl;

	obj.close();

	*/




	/*
	ofstream obj;
	obj.open("C:\\Users\AL REHMAN COM\source\repos\12June_FILE\\path.txt");

	if (!obj)
	{
		cerr << "File creation failed" << endl;
		exit(0);
	}

	cout << "OK" << endl;

	obj.close();

	*/


	return 0;
}