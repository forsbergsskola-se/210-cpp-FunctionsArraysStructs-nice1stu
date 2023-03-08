// FunctionsArraysStructs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct Vector
{
    int x, y;

    Vector(int a, int b)
    {
        x = a;
        y = b;
    }

    Vector operator+(Vector v)
    {
        int a = x + v.x;
        int b = y + v.y;
        return Vector(a, b);
    }

    void print()
    {
        cout << "Vector(" << x << "," << y << ")" << endl;
    }
};

int main()
{
    cout << "Vector2D\n";
    Vector v1(3, 2);
    Vector v2(-1, -2);
    cout << "Adding ";
    v1.print();
    cout << " and ";
    v2.print();
    cout << "..." << endl;
    Vector result = v1 + v2;
    cout << "Result: ";
    result.print();
    return 0;
}
