/* Private Constructor Use cases
 * 1. Calling constructor (creating object) only from friend function  (Example below)
 * 2. Singleton class (refer Singleton.cpp)
 * 3. Factory method usage (create instance only via a factory method.) (Refor FactoryMathod.cpp)
 * 4. Stop Prevent class creation on stack (Using a static function (Singleton.cpp) to create instance on heap. Note instance will still be created on stack using friend function)
 * 5. Named Constructor (refer NamedConstructor.cpp)
 * 6. Preventing creating copys of the class (refer PrivateCopyConstructor.cpp)
 */

#include <iostream>

using namespace std;

class A {
private:
	A() {
		cout << "A::Constructor" << endl;
	}

	~A() {
		cout << "A::Destructor" << endl;
	}

	friend class B;
};

class B{
public:
	B() {
		A a1;
		cout << "B::Constructor" << endl;
	}

	~B() {
		cout << "B::Destructor" << endl;
	}
};

//Driver code
int main()
{
	B b1;

	return 0;
}