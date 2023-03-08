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

int fibonacciRecursive(int r)
{
    if (r <= 1) return r;
    return fibonacciRecursive(r - 1) + fibonacciRecursive(r - 2);
}

//ArrayAverage
void getUserInput(int numArray[], int numArraySize)
{
    int total = 0;
    for (size_t i = 0; i < numArraySize; ++i)
    {
        cout << "Enter a number & press Enter\n";
        cin >> numArray[i];
        total += numArray[i];
    }
    cout << "Total: " << total << endl;
    cout << "Average: " << (total / numArraySize) << endl;

    //bubble sort array
    for (size_t i = 0; i < numArraySize - 1; ++i)
    {
        for (size_t j = 0; j < numArraySize - i - 1; ++j)
        {
            if (numArray[j] > numArray[j + 1])
            {
                // Swap numArray[j] and numArray[j+1]
                int temp = numArray[j];
                numArray[j] = numArray[j + 1];
                numArray[j + 1] = temp;
            }
        }
    }

    cout << "Sorted array: ";
    for (size_t i = 0; i < numArraySize; ++i)
    {
        cout << numArray[i] << " ";
    }
    cout << endl;

    double median;
    if (numArraySize % 2 == 0)
    {
        median = (numArray[numArraySize / 2 - 1] + numArray[numArraySize / 2]) / 2.0;
    }
    else
    {
        median = numArray[numArraySize / 2];
    }

    cout << "Median: " << median << endl;
}

//EmployeeStruct

struct EmployeeInfo
{
    char firstName[256];
    char lastName[256];
    int personnummer;
    int phoneNumber;
    int dateOfEmployment;
    char gender[256];
    int addressStreetNo;
    char addressStreet[256];
    char addressCity[256];
};


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
    cout << "Iterative Fibonacci to " << n << " is " << fibonacciIterative(n) << endl;

    //fibonacciRecursive
    int r = 3;
    cout << "Recursive fibonacci of " << r << " is " << fibonacciRecursive(r) << endl;
    
    //ArrayAverage
    int number[9];
    getUserInput(number, 9);

    return 0;
}
