#ifndef CIRCLE_H
#define CIRCLE_H

#include <math.h>
#include <cmath>

class Circle
{
private:
    int x, y;
    double radius;

public:
    // CONSTRUCTORS
    Circle();                            // DEFAULT CONSTRUCTOR
    Circle(int x, int y, double radius); // CONSTRUCTOR WITH PARAMETERS

    // GETTER FUNCTIONS
    int getX() const
    {
        return this->x;
    };

    int getY() const
    {
        return this->y;
    };
    //
    int getRadius() const
    {
        return this->radius;
    };
    // GETTER FUNCTIONS ENDS HERE

    // Set function
    void set(int x, int y, double radius);
    // Set function ends here.

    double Area() const;
    double Perimeter() const
    {
        // 2 * M_PI * radius
        return 2 * M_PI * radius;
    };
    double Distance() const;
    double Distance(const Circle &a) const;
    //
    void print();
};

#endif
