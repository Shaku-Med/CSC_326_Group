#include "Circle.h"
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // Declaring a circle objects.
    Circle obj1, obj2(1, 2, 3), *p1, *p2;

    // Pointing the the object.
    p1 = &obj1;
    p2 = &obj2;

    // Making a dynamic allocation to the circle.
    Circle *p3 = new Circle[2];

    // Setting objects using the set functions.
    p1->set(3, 7, 4.2);
    // p2->set(2, 4, 9);
    p3[0].set(1, 3, 4);
    p3[1].set(9, 2, 6);

    // Using all functions for  pointer 1 (p1) which points to object 1.
    p1->Area();
    p1->getX();
    p1->getY();
    p1->Perimeter();
    p1->Distance();

    // Using all functions for  pointer 2 (p2) which points to object 2.
    p2->Area();
    p2->getX();
    p2->getY();
    p2->Perimeter();
    p2->Distance();
    //
    cout << "This program will calculate the diameter and area of a circle with X corordinate of " << p1->getX() << " a y coordinate of " << p1->getY() << ", and a radius of " << p1->getRadius() << "\nHere is the circle's data: " << endl;
    p1->print();
    //
    cout << "Here is another circle whose x, y and radius were set using the constructor initializer. The x coordinate is " << p2->getX() << ", the y coordinate is " << p2->getY() << ", and the radius is " << p2->getRadius() << endl;
    p2->print();
    //
    cout << "Distance from the center of Circle 1 to the center of Circle 2: " << obj1.Distance(obj2) << endl;
    //
    // Using all functions for  pointer 3 (p3) which points to object 3.
    p3[0].Area();
    p3[0].getX();
    p3[0].getY();
    p3[0].Perimeter();
    p3[0].Distance();
    //
    p3[1].Area();
    p3[1].getX();
    p3[1].getY();
    p3[1].Perimeter();
    p3[1].Distance();
    //
    cout << "Here is another circle: " << endl;
    p3[0].print();
    cout << "Here is another circle: " << endl;
    p3[1].print();
    //
    cout << "Distance from the center of Circle 2 to the center of Circle 3: " << p3[0].Distance(obj1) << endl;

    // Releasing or clearing the dynamic object.
    delete[] p3;
}