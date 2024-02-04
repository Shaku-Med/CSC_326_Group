#include ""
#include <iostream>
using namespace std;

double distance(const Circle &c);
void print(const Circle &c);

int main()
{
}

// New non-member function definitions
double distance(const Circle &c)
{
    return sqrt(pow((c.getX() - 0), 2) + pow((c.getY() - 0), 2));
}

void print(const Circle &c)
{
    cout << "X: " << c.getX() << "\nY: " << c.getY() << "\nRadius: "
         << "Radius: " << c.getRadius() << "\n"
         << endl;
}