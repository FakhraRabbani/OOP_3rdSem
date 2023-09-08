// Implement following function named reverseCase that accepts a C-string str as an argument and return a newly created string
// which contains the reverse case of str. It should test each character to determine whether it is upper or lowercase. If a character is 
// uppercase, it should be converted to lowercase. Likewise, if a character is lowercase, it should be converted to uppercase. No harm 
// should be done to any other characters. It should return NULL in case of empty string (str contains no characters). The function
// should not display anything.
// char* reverseCase(const char* str);
// For instance, the string argument 
// “Hello, four Score And Seven years Ago” will be converted to “hELLO, FOUR sCORE aND sEVEN YEARS aGO”
// “Bsf21mXyZ, pU. LahoRE” will be converted to “bSF21MxYz, Pu. lAHOre”
// Demonstrate the working of reverseCase function in main and display the modified string on the screen. Display an appropriate 
// message if the returned string is empty. Don’t forget to free the memory resource allocated by the program, if any

#include<iostream>
#include<string>
using namespace std;

char* reverseCase(const char* str)
{
	char* rev = new char[50];

	if(str == NULL)
	{
		cout << "String is empty";
	}

	int i = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			rev[i] = str[i] - 32;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			rev[i] = str[i] + 32;
		}
		else
		{
			rev[i] = str[i];
		}
	}

	rev[i] = '\0';
	
	return rev;
}
int main()
{

	string str;
	cout << "Enter a string: ";
	getline(cin, str);

	char *p = reverseCase(&str[0]);

	cout << p;

	delete p;

	return 0;
}