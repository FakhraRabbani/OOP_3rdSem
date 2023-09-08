#include<iostream>

using namespace std;

class CPU
{
	int cpuid;
	float cpuSpeed;

public:

	CPU()
	{
		cout << "CPU Default Constructor" << endl;
		this->cpuid = -1;
		this->cpuSpeed = -1;
	}

	CPU(int cpuid, float cpuSpeed)
	{
		cout << "CPU Parameterized Constructor" << endl;
		this->cpuid = cpuid;
		this->cpuSpeed = cpuSpeed;
	}

	~CPU()
	{
		cout << "CPU Destructor" << endl;
	}
};

class Computer
{
	int compid;
	int price;
	CPU comCPU;

public:

	Computer()
	{
		cout << "Computer Default Constructor" << endl;
		this->compid = -1;
		this->price = -1;
	}

	Computer(int cpuid, int price)
	{
		cout << "Computer Parameterized Constructor" << endl;
		this->compid = compid;
		this->price = price;
	}

	~Computer()
	{
		cout << "Computer Destructor" << endl;
	}
};

int main()
{
	Computer c1, c2(12, 2.5);

	return 0;
}