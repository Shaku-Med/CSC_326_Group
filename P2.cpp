#include "Circle.h"
#include <iostream>
#include <cmath>
//
using namespace std;

Circle::Circle()
{
    x, y = 0;
    radius = 0.0;
}

Circle::Circle(int xv, int yv, double rd)
{
    x = xv;
    y = yv;
    radius = rd;
}

void Circle::set(int xv, int yv, double rd)
{
    this->x = xv;
    this->y = yv;
    this->radius = rd;
}

double Circle::Area() const
{
    // return 2 * M_PI * radius;
    return M_PI * (pow(radius, 2));
}

//

//
double Circle::Distance(const Circle &a) const
{
    return sqrt(pow((x - a.x), 2) + pow((y - a.y), 2));
}

void Circle::print()
{
    // cout << this->x << " " << this->y << " " << this->radius << endl;
    cout << "x: " << this->x << endl;
    cout << "Y: " << this->y << endl;
    cout << "Radius: " << this->radius << endl;
    cout << "Area: " << this->Area() << endl;
    cout << "Diameter: " << this->Perimeter() << endl;
    cout << "Distance from the circle of 1 to the origin:  " << this->Distance() << endl;
    cout << ".............................." << endl;
}

int main()
{
    Circle obj1, obj2, *p1, *p2;
    //
    p1 = &obj1;
    p2 = &obj2;
    Circle *p3 = new Circle[2];
    //
    p1->set(3, 7, 4.2);
    p2->set(2, 4, 9);
    p3[0].set(1, 3, 4);
    p3[1].set(9, 2, 6);
    //
    p1->Area();
    p1->getX();
    p1->getY();
    p1->Perimeter();
    p1->Distance();
    obj1.Distance(obj2);
    //
    p2->Area();
    p2->getX();
    p2->getY();
    p2->Perimeter();
    p2->Distance();
    obj2.Distance(obj1);
    //
    p3[0].Area();
    p3[0].getX();
    p3[0].getY();
    p3[0].Perimeter();
    p3[0].Distance();
    p3[0].Distance(obj1);
    //
    //
    p3[1].Area();
    p3[1].getX();
    p3[1].getY();
    p3[1].Perimeter();
    p3[1].Distance();
    p3[1].Distance(obj2);
    //
    //
    p1->print();
    p2->print();

    p3[0].print();
    p3[1].print();

    delete[] p3;
}