/*
#include"iostream"
#include<string>
using namespace std;

int add(int a, int b, int c)
{
	return a + b + c;
}
int add(int a, int b)
{
	return a + b;
}
float add(float a, float b)
{
	return a + b;
}

int main()
{

	//cout << 'A' << endl;
	//cout << 456 << endl;
	//cout << 4.56 << endl;
	//cout << 4.56f << endl;
	
	//int i, c, f;err
	//cin >> i >> c >> f;
	//cout << i << "\t" << c << "\t" << f << endl;


	/*
	int in;
	char ch;
	float fl;
	cin >> in >> ch >> fl;
	cout << in << "\t" << ch << "\t" << fl << endl;
	*/


	/*
	int arr[5];
	//cin >> arr; //syntax error
	for (int i = 0; i < 5; i++)
	{
		cin >> arr[i];
	}
	cout << arr; //logical error
	*/



	/*
	char ch[5];
	for (int i = 0; i < 4; i++)
	{
		cin >> ch[i];
	}
	ch[4] = NULL;
	//cin >> ch;
	cout << ch;
	*/
	/*
	char ch[5];
	cin >> ch;
	cout << ch;
	*/
	
	/*
	string str = "";
	//cin >> str;
	getline(cin, str);
	cout << str << endl;
	*/

	/*
	int id = -1;
	string str;
	getline(cin, str);
	cin >> id;	
	cout << id << "\t" << str << endl;
	*/
	
	/*
	int id = -1;
	string str;
	cin >> id;
	cin.ignore();
	getline(cin, str);
	cout << id << "\t" << str << endl;
	*/

	/*
	int a, b, c;
	string str;
	cin >> a >> b >> c;
	cin.ignore(3);
	getline(cin, str);
	cout << a << "\t" << b << "\t" << c << "\t" << str << endl;
	*/

	/*
	string name;
	cout << name.length() << endl;
	cout << name.size() << endl;
	cout << sizeof(name) << endl;
	
	getline(cin, name);
	cout << name.length() << endl;
	cout << name.size() << endl;
	cout << sizeof(name) << endl;

	getline(cin, name);
	cout << name.length() << endl;
	cout << name.size() << endl;
	cout << sizeof(name) << endl;
	*/


	//FUNCTION OVERLOADING
    
   int s3 = add(1, 2, 3);
   float f2 = add(5.5, 6);
   int i2 = add(1, 2);

   cout << s3 << "\t" << f2 << "\t" << i2 << endl;
	return 0;
}
*/