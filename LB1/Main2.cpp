#include "Circle2.h"
#include <iostream>
using namespace std;

double distance(const Circle &c);
void print(const Circle &c);

int main()
{
    Circle obj1, obj2(1, 2, 3), *p1, *p2;
    Circle *p3 = new Circle[2];

    //
    p1 = &obj1;
    p2 = &obj2;
    //
    p1->set(1, 5, 2);
    p2->set(2, 4, 9);
    //
    p3[0].set(1, 3, 4);
    p3[1].set(9, 2, 6);
    //

    p1->Area();
    p1->getX();
    p1->getY();
    p1->Perimeter();
    //
    p2->Area();
    p2->getX();
    p2->getY();
    p2->Perimeter();
    //
    p3[0].Area();
    p3[0].getX();
    p3[0].getY();
    p3[0].Perimeter();
    //
    //
    p3[1].Area();
    p3[1].getX();
    p3[1].getY();
    p3[1].Perimeter();
    //

    // Demonstrate new non-member functions
    cout << "This program will calculate the diameter and area of a circle with X corordinate of " << p1->getX() << " a y coordinate of " << p1->getY() << ", and a radius of " << p1->getRadius() << "\nHere is the circle's data: " << endl;
    print(obj1);
    //
    cout << "Here is another circle whose x, y and radius were set using the constructor initializer. The x coordinate is " << p2->getX() << ", the y coordinate is " << p2->getY() << ", and the radius is " << p2->getRadius() << endl;
    print(obj2);

    cout << "Distance from the center of Circle 1 to the center of Circle 2: " << obj1.Distance(obj2) << endl;
    //
    cout << "Here is another circle: " << endl;
    print(p3[0]);

    cout << "Here is another circle: " << endl;
    print(p3[1]);
    cout << "Distance from the center of Circle 2 to the center of Circle 3: " << p3[0].Distance(obj1) << endl;

    delete[] p3;

    return 0;
}

// New non-member function definitions
double distance(const Circle &c)
{
    return sqrt(pow((c.getX()), 2) + pow((c.getY()), 2));
}

void print(const Circle &c)
{
    cout << "\nX: " << c.getX() << endl;
    cout << "Y: " << c.getY() << endl;
    cout << "Radius: " << c.getRadius() << endl;
    cout << "Area: " << c.Area() << endl;
    cout << "Diameter: " << c.Perimeter() << endl;
    // Non-member function Distance() is invoked here
    cout << "Distance from the circle to the origin:  " << distance(c) << endl;
    cout << ".............................." << endl;
}