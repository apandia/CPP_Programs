#include <iostream>

using namespace std;

//Add "_CRT_SECURE_NO_WARNINGS" macro suppress warning/error related to strncpy

class MyString {
public:
	MyString(char* str = "") {
		m_length = strlen(str) + 1;
		mp_string = new char[m_length];

		strncpy(mp_string, str, m_length);
		mp_string[m_length - 1] = '\0';

		cout << "Default Constructor" << endl;
	}

	MyString& operator=(const MyString& source) {
		cout << "Overloaded assignment operator" << endl;
		//Check for self assignment
		if (this == &source)
			return *this;

		//deallocate any previously allocated memory
		delete[] mp_string;

		//update new lentgh
		m_length = source.m_length;

		if (m_length > 0) {
			//Allocate new memory
			mp_string = new char[m_length];

			//Copy new string
			strncpy(mp_string, source.mp_string, m_length);
			mp_string[m_length - 1] = '\0';
		}
		else {
			mp_string = 0;
		}

		//returns reference as can be used for chaining assignment operator i.e a = b = c
		return *this;
	}

	//Overloaded copy constructor
	//Imp Note: 
	//1. The parameter is pass by reference.
	//Reason: Copy constructor is called when a value is pass by value. If no reference then it wil result in infinite recursion.

	//2. const parameter is uses
	//Reason: Non-const references will not work for temporaries created by compiler as it doesn't make any sense to modify compiler
	//created temp objects as they can die any meoment
	MyString(const MyString& source) {
		cout << "Overloaded copy constructor" << endl;
		//update new lentgh
		m_length = source.m_length;

		if (m_length > 0) {
			//Allocate new memory
			mp_string = new char[m_length];

			//Copy new string
			strncpy(mp_string, source.mp_string, m_length);
			mp_string[m_length - 1] = '\0';
		}
		else {
			mp_string = 0;
		}
	}

	void display() {
		cout << "String = " << mp_string << endl;
	}

private:
	char* mp_string;
	int m_length;
};

//Driver function
int main()
{
	//Default Constructor
	MyString str1("Hello");
	str1.display();

	//Overloaded copy constructor
	MyString str2 = str1;
	str2.display();

	MyString str3;
	//Overloaded assignment operator
	str3 = str1;
	str3.display();

	//Default constructor will be called first to create temp MyString object with "Hi"
	//After that overloaded assignment operator will be called.
	str3 = "Hi";
	str3.display();

	//As per above logic, here copy constructor should have been called. But due to compiler optimization
	//technique called "Copy Ellision" default constructor will be called directly and not copy constructor
	MyString str4 = "Hi";
	str4.display();

	return 0;
}
