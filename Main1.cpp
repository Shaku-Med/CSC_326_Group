#include "Circle.h"
#include <iostream>
using namespace std;

int main()
{
    Circle obj1, obj2(1, 2, 3), *p1, *p2;
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