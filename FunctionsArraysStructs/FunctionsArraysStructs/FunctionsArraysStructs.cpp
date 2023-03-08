// FunctionsArraysStructs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

//Fibonacci
//fn = fn-1 + fn-2

int fibonacciIterative(int n)
{
    int i, fnOne = 0, fnTwo = 1, fnThree;
    if (n == 0) return fnOne;
    for (i = 2; i <= n; ++i)
    {
        fnThree = fnOne + fnTwo;
        fnOne = fnTwo;
        fnTwo = fnThree;
    }
    return fnTwo;
}






//Vector Addition
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
    //vector
    cout << "Vector2D\n";
    Vector v1(3, 2);
    Vector v2(-1, -2);
    cout << "Adding "; v1.print(); cout << " and "; v2.print(); cout << "…" << endl;
    Vector result = v1 + v2;
    cout << "Result: ";
    result.print();

    //fibonacciIterative
    int n = 10;
    cout << "Iterative Fibonacci to " << n << " is " << fibonacciIterative(n);
    

    return 0;
}
