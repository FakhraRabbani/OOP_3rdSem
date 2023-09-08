

//COMPOSITION

/*

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

	CPU(const CPU& obj)
	{
		cout << "CPU Copy Constructor" << endl;

		this->cpuid = obj.cpuid;
		this->cpuSpeed = obj.cpuSpeed;
	}

	~CPU()
	{
		cout << "CPU Destructor" << endl;
	}

	void print()
	{
		cout << "CPU ID: " << cpuid << endl;
		cout << "CPU speed: " << cpuSpeed << endl;

	}
};

class Computer
{
	int compid;
	int price;
	CPU comCPU;

public:

	Computer() : comCPU()
	{
		cout << "Computer Default Constructor" << endl;
		this->compid = -1;
		this->price = -1;

		//comCPU = CPU(); Logically maybe not correct
	}

	Computer(int compid, int price) : comCPU()
	{
		cout << "Computer Parameterized Constructor" << endl;
		this->compid = compid;
		this->price = price;

		//comCPU.cpuid = cpuid;   //ERROR 
	}

	Computer(int compid, int price, int cpuID, float cpuS ) : comCPU(cpuID, cpuS)
	{
		cout << "Computer Parameterized Constructor" << endl;
		this->compid = compid;
		this->price = price;

	}

	Computer(const Computer& obj) : comCPU(obj.comCPU)
	{
		cout << "Computer Copy Constructor" << endl;

		this->compid = obj.compid;
		this->price = obj.price;
	}

	~Computer()
	{
		cout << "Computer Destructor" << endl;
	}

	void print()
	{
		cout << "Computer ID: " << compid << endl;
		cout << "Computer price: " << price << endl;

		comCPU.print();
	}

};

int main()
{
	Computer c1, c2(12, 2.5), c3(13, 14, 45, 5.2f), c4(c2);

	c3.print();

	return 0;
}

*/










//Aggregation

#include<iostream>

using namespace std;

class Teacher
{
	int tid;
	string tname;

public:

	Teacher(int tid, string tname)
	{		
		this->tid = tid;
		this->tname = tname;

		cout << "Teacher Para Const" << endl;
	}

	void Tinfo()
	{
		cout << "T ID: " << tid << endl;
		cout << "T Name : " << tname << endl;
	}
};

class Dept
{
	int did;
	string dname;
	Teacher* faculty;

public:

	Dept(int did, string dname, Teacher* t)
	{
		this->did = did;
		this->dname = dname;

		faculty = t;

		cout << "Dept Para Const" << endl;
	}

	void Depinfo()
	{
		cout << "D ID: " << did << endl;
		cout << "D Name : " << dname << endl;

		if (faculty != NULL)
			faculty->Tinfo();
	}
};

int main()
{
	Teacher t(123, "Hassan Khan");
	Dept d(9, "DCS", &t);

	d.Depinfo();


	Dept d1(9, "DCS", NULL);



	return 0;
}