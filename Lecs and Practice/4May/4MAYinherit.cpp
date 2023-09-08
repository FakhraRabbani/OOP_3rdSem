

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

	void print()
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
	B ob(5,4);

	A oa;
	C oc;

	//Assigment
	oa = ob;
	oa = oc;
	ob = oc;

	*/

	//A oa;
	//B ob(4, 5);

	//B ob1 = ob;

	//oa.printA();
	//ob.printA(); //ob.A::printA();
	//ob.printB();

	
	B ob(4, 5);

	//ob.printB();

	ob.print(); //Jis classs ka object uss ka print call

	C oc;
	oc.print();

	A oaa(4);
	oaa.print();

	return 0;
}