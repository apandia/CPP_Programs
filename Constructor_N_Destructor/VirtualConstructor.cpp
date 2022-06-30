#include <iostream>

using namespace std;

class Base {
public:
	Base() {
		cout<< "Base Constructor"<<endl;
	}

	virtual ~Base() {
		cout << "Base Destructor" << endl;
	}

	static Base* create(int id);

	virtual void display() {
		cout << " Base::Display" << endl;
	}
};

class Derived1 : public Base {
public:
	Derived1() {
		cout << "Derived1 Constructor" << endl;
	}

	~Derived1() {
		cout << "Derived1 Destructor" << endl;
	}

	void display() {
		cout << " Derived1::Display" << endl;
	}
};

class Derived2 : public Base {
public:
	Derived2() {
		cout << "Derived2 Constructor" << endl;
	}

	~Derived2() {
		cout << "Derived2 Destructor" << endl;
	}

	void display() {
		cout << " Derived2::Display" << endl;
	}
};


//create function acts as virtual constructor creating instances at runtime.
Base* Base::create(int id)
{
	Base* instance = nullptr;

	switch (id)
	{
	case 1:
		instance = new Derived1;
		break;
	case 2:
		instance = new Derived2;
		break;
	default:
		instance = new Base;
		break;
	}

	return instance;
}

//Utility/user code to use above Base and Derived classes
int main()
{
	Base* b1 = Base::create(1);
	b1->display();

	Base* b2 = Base::create(2);
	b2->display();

	delete b1;
	b1 = nullptr;

	delete b2;
	b2 = nullptr;

	return 0;
}
