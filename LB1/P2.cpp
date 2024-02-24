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
double Circle::Distance(const Circle &a) const
{
    return sqrt(pow((x - a.x), 2) + pow((y - a.y), 2));
}