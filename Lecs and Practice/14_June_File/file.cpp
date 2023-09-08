
#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	/*
	
	ofstream outf;
	outf.open("test.txt");

	if (!outf)
	{
		cerr << "FILE CREATION FAILED";
		exit(0);
	}

	int id = 0;
	float cgpa = 0.0f;

	cout << "Enter id and cgpa: ";

	while (cin >> id >> cgpa)
	{
		cout << "Enter id and cgpa: ";

		outf << "ID: " << id << " " << "CGPA: " << cgpa << endl;

	}

	outf.close();

	*/
	
	ifstream inf("test.txt");

	if (!inf)
	{
		cerr << "FILE Opening FAILED";
		exit(0);
	}

	int id1 = 0;
	float cgpa1 = 0.0f;

	/*
	while(inf >> id1 >> cgpa1)
	{
		cout << "ID: " << id1 << " " << "CGPA: " << cgpa1 << endl;
	}*/

	inf >> id1 >> cgpa1;

	while (!inf.eof())
	{
		cout << "ID: " << id1 << " " << "CGPA: " << cgpa1 << endl;

		inf >> id1 >> cgpa1;	

	}

	inf.close();

	
	return 0;
}