

//Public Data Members(Access identifiers)
//Size, address
//Accessing public data members and initializing them
/*
#include<iostream>

using namespace std;

class Algebra
{
	//Access Identifier is public
public:
	//data members of class
	int a;
	int b;
};
int main()
{
	Algebra obj1, obj2;

	//SIZE
	cout << "Size of obj1: " << sizeof(obj1) << endl; //8
	cout << "Size of obj2: " << sizeof(obj2) << endl; //8
	cout << "Size of Algebra class: " << sizeof(Algebra) << endl; //8

	cout << endl << endl;

	//ADDRESS
	cout << "Address of obj1: " << &obj1 << endl << "Address of a of obj1: " << &(obj1.a) << endl ; //Address of object is same as address of first member
	cout << "Address of b of obj1: " << &(obj1.b) << endl;     //Members of object are being accessed by main because they are defined public here (Access idenifier is public here)

	cout << endl;

	cout << "Address of obj2: " << &obj2 << endl << "Address of a of obj2: " << &(obj2.a) << endl;
	cout << "Address of b of obj2: " << &(obj2.b) << endl;

	//cout << "Address of Algebra class: " << &Algebra << endl; //ERROR Because algebra is a class, having no physical existance(not in memory)

	cout << endl << endl;




	//ASSIGNING VALUES

	obj1.a = 45;
	obj1.b = 55;
	obj2.a = 98;
	obj2.b = 99;

	cout << "obj1.a: " << obj1.a << "\t" << "obj1.b: " << obj1.b << endl;   //45    55
	cout << "obj2.a: " << obj2.a << "\t" << "obj2.b: " << obj2.b << endl;   //98    99 
	//
	return 0;
}
*/























//Private data members (ACCESS INDENTIFIERS)
//Member Functions
//Initializing objects, accesing objects, performing operations(addition, division)

/*
#include<iostream>

using namespace std;

class Algebra
{
	//Access Identifier is private (by default)
	//data members of class
	int a;
	int b;

public: //interface for member functions
	
	void print()
	{
		cout << "a: " << a << "\t" << "b: " << b << endl;  
	}

	void input()
	{
		cout << "Enter value of member a: ";
		cin >> a;

		cout << "Enter value of member b: ";
		cin >> b;
	}

	void setData(int a1, int b1)
	{
		a = a1;
		b = b1;
	}

	int add()
	{
		return a + b;
	}

	int div()
	{
		return a / b;
	}

	float div1()
	{
		return float(a)/ b;  //explicit typecasting  (converted to float)
	}

	
	//float div()
	//{
	//	return float(a / b);  //Not right as integer to integer division will return integer
	//}
	

	
};
int main()
{
	Algebra obj1, obj2;

	//cout << obj1.a; //Error because data members are private and can only be accessed by class member functions
	//print(); //error qk class ka function sirf class ke objects ke reference se call hoskta


	//Initializing object1 by taking input from user
	cout << "Input For Object1: " << endl;
	obj1.input();
	cout << endl;

	//Initializing object2 by setting data
	cout << "Setting Data For Object2: " << endl;
	obj2.setData(4, 5);

	cout << endl << endl;

	//Printing Data
	cout << "Print For Object1: " << endl;
    obj1.print();
	cout << "Print For Object2: " << endl;
	obj2.print();


	cout << endl << endl;


	//Adding data
	cout << "a + b of object1: " << obj1.add() << endl;
	//Or
	int s = obj2.add();
	cout << "a + b of object2: " << s << endl;

	cout << endl << endl;


	//Dividing data by int div()
	cout << "Division by function int div()" << endl;

	cout << "a / b of object1: " << obj1.div() << endl;
	//Or
	int d = obj2.div();
	cout << "a / b of object2: " << d << endl;

	cout << endl;



	//Dividing data by float div1()
	cout << "Division by function float div1() (explicit typecasting)" << endl;
	cout << "a / b of object1: " << obj1.div1() << endl;
	//Or
	float d1 = obj2.div1();
	cout << "a / b of object2: " << d1 << endl;
	return 0;
}

*/


























//Constructors
//Default Constructors
//Parameterized / Overload Constructors
//Copy Constructor
//Assigment Operator
//Destructor

/*
#include<iostream>

using namespace std;

class Algebra
{
	int a, b;  //private data members

public:

	void print()
	{
		cout << "a: " << a << "\t" << "b: " << b << endl;
	}

	Algebra()
	{
		a = 0;
		b = 0;
		cout << "Default Constructor" << endl;
	}

	Algebra(int a1, int b1)
	{
		a = a1;
		b = b1;
		cout << "Parameterized Constructor" << endl;
	}

	Algebra(const Algebra& obj)  //By Value se error ayega
	{
		a = obj.a;
		b = obj.b;
		cout << "Copy Constructor" << endl;
	}

	~Algebra()
	{
		cout << "Destructor" << endl;
	}
};
int main()
{
	Algebra obj1;  //Initialized by default constructor
	Algebra obj2(5, 9);  //Initialized by parameterized constructor
	Algebra obj3 = obj2;   //Copy constructor
	//Algebra obj3;
	//obj3 = obj2;  //Assigment (not copy constructor) default constructor chala


	//Printing Data
	cout << "Print For Object1: " << endl;
	obj1.print();    //0  0
	cout << "Print For Object2: " << endl;
	obj2.print();    //5  9
	cout << "Print For Object3: " << endl;
	obj3.print();    //5  9

	return 0;
}
*/




































//Setters
//Getters / Accessors
//Check in setters for only positive values -> code less and no negative values check again again

/*
#include<iostream>

using namespace std;

class Algebra
{
	int a, b;  //private data members

public:

	void print()
	{
		cout << "a: " << a << "\t" << "b: " << b << endl;
	}

	void setA(int a1)  //Setter for data member a
	{
		if (a1 > 0) //check
			a = a1;
		else
			a = 0;
	}

	void setB(int b1)  //Setter for data member b
	{
		if (b1 > 0)
			b = b1;
		else
			b = 0;
	}

	//Getters
	int getA()  
	{
		return a;
	}

	int getB()
	{
		return b;
	}

	Algebra()
	{
		a = 0;
		b = 0;
		cout << "Default Constructor" << endl;
	}

	Algebra(int a1, int b1)
	{
		a = a1;
		b = b1;
		cout << "Parameterized Constructor" << endl;
	}

	Algebra(const Algebra& obj)  //By Value se error ayega
	{
		a = obj.a;
		b = obj.b;
		cout << "Copy Constructor" << endl;
	}

	~Algebra()
	{
		cout << "Destructor" << endl;
	}
};
int main()
{
	Algebra obj1, obj2(5, 9);
	
	cout << "Before setting members of object 1: " << endl;
	cout << "Print For Object1: " << endl;
	obj1.print();    //0  0

	cout << endl;

	//Setting data members of object1
	obj1.setA(4);
	obj1.setB(3);

	cout << "After setting members of object 1: " << endl;aa																							
	cout << "Print For Object1: " << endl;
	obj1.print();    //0  0

	cout << endl;


	//Getters

	cout << "Member A of object 1: " << obj1.getA() << endl;
	cout << "Member B of object 1: " << obj1.getB() << endl;
	cout << "Member A of object 2: " << obj2.getA() << endl;
	cout << "Member B of object 2: " << obj2.getB() << endl;

	return 0;
}
*/



















//9FEB LEC


/*
#include<iostream>

using namespace std;

class Algebra
{
public:

	int a, b;

public:


	Algebra()
	{
		a = 0;
		b = 0;
		cout << "Default Constructor" << endl;
	}

	Algebra(int a1, int b1)
	{
		a = a1;
		b = b1;
		cout << "Parameterized Constructor" << endl;
	}


};
void test(Algebra r)
{

}
int main()
{
	Algebra obj2(5, 9);
	test(obj2);


	return 0;
}
*/

















//ADDITION, SUBTRACTION, DIVISION, MULTIPLICATION OF 2 OBJECTS
//COMPARISON OF 2 OBJECTS(STATES EQUAL OR NOT)

/*
#include<iostream>

using namespace std;

class Algebra
{
private:

	int a, b;  

public:

	void print()
	{
		cout << "a: " << a << "\t" << "b: " << b << endl;
	}

	void setA(int a1)  //Setter for data member a
	{
		if (a1 > 0) //check
			a = a1;
		else
			a = 0;
	}

	void setB(int b1)  //Setter for data member b
	{
		if (b1 > 0)
			b = b1;
		else
			b = 0;
	}

	//Getters
	int getA()
	{
		return a;
	}

	int getB()
	{
		return b;
	}

	Algebra()
	{
		a = 0;
		b = 0;
		cout << "Default Constructor" << endl;
	}


	Algebra(const Algebra& obj)  //By Value se error ayega
	{
		a = obj.a;
		b = obj.b;
		cout << "Copy Constructor" << endl;
	}

	Algebra(int a1, int b1)
	{
		a = a1;
		b = b1;
		cout << "Parameterized Constructor" << endl;
	}
	
	~Algebra()
	{
		cout << "Destructor" << endl;
	}

	int add()
	{
		return a + b;
	}

	Algebra ADD(const Algebra& obj)
	{
		Algebra temp;
		
		temp.a = a + obj.a;
		temp.b = b + obj.b;

		return temp;
	}

	Algebra sub(const Algebra& obj)
	{
		Algebra temp(a - obj.a, b - obj.b);
		return temp;
	}

	Algebra Multi(const Algebra& obj)
	{
		return Algebra(a * obj.a, b * obj.b);
	}

	Algebra Div(const Algebra& obj)
	{
		return Algebra(a / obj.a, b / obj.b);
	}

	bool isEqual(const Algebra& obj)
	{
		return(a == obj.a, b == obj.b);
	}
};
int main()
{
	Algebra obj1(5, 9);
	Algebra obj2(obj1);

	int s;
	s = obj1.add();
	cout << s << endl;


	
	cout << "Addition of objects" << endl;

	Algebra ad;
	ad = obj1.ADD(obj2);
	ad.print();
	


	cout << "Subtraction" << endl;

	Algebra sub;
	sub = obj1.sub(obj2);
	sub.print();


	cout << "Multiplication" << endl;

	Algebra multi;
	multi = obj1.Multi(obj2);
	multi.print();



	cout << "Division" << endl;
	Algebra div;
	div = obj1.Div(obj2);
	div.print();

  

	cout << "Checking states" << endl;
	cout << obj1.isEqual(obj2) << endl;
	

	return 0;
}
*/










//ARRAYS
//Creating arrays
//Taking input and printing 
/*
#include<iostream>

using namespace std;

class Algebra
{
private:
	int a, b;
public:

	Algebra()
	{
		a = 0;
		b = 0;
		cout << "Default constructor" << endl;
	}

	Algebra(int a1, int b1)
	{
		a = a1;
		b = b1;
		cout << "Parameterized constructor" << endl;
	}

	~Algebra()
	{
		cout << "Destructor" << endl;
	}

	void print()
	{
		cout << "a: " << a << "\t" << "b: " << b << endl;
	}

	void input()
	{
		cout << "Enter a :" << endl;
		cin >> a;
		cout << "Enter b: " << endl;
		cin >> b;
	}
};
int main()
{

	//int ar[3];
	Algebra array[5]; //Array of 3 objects

	//array[0].print();  //Print object no zero

	//Taking input in objects
	for (int i = 0; i < 3; i++)
	{
		cout << "Enter for object no " << i << endl;
		array[i].input();
	}


	//Printing Objects
	for (int i = 0; i < 3; i++)
	{
		cout << "Object " << i << endl;
		array[i].print();
	}

	return 0;
}
*/












/*
//Initialozation of arrays at creation time

#include<iostream>

using namespace std;

class Algebra
{
private:
	int a, b;
public:

	Algebra()
	{
		a = 0;
		b = 0;
		cout << "Default constructor" << endl;
	}

	Algebra(int a1, int b1)
	{
		a = a1;
		b = b1;
		cout << "Parameterized constructor" << endl;
	}

	Algebra(const Algebra& obj)  //By Value se error ayega
	{
		a = obj.a;
		b = obj.b;
		cout << "Copy Constructor" << endl;
	}

	~Algebra()
	{
		cout << "Destructor" << endl;
	}

	void print()
	{
		cout << "a: " << a << "\t" << "b: " << b << endl;
	}

	void input()
	{
		cout << "Enter a :" << endl;
		cin >> a;
		cout << "Enter b: " << endl;
		cin >> b;
	}
};
int main()
{

	//int ar[5] = { 0,1,2,3,4 };

	//Algebra ar[3] = { Algebra(), Algebra(), Algebra() };  //By default 

	//Algebra ar[3] = { Algebra(1,2), Algebra(5,9), Algebra(6,7) };  //PArameterized

	Algebra ar[3] = { Algebra(), Algebra(7,9), Algebra(ar[1]) }; //Default, parameterized, copy

	//Printing Objects
	for (int i = 0; i < 3; i++)
	{
		cout << "Object " << i << endl;
		ar[i].print();
	}
	return 0;
}

*/















//PASSING ARRAYS TO FUNCTIONS

/*
#include<iostream>

using namespace std;

class Algebra
{
private:
	int a, b;
public:

	Algebra()
	{
		a = 0;
		b = 0;
		cout << "Default constructor" << endl;
	}

	Algebra(int a1, int b1)
	{
		a = a1;
		b = b1;
		cout << "Parameterized constructor" << endl;
	}

	Algebra(const Algebra& obj)  //By Value se error ayega
	{
		a = obj.a;
		b = obj.b;
		cout << "Copy Constructor" << endl;
	}

	~Algebra()
	{
		cout << "Destructor" << endl;
	}

	void print()
	{
		cout << "a: " << a << "\t" << "b: " << b << endl;
	}

	void input()
	{
		cout << "Enter a :" << endl;
		cin >> a;
		cout << "Enter b: " << endl;
		cin >> b;
	}

};

void printArray(Algebra r[], const int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Object " << i << endl;
		r[i].print();
	}
}
int main()
{


	Algebra ar[3] = { Algebra(), Algebra(7,9), Algebra(ar[1]) }; //Default, parameterized, copy

	//Printing Array through global function
	printArray(ar, 3);
	
	return 0;
}
*/













//Making arrays pointer
/*
#include<iostream>

using namespace std;

class Algebra
{
private:
	int a, b;
public:

	Algebra()
	{
		a = 0;
		b = 0;
		cout << "Default constructor" << endl;
	}

	Algebra(int a1, int b1)
	{
		a = a1;
		b = b1;
		cout << "Parameterized constructor" << endl;
	}

	Algebra(const Algebra& obj)  //By Value se error ayega
	{
		a = obj.a;
		b = obj.b;
		cout << "Copy Constructor" << endl;
	}

	~Algebra()
	{
		cout << "Destructor" << endl;
	}

	void print()
	{
		cout << "a: " << a << "\t" << "b: " << b << endl;
	}

	void input()
	{
		cout << "Enter a :" << endl;
		cin >> a;
		cout << "Enter b: " << endl;
		cin >> b;
	}

};
int main()
{

	Algebra obj1;

	Algebra* pa;
	pa = &obj1;

	cout << "pa: " << pa << endl;

	pa->print();	//(* pa).print();



	cout << "Array" << endl;

	Algebra ar[3] = { Algebra(), Algebra(1,2), Algebra() };

	Algebra* par;

	par = ar;

	par[0].print();
	par[1].print();
	



	return 0;
}


*/













/*

#include<iostream>
#include<string>

using namespace std;

class Faculty
{
private:
	int eCode;
	string name;
	int scale;
public:

	Faculty()
	{
		eCode = 0;
		name = "";
		scale = 0;
		cout << "Default constructor" << endl;
	}

	Faculty(int EC, string Name, int Scale)
	{
		eCode = EC;
		name = Name;
		scale = Scale;
		cout << "Parameterized constructor" << endl;
	}

	Faculty(const Faculty& obj)  //By Value se error ayega
	{
		eCode = obj.eCode;
		name = obj.name;
		scale = obj.scale;
		cout << "Copy Constructor" << endl;
	}

	~Faculty()
	{
		cout << "Destructor" << endl;
	}

	void print()
	{
		cout << "eCode: " << eCode << "\t" << "name: " << name << "\tscale: " << scale << endl;
	}

	void input()
	{
		cout << "Enter eCode :" << endl;
		cin >> eCode;

		cout << "Enter name: " << endl;
		getline(cin,name);

		cout << "Enter scale :" << endl;
		cin >> scale;
	}

	Faculty getDifferentSale(Faculty arr[], const int size)
	{

		for (int i = 0; i < size; i++)
		{
			if (this->scale != arr[i].scale)
			{
				return arr[i];
			}
		}
	}
};

int main()
{

	Faculty obj1(45, "kainat", 79);

	Faculty* pa;
	pa = &obj1;

	//pa->print();	//(* pa).print();


	Faculty ar[3] = { Faculty(100, "natalia", 79), Faculty(45, "kainat", 79), Faculty(45, "kainat", 99)};

	Faculty* par;
	par = ar;
    
	(* par).getDifferentSale(ar, 3);

	




	return 0;
}
*/














/*
#include<iostream>

using namespace std;

//int add(int* ptra, int* ptrb)
//{
	//return  *ptra + *ptrb;
//}

int add(int x, int y)
{
	return x + y;
}

int add(int x, int y,int z)
{
	return x + y + z;
}

int main()
{
	/*
	int a = 5;
	cout << "a = " << a << endl;
		cout << "Address of a = " << &a << endl;

		int* p;
		p = &a;


		cout << "p = " << p << endl;
		cout << "*p = " << *p << endl;
		cout << "&p = " << &p << endl;

		cout << "&*p = " << &*p << endl;
		cout << "*&p = " << *&p << endl;

		a = 10;

		cout << "*p: " << *p << "\ta: " << a << endl;

		*p = 4;
		cout << "*p: " << *p << "\ta: " << a << endl;
		*/



	/*
		int b = 10;
		int* ptr;
		int val = 4;

		cout << &b << endl;
		cout << &val << endl;
		cout << &ptr << endl;
		cout << endl << endl;
		ptr = &val;

		cout << &b << endl;
		cout << &val << endl;
		cout << &ptr << endl;
		cout << b << endl;
		cout << val << endl;
		cout << *ptr << endl;
		cout << endl << endl;
		ptr = &b;

		cout << &b << endl;
		cout << &val << endl;
		cout << &ptr << endl;
		cout << b << endl;
		cout << val << endl;
		cout << *ptr << endl;
		cout << endl << endl;

		*ptr = val;
		
		cout << b << endl;
		cout << val << endl;
		cout << *ptr << endl;

		b = 5;

		cout << b << endl;
		cout << val << endl;
		cout << *ptr << endl;

		*/


	
	//cout << add(&a, &b);

	//cout << add(1, 2);
	//cout << add(1, 2, 3);
	
	//return 0;
//}








/*
#include<iostream>

using namespace std;

class Algebra
{

private:

	int a, b ;
	const int c;

public:

	void setA(int a1)
	{
		if (a1 > 0)
			this ->a = a1;
		else
			this ->a = 0;
	}

	void setB(int b1)
	{
		if (b1 > 0)
			this->b = b1;
		else
			this->b = 0;
	}

	int getA()
	{
		return this->a;
	}

	int getB()
	{
		return this->b;
	}

	int getC()
	{
		return  this-> c;
	}

	Algebra():c(0)
	{
		cout << "Default constructor." << endl;
		this->a = 0;
		this -> b = 0;

	}

	Algebra(int a, int b, int c):c(c)
	{
		cout << "Parameterized Constructor" << endl;
		this->setA(a);
		this->setB(b);
	}

	Algebra(const Algebra &obj):c(obj.c)
	{
		cout << "Copy constructor." << endl;
		this->setA(obj.a);
		this->setB(obj.b);
	}

	~Algebra()
	{
		cout << "Destructor eexecuted." << endl;
	}

	void print() const
	{
		cout << this->a << "\t" << this->b << "\t" << this->c << endl;
	}

	void input()
	{
		cout << "Enter a: ";
		cin >> this->a;

		cout << "Enter b : ";
		cin >> this->b;


		this->setA(a);
		this->setB(b);
	}

	void setData(int a, int b)
	{
		this->setA(a);
		this->setB(b);

	}

	
	int add()
	{
		return this->a + this->b;
	}

	float div()
	{
		return (float)a / b;
	}

	int divi()
	{
		return this->a / this->b;
	}
	
	Algebra addO(const Algebra& obj)const
	{
		
		//Algebra temp;
		//temp.a = a + obj.a;
		//temp.b = b + obj.b;
		//return temp;

		//Algebra temp(a + obj.a, b + obj.b);
		//return temp;

		return Algebra(a + obj.a, b + obj.b,obj.c);
	}

	Algebra sub(const Algebra& obj)const
	{
		return Algebra(a - obj.a, b - obj.b, c-obj.c);
	}

	Algebra di(const Algebra& obj)
	{
		return Algebra(a / obj.a, b / obj.b, c / obj.c);
	}

	Algebra mod(const Algebra& obj)
	{
		return Algebra(a % obj.a, b % obj.b, c % obj.c);
	}

	Algebra mul(const Algebra& obj)
	{
		return Algebra(a * obj.a, b * obj.b , c * obj.c);
	}

	bool isEqual(const Algebra& obj)const
	{
		return (a == obj.a && b == obj.b, c == obj.c);
	}

	void printAr(Algebra arr[], const int size)
	{
		for (int i = 0; i < 3; i++)
		{
			arr[i].print();
		}
	}

	Algebra arrT(const Algebra arr[], const int size)
	{
		Algebra sum;
		for (int i = 0; i < size; i++)
		{
			sum.a = sum.a + arr[i].a;
		}
		return sum;
	}
	
};

void printArray(Algebra array[], const int size)
{
	for (int i = 0; i < 3; i++)
	{
		array[i].print();
	}
}
int main()
{

	Algebra o1, o2(5,9,3), o3(o2);
	
	const Algebra obj(4,7,9);
	o2.print();

	o1.print();
	o2.print();
	o3.print();

	cout << o2.getC();

	cout << o2.getA();
	*/

	/*
	Algebra* p = new Algebra[2];
	p->print();
	(* (p + 1)).print();

	for (int i = 0; i < 2; i++)
	{
		(*(p + i)).input();
	}

	for (int i = 0; i < 2; i++)
	{
		(*(p + i)).input();
	}

	delete[] p;

	*/

	//Algebra* pa = new Algebra(5,9);
	//pa->print();
	//delete pa;
	
	//Algebra* pa;
	//Algebra oa(4,5);
	//pa = &oa;

	//pa[0].print();


	//pa->print();
	//(*pa).print();

	//pa->input();
	//pa->setA(5);
	//cout << pa->getA();

	//Algebra a[3] = { Algebra(), Algebra(4,5), Algebra(a[1]) };

	//Algebra s;
	 //s= a->arrT(a, 3);
	 //s.print();

	// (* a).printAr(a, 3);

	//a->printAr(a, 3);

	//printArray(a,3);

	/*
	for (int i = 0; i < 3; i++)
	{
		a[i].print();
	}



	Algebra ar[3];

	//ar[0].input();
	//ar[0].print();

	/*
	for (int i = 0; i < 3; i++)
	{
		ar[i].input();
	}

	for (int i = 0; i < 3; i++)
	{
		ar[i].print();
	}
	*/



	/*
	Algebra o1(5, 9), o2(7, 1);
	Algebra a;
	a = o1.addO(o2);
	a.print();
	a = o1.sub(o2);
	a.print();
	a = o1.di(o2);
	a.print();
	a = o1.mod(o2);
	a.print();
	a = o1.mul(o2);
	a.print();

	cout << o1.isEqual(o2) << endl;
	*/


	/*
	Algebra obj1, obj2;
	Algebra obj3(4, 7)
	Algebra obj4 = obj3;

	Algebra obj5;
	obj5 = obj4;
	obj5.print();


	Algebra obj6;
	obj6.setA(55);

	cout << obj6.getB() << endl;

	cout << obj1.getA() << endl;
	cout << obj3.getA() << endl;

	obj1.input();
	obj2.setData(4,9);

	obj1.print();
	obj2.print();

	cout << obj1.add() << endl;
	cout << obj2.add() << endl;

	cout << obj1.div()<< endl;
	cout << obj2.divi() << endl;
	*/
	
	//return 0;

//}






















#include<iostream>

using namespace std;

class Algebra
{
	int a,b;
	const int c = 0;

	static int s ;

public:

	Algebra() :c(0)
	{
		cout << "Default constructor." << endl;
		this->a = 0;
		this->b = 0;
		s++;

	}

	Algebra(int a, int b, int c) :c(c)
	{
		cout << "Parameterized Constructor" << endl;
		this->a = a;
		this->b = b;
		s++;
	}

	~Algebra()
	{
		cout << "Destructor eexecuted." << endl;
	}

	static void setS(int s)
	{
		Algebra::s = s;
	}

	static int getS()
	{
		return Algebra::s;
	}

	static bool compare(const Algebra ar[], const Algebra ar2[], int sz, int sa)
	{

	}
};
int Algebra::s;
int main()
{
	
	//Algebra::compare();
	//Algebra o1;
	//o1.setS(99);

	//Algebra::setS(100);
	//cout << Algebra::getS() << endl;
	
	Algebra o1, o2, o3(5,6,7);



	cout << Algebra::getS() << endl;
	
	int s = Algebra::getS();


	return 0;
}




































































