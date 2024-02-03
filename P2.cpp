#include "Circle.h"
#include <iostream>
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

double Distance(Circle &a)
{
    return sqrt(pow((a.getX()), 2) + pow((a.getY()), 2));
}

double Circle::Area() const
{
    // return 2 * M_PI * radius;
    return M_PI * (pow(radius, 2));
}

void print(Circle &a)
{
    // cout << this->x << " " << this->y << " " << this->radius << endl;
    cout << "x: " << a.getX() << endl;
    cout << "Y: " << a.getY() << endl;
    cout << "Radius: " << a.getRadius() << endl;
    cout << "Area: " << a.Area() << endl;
    cout << "Diameter: " << a.Perimeter() << endl;
    cout << "Distance: " << Distance(a) << endl;
}

int main()
{
    Circle circle1(2, 4, 3.4);
    Circle c2;
    //
    double distanceFM0 = Distance(circle1);
    //
    cout << "Values stored in Circle1: \n";
    print(circle1);
    cout << "\n";
    //
    cout << "Values stored in Circle2: \n";
    print(c2);
}