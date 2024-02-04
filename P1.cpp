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

double Circle::Distance() const
{
    // sqrt(pow((x - 0), 2) + pow((y - 0), 2));
    // Samething but this is shorter -> x - 0 = the value x has. same applies to y.
    return sqrt(pow(x, 2) + pow(y, 2));
}

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