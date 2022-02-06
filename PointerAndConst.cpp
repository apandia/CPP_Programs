#include <iostream>

using namespace std;

int main()
{
	int a = 60, b = 70, c = 80;

	//1. pointer to const. 
	//Pointer points a variable whose vaue can't be changed
	const int* ptr = &a;
	cout << "*ptr = " << *ptr << endl;

	//value at location pointer to by ptr can not be changed.below line will give compilation error.
	//*ptr = 10;

	//pointer can points to another variable
	ptr = &b;
	cout << "*ptr = " << *ptr << endl;

	//2. constant pointer
	int* const ptr2 = &c; //const pointer has to initialized in same line
	cout << "*ptr2 = " << *ptr2 << endl;

	//pointer can not points to another variable. Below sentence will give compilation error
	//ptr2 = &b;

	// the value of variable c can be changed through the pointer though.
	*ptr2 = 90;
	cout << "*ptr2 = " << *ptr2 << endl;

	return 0;
}