#include <iostream>
#include <functional>

using namespace std;

//Normal function to add 2 numbers and return the sum
int add(int a, int b)
{
	return a + b;
}

void AddTwoNumber(int a, int b, const std::function<int(int, int)>& func)
{
	int value = func(a, b);
	cout << "Using lambda and std function = " << value << endl;
}

void PrintHelloWorld(const std::function<void(void)>& func)
{
	func();
}

int main()
{
	cout << "Normal add function = " << add(2, 5) << endl;

	//lamda function
	//syntax:
	//1. [] -> tells that it is lamda function
	//2. (int a, int b) --> input parameter for the function
	//3. {} --> function body (return sum in this case)
	//4. (2, 5) --> value with which lamda function will be called
	cout << "Addition using Lamda function = " << [](int a, int b) {return a + b; } (2, 5)<< endl;

	//Assign lamda unction to a variable and use it
	auto add = [](int a, int b) {return a + b; };
	cout << "Addition using reusable lamda function = " << add(2, 5) << endl;

	//Using lambda and std function
	AddTwoNumber(2,5, [](int a, int b) {return a + b; });

	//lambda function example with no parameter, only some print
	PrintHelloWorld([]() {cout << "hello World!" << endl; });

	return 0;
}
