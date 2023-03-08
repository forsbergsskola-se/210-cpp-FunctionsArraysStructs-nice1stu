// FunctionsArraysStructs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

struct Vector
{
    int x, y;

    static Vector Zero()
    {
        return Vector(0, 0);
    }

    static Vector One()
    {
        return Vector(1, 1);
    }

    Vector operator+(Vector v)
    {
        return Vector(x + v.x, y + v.y);
    }

    void print()
    {
        cout << "Vector(" << x << "," << y << ")" << endl;
    }


    Vector(int a, int b)
    {
        x = a;
        y = b;
    }
};

int main()
{
    cout << "Vector2D\n";
    Vector v1(3, 2);
    Vector v2(-1, -2);
    cout << "Adding " << v1.print() << " and " << v2.print() << "..." << endl;
    Vector result = v1 + v2;
    cout << "Result: ";
    result.print();
    return 0;
}
