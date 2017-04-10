// OpenCV0201.cpp : Defines the entry point for the console application.
//
// The purpose of this program is to show the use of the arguments in the main() function.

#include <iostream>
using namespace std;


int main(int argc, char** argv)
{
	// Output the value of argc.
	cout << "The value of argc is " << argc << endl;

	// Output the value of argv.
	unsigned long a = (unsigned long) argv;
	cout << "The value of argv is " << hex << argv << endl;


	// Output the value(s) of **argv
	for (int i = 0; i < argc; i++)
	{
		cout << "For argv element " << i << ", the value is " << *(argv + i) << endl;
	}

	// Output the value(s) of the addresses of the strings.
	for (int i = 0; i < argc; i++)
	{
		unsigned long a = (unsigned long) (*(argv + i));
		cout << "For argv element " << i << ", the address is " << hex << a << dec << endl;
	}

	// Count the number of characters in each string.
	for (int i = 0; i < argc; i++)
	{
		char* s = *(argv + i);
		int n = 0;
		for (int j = 0; s[j] != '\0'; j++)
		{
			n++;
		}
		cout << "For argv element " << i << ", the number of characters is " << n << endl;
	}

	return 0;
}

