


#include<iostream>

using namespace std;

class A
{
	int da;

public:

	A()
	{
		da = 0;
		cout << "A DEF CONST" << endl;
	}

	A(int da)
	{

		this->da = da;
		cout << "A PARA CONST" << endl;
	}

	A(const A& obj)
	{
		this->da = obj.da;
		cout << "A Copy Constructor" << endl;
	}

	/*
	void printA()
	{
		cout << "da: " << da << endl;
	}
	*/

	virtual void print()
	{
		cout << "da: " << da << endl;
	}

	~A()
	{
		cout << "A Destructor" << endl;
	}
};

class B : public A
{
	int db;

public:

	B()
	{
		db = 0;
		cout << "B DEF CONST" << endl;
	}

	B(int da, int db) : A(da)
	{
		//this->da = da; ERROR->private

		this->db = db;
		cout << "B PARA CONST" << endl;
	}

	B(const B& obj) : A(obj)
	{
		//this->da = obj.da;   ERROR->Inaccessible

		this->db = obj.db;
		cout << "B Copy Constructor" << endl;
	}

	/*
	void printB()
	{
		//cout << "da: " << da << endl;  ERROR(INACCESSIBLE)

		printA();  //this->A::printA();

		cout << "db: " << db << endl;
	}
	*/

	void print()
	{
		//cout << "da: " << da << endl;  ERROR(INACCESSIBLE)

		//print();   //Loop // Infinite recursion

		this->A::print();

		cout << "db: " << db << endl;
	}

	~B()
	{
		cout << "B Destructor" << endl;
	}
};


class C : public B
{
	int dc;

public:

	C()
	{
		dc = 0;
		cout << "C DEF CONST" << endl;
	}

	/*
	void printC()
	{
		cout << "dc: " << dc << endl;
	}
	*/

	void print()
	{
		this->B::print();

		cout << "dc: " << dc << endl;
	}

	~C()
	{
		cout << "C Destructor" << endl;
	}
};


int main()
{
	/*
	A oa;
	B ob(4, 5);

	oa = ob;

	oa.print();
	*/

	/*
	B ob(4, 5);

	A* pa; //Not an object until memory assign

	pa = &ob; //No constructor call bc pointer

	pa->print();  //Static bind(Apni class ka print call(a ka), B ka ni
	//Kis ka print call->run time
	*/


	//After Making Virtual Funct   ->decision(object type)

	/*
	B ob(4, 5);

	A* pa; 

	pa = &ob;

	pa->print();  //B ka print call

	*/



	A oa(1);
	B ob(4, 3);
	C oc;


	A *pa[3] = {&oa, &ob, &oc}; //Array of pointers

	for (int i = 0; i < 3; i++)
	{
		pa[i]->print();
	}


	













	return 0;
}