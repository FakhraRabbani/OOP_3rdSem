// Implement following function named letterPerWord that accepts C-string str as its argument. The function should count the 
// number of characters of each word appearing in the string and display a table containing the word followed by its length on the 
// screen. Display an appropriate message, if str is empty.
// void letterPerWord(const char* str);
// For instance, if the string argument is “All is well.” the function should display.
// Word Number of Characters
// All 3
// is 2
// well 4
// In main function, ask the user to input a string (maximum 50 characters) and then pass it to letterPerWord function.

#include<iostream>
#include<string>
using namespace std;

void letterPerWord(const char* str)
{
	if (str == NULL)
	{
		cout << "Empty String";
	}

	int count = 0;

	cout << "Word" << "\t" << "Number of Characters" << endl;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ')
		{
			count++;
			cout << str[i] ;
		}
		else if (str[i] == ' ')
		{
			cout << "\t" << count << endl;
			count = 0;
		}
	}
	
	cout << "\t" << count  << endl;
}
int main()
{
	string str;
	cout << "Enter a string: ";
	getline(cin, str);
	letterPerWord(&str[0]);

	return 0;
}
