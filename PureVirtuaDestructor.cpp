#include <iostream>

using namespace std;

class Base {
public:
	virtual ~Base() = 0;
	// Pure virtual destructor
};

//Pure virtual functions needs to have  body unlike pure virtual functions.
//This is because base destructor will always be called after derived destructor.
Base::~Base() {
	std::cout << "Base Pure virtual destructor is called"<<endl;
}

class Derived : public Base {
public:
	~Derived() { cout << "Derived destructor is called"<<endl; }
};

// Driver Code
int main()
{
	//Base object cant be created. Because of pure virtaul destructor the class will behave like abstract class.
	//below sentence will give compilation error
	//Base a;

	Base* b = new Derived();
	delete b;

	return 0;
}