#include <iostream>

using namespace std;

class MyClass {
public:
	MyClass(int value) {
		data = value;
		cout << "One parametr constructor" << endl;
	}

	void display() {
		cout << "data = " << data << endl;
	}

private:
	int data;
};

//Driver function
int main()
{
	MyClass obj(20);
	obj.display();

	//Call to single parameter constructor which acts as conversion constructor
	//Add keywor "explicit" to remove usage of conversion constructor. In that case below sentance will compilation error
	obj = 30; 
	obj.display();

	return 0;
}