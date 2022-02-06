// named constructor idiom is used to solve ambiguous nature of constructor.
// Constructor with same no of parameters of same type
// Declare all the class’s constructors in the private or protected sections, and then for accessing objects of class, create public static functions.

#include <iostream>

using namespace std;

class Point {
private:
	Point(float x, float y) {
		mx = x;
		my = y;
	}

	float mx, my;

public:
	//Calls the private constructor for each use case
	//Note: We can not have overloaded constructor with same number of argument and type
	static Point Polar(float radius, float angle);
	static Point Rectangular(float length, float breadth);

	void display() {
		cout << "(" <<mx << ", " << my << ")" << endl;
	}
};

Point Point::Polar(float radius, float angle)
{
	return Point(radius*cos(angle), radius*sin(angle));
}
Point Point::Rectangular(float length, float breadth)
{
	return Point(length, breadth);
}


//Driver function
int main()
{
	// Polar coordinates
	Point polar = Point::Polar(5.5, 45);
	cout << "Polar coordinates : ";
	polar.display();


	// rectangular coordinates
	Point rect = Point::Rectangular(4.5, 2.6);
	cout << "Rectangular coordinates :";
	rect.display();

	return 0;
}