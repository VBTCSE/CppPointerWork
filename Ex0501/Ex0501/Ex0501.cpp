// Ex0501.cpp : Defines the entry point for the console application.
//

/*

The purpose of this program is to review and demonstrate some concepts
concerning pointers in C++.

Ref: Dawson, "C++ Projects: Programming with Text-Based Games"

*/

#include <iostream>
#include <string>
using namespace std;



void functionA(double* pX);	// pass a pointer to a double

void functionB(const double* pX);	// pass a pointer to a constant double

void functionC(const double* const pX);	// pass a constant pointer to a constant double

int* functionD();	// return a pointer

const double* functionE(const double* const pX);	// pass a constant pointer to a constant double, return a constant pointer


int main()
{
	cout << "Program Ex0501" << endl << endl;

	//------------------------------------------------------------------------
	// 1. Computer memory is organized in an ordered way, 
	//    where each part of memory has its own unique address.
	


	//------------------------------------------------------------------------
	// 2. A pointer is a variable that contains a memory address.



	//------------------------------------------------------------------------
	// 3. To declare a pointer, you list a type, followed by an asterisk 
	//    (*), followed by a name.

	// To allow this next code to run to display the effect of not initializing 
	// a pointer, turn off uninitialized variable run-time checks.
	// Do this as follows: 
	// A. Project menu: select Ex0501 Properties.
	// B. Select Configuration Properties > C/C++ > Code Generation
	// C. Change the Basic Runtime Checks to Stack Frames (/RTCs)
	// D. Press the OK button to close the property page.
	// You can now run the following code.
	// When done, re-open the property page and change the 
	// Basic Runtime Checks to Both (/RTC1, quiv. to /RTCsu)(/RTC1).
	int* pn;	// pointer to an integer.
	cout << "3. Just declared a pointer to an integer, without initializing it."
		<< "\nHere's its value: " << pn << endl << endl;
	system("pause"); cout << endl;



	//------------------------------------------------------------------------
	// 4. Programmers often prefix pointer varible names with the letter "p"
	//    to remind them that the variable is indeed a pointer.
	double* px;	// pointer to a double.
	string* ps;	// pointer to a string.
	string* pAnotherString;	// pointer to a second string.



	//------------------------------------------------------------------------
	// 5. A pointer is declared to point to a value of a specific type, such
	//    as int, double, string, as shown above.



	//------------------------------------------------------------------------
	// 6. It's good programming practice to initialize a pointer when you 
	//    declare it.



	//------------------------------------------------------------------------
	// 7. The constant NULL, defined in iostream, can be assigned to a pointer
	//    to represent that the pointer doesn't point to any memory address.
	//    This is called a null pointer

	// This is better than the above declarations.
	int* pn2 = NULL;	// pointer to an integer.
	cout << "7. Just declared a pointer to an integer and initialized it."
		<< "\nHere's its value: " << pn2 << endl << endl;
	system("pause"); cout << endl;


	double* px2 = NULL;	// pointer to a double.
	string* ps2 = NULL;	// pointer to a string.
	string* pAnotherString2 = NULL;	// pointer to a second string.



	//------------------------------------------------------------------------
	// 8. To get the address of a variable, use the "address of" operator (&).

	int x = 5;	// a variable declared and initialized.
	// output its address:
	cout << "8. The integer variable x was declared and initialized with a value"
		<< " of 5.\nThe address of x is " << &x << endl << endl;
	system("pause"); cout << endl;



	//------------------------------------------------------------------------
	// 9. When a pointer contains the address of an object, it is said to 
	//    point to the object.  The pointer provides indirect access to the
	//    object to which it points.

	pn2 = &x;	// Use pn2 to get indirect access to x.
	cout << "9. The pointer pn2 now points to x.\nThe value of this pointer is " 
		<< pn2 << endl << endl;
	system("pause"); cout << endl;



	//------------------------------------------------------------------------
	// 10. Unlike references, pointers can be reassigned.  A pointer can be
	//     set to point to different objects at different times during the 
	//     life of a program.

	int y = 7;	// a new variable
	pn2 = &y;	// now pn2 points to y.
	cout << "10. The pointer pn2 has been changed and now points to y.\n"
		<< "The value of this pointer now is " << pn2 << endl << endl;
	system("pause"); cout << endl;



	//------------------------------------------------------------------------
	// 11. You dereference a pointer to access the object to which it points
	//     with *, the dereference operator.

	int z = *pn2;	// z has the value of the integer to which pn2 points.
	cout << "11. The variable z dereferences the pointer pn2.\n"
		<< "The value of this variable is " << z << endl << endl;
	system("pause"); cout << endl;



	//------------------------------------------------------------------------
	// 12. You can use the -> operator with pointers for a more readable way
	//     to access object members.

	struct vector	// define a vector structure
	{
		double x;
		double y;
	};

	vector v = { 3, 29 };	// declare a vector and initialize it
	vector* pv = &v;		// a pointer to the vector
	cout << "12. Have declared an instance v of the vector structure.\n"
		<< "The x component is " << pv->x << endl
		<< "The y component is " << pv->y << endl << endl;
	system("pause"); cout << endl;



	//------------------------------------------------------------------------
	// 13. A constant pointer can only point to the object that it was
	//     initialized to point to.  You declare a constant pointer by putting
	//     the keyword const before the pointer name.

	// value of variable pv->x can change, pointer cannot change
	double* const pCannotChange = &(pv->x);	
	cout << "13. Made a constant pointer to the double x component of the vector."
		<< "\nThis pointer's value is " << pCannotChange << endl
		<< "The value of the double to which it points is " << *pCannotChange
		<< endl << endl;
	cout << "Can change the value of the double variable.\n"
		<< "Initially, it is " << pv->x << endl;
	pv->x = 5.5;	// change it
	cout << "Changed double variable's value to " << pv->x << endl << endl;
	// Cannot do this, change it to point to something else:
	// pCannotChange = &(pv->y);
	system("pause"); cout << endl;



	//------------------------------------------------------------------------
	// 14. You cannot use a pointer to a constant to change the value to
	//     which it points.  A pointer to a constant is declared by putting 
	//     the keyword const before the type name.

	// First, declare some constant.
	const int DAYS_PER_WEEK = 7;
	const int WEEKS_PER_YEAR = 52;
	// Then, a pointer to this constant.
	const int* pDPW = &DAYS_PER_WEEK;
	cout << "14. Have declared and initialized a pointer to a constant integer.\n"
		<< "The value of the pointer is " << pDPW << endl
		<< "The value of the constant to which it points is " << *pDPW
		<< endl << endl;
	// Cannot do this, change the value to which the pointer points.
	// *pDPW = 10;
	// But it can be changed to point to another constant.
	pDPW = &WEEKS_PER_YEAR;
	cout << "Was able to change this pointer to point to another constant.\n"
		<< "Now the value of the pointer is " << pDPW << endl
		<< "The value of the constant to which it points is " << *pDPW
		<< endl << endl;
	system("pause"); cout << endl;



	//------------------------------------------------------------------------
	// 15. A constant pointer to a constant can only point to the value it
	//     which it was initialized to point to, and cannot be used to change
	//     that value.  This is declared as follows:
	const int* const pDPW2 = &DAYS_PER_WEEK;
	cout << "15. Have declared and initialized a constant pointer to a constant integer.\n"
		<< "The value of the pointer is " << pDPW2 << endl
		<< "The value of the constant to which it points is " << *pDPW2
		<< endl << endl;
	// Cannot do this, change the value to which the pointer points.
	// *pDPW2 = 10;
	// Also, cannot do this, change to point to another constant.
	//pDPW2 = &WEEKS_PER_YEAR;
	system("pause"); cout << endl;



	//------------------------------------------------------------------------
	// 16. You can pass pointers for efficiency or to provide indirect access
	//     to objects.
	cout << "16. Passing the x component of the vector to functionA().\n";
	double* pA = &(pv->x);
	cout << "The value passed into the function is " << *pA << endl << endl;
	functionA(pA);
	// However, the value of *pA could have been changed in the function:
	cout << "After returning from functionA, the value of the double that"
		<< "\n was passed into it has been changed to " << pv->x << endl << endl;
	system("pause"); cout << endl;



	//------------------------------------------------------------------------
	// 17. If you want to pass a pointer for efficiency, you should pass a
	//     pointer to a constant or a constant pointer to a constant, so the
	//     object that you are passing access to cannot be changed through the
	//     pointer.
	cout << "17. Passing the x component of the vector to functionB().\n";
	double* pB = &(pv->x);
	cout << "The value passed into the function is " << *pB << endl << endl;
	functionB(pB);
	// The value of the double passed in cannot be changed in the function:
	cout << "After returning from functionB, the value of the double that"
		<< "\n was passed into it has not been changed." << endl << endl;

	double* pC = &(pv->x);
	cout << "The value passed into the functionC is " << *pC << endl << endl;
	functionC(pC);
	// The value of the double passed in cannot be changed in the function:
	cout << "After returning from functionC, the value of the double that"
		<< "\n was passed into it has not been changed." << endl << endl;
	system("pause"); cout << endl;



	//------------------------------------------------------------------------
	// 18. A dangling pointer is a pointer to an invalid memory address.
	//     Dereferencing a dangling pointer can have disastrous results.
	//     Dangling pointers are often caused by deleting an object to which 
	//     a pointer pointed.  You should assign NULL to such a pointer.

	int* pM = new int(12);	// dynamically allocate an integer and set = 12.
	cout << "18. Alloc and init: pM = " << pM << " *pM = " << *pM << endl;
	delete pM;
	cout << "    Deleted object: pM = " << pM << " *pM = " << *pM << endl;
	pM = NULL;
	cout << "       Set pM NULL: pM = " << pM << endl << endl;
	system("pause"); cout << endl;



	//------------------------------------------------------------------------
	// 19. You can return a pointer from a function.  Be careful not to return
	//     a pointer to a local object because the object will cease to exist
	//     after the function returns.  This means that the returned pointer
	//     would be a dangling pointer.

	// First, a dangling pointer.
	cout << "19. Going to call functionD which returns a dangling pointer.\n\n";
	int* pDangling = functionD();
	cout << "The value of the returned pointer from functionD: " << pDangling
		<< "\nwhich points to a value of " << *pDangling << endl << endl;

	// Second, valid pointer returned.
	cout << "Going to call functionE, which returns a valid pointer.\n\n";
	// Passing a pointer to the x component of the vector.
	const double* pZ = functionE(&(pv->x));
	cout << "The value of the returned pointer from functionE: " << pZ
		<< "\nwhich points to a value of " << *pZ << endl << endl;
	system("pause"); cout << endl;



	//------------------------------------------------------------------------
	system("pause");

	return 0;
}


void functionA(double* pX)	// pass a pointer to a double
{
	cout << "Value passed into functionA: " << *pX << endl;
	cout << "through a pointer whose value is: " << pX << endl << endl;

	// Changing the value of the double within this function.
	*pX = 2 * (*pX) + 3.14159;
	cout << "Within functionA, changed the value of the double: " << *pX
		<< endl << endl;

	// And can do this.
	pX++;	// Change the value of the pointer itself.
	cout << "Within functionA, the pointer is changed.\n"
		<< "Now the value of the pointer is " << pX << endl
		<< "and it points to the value " << *pX << endl << endl;
}

void functionB(const double* pX)	// pass a pointer to a constant double
{
	cout << "Value passed into functionB: " << *pX << endl;
	cout << "through a pointer whose value is: " << pX << endl << endl;

	// Cannot do this.
	// *pX = 2 * (*pX) + 3.14159;

	// But can do this.
	pX++;	// Change the value of the pointer itself.
	cout << "Within functionB, the pointer is changed.\n"
		<< "Now the value of the pointer is " << pX << endl
		<< "and it points to the value " << *pX << endl << endl;
}


void functionC(const double* const pX)	// pass a constant pointer to a constant double
{
	cout << "Value passed into functionC: " << *pX << endl << endl;
	// Cannot do this.
	// *pX = 2 * (*pX) + 3.14159;

	// And, cannot do this either.
	// pX++;
}



int* functionD()	// return a pointer
{
	int* pk = new int(4);

	int* pn = pk;

	cout << "In functionD, the pointer value is " << pn
		<< "\nand it points to a value of " << *pn << endl << endl;

	delete pk; pk = NULL;	// release memory

	return pn;	// this will become a dangling pointer
}



const double* functionE(const double* const pX)	// pass a pointer to a constant double, return a pointer
{
	cout << "Value passed into functionE: " << *pX << endl;
	cout << "through a pointer whose value is: " << pX << endl << endl;

	// Cannot do this.
	// *pX = 2 * (*pX) + 3.14159;

	// And, cannot do this either.
	// pX++;

	const double* pE = pX + 1;

	cout << "Within functionE, a new pointer is formed.\n"
		<< "The value of the new pointer is " << pE << endl
		<< "and it points to the value " << *pE << endl << endl;

	cout << "The new pointer value will be returned.\n\n";


	return pE;
}
