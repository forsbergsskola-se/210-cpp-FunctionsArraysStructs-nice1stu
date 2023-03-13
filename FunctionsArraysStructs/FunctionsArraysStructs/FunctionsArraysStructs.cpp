// FunctionsArraysStructs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

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
void getUserInput(int numArray[], size_t numArraySize)
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

//Address struct (employee struct)
struct Address
{
    int addressStreetNo;
    string addressStreet;
    string addressCity;
};

//EmployeeStruct
struct EmployeeInfo
{
    string firstName;
    string lastName;
    long long personnummer;
    int phoneNumber;
    int dateOfEmployment;
    char gender[256];
    Address address;
    int salary;
};

//store the info in an array
void FillInEmployeeArray(EmployeeInfo arr[], size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        cout << "Enter data for employee " << i + 1 << endl;
        cout << "First Name: " << endl;
        cin >> arr[i].firstName;
        cout << "Last Name: " << endl;
        cin >> arr[i].lastName;
        cout << "Personnummer: AAAAMMDDxxxx" << endl;
        cin >> arr[i].personnummer;
        cout << "Phone Number: " << endl;
        cin >> arr[i].phoneNumber;
        cout << "Date of Employment: AAAAMMDD" << endl;
        cin >> arr[i].dateOfEmployment;
        cout << "Gender: M/F/L/G/B/T/Q" << endl;
        cin >> arr[i].gender;
        cout << "Address Street No.: " << endl;
        cin >> arr[i].address.addressStreetNo;
        cout << "Address Street: " << endl;
        cin >> arr[i].address.addressStreet;
        cout << "Address City: " << endl;
        cin >> arr[i].address.addressCity;
        cout << "Employee Salary" << endl;
        cin >> arr[i].salary;
        cout << endl;
    }
}

//print employee data
void printEmployeeData(EmployeeInfo employees[], int numEmployees)
{
    for (size_t i = 0; i < numEmployees; ++i)
    {
        cout << "Employee #" << i + 1 << " data:" << endl;
        cout << "First name: " << employees[i].firstName << endl;
        cout << "Last name: " << employees[i].lastName << endl;
        cout << "Personnummer: " << employees[i].personnummer << endl;
        cout << "Phone number: " << employees[i].phoneNumber << endl;
        cout << "Date of employment: " << employees[i].dateOfEmployment << endl;
        cout << "Gender: " << employees[i].gender << endl;
        cout << "Street number: " << employees[i].address.addressStreetNo << endl;
        cout << "Street name: " << employees[i].address.addressStreet << endl;
        cout << "City: " << employees[i].address.addressCity << endl;
        cout << "Salary: " << employees[i].salary << endl;
        cout << endl;
    }
}

//average employeeSalary
double averageSalary(EmployeeInfo employees[], size_t numEmployees)
{
    int sum = 0;
    for (size_t i = 0; i < numEmployees; ++i)
    {
        sum += employees[i].salary;
    }
    return (double)sum / numEmployees;
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

//Swap Pointer Values
void SwapPointerValues(int* pointer1, int* pointer2)
{
    int temp = *pointer1;
    *pointer1 = *pointer2;
    *pointer2 = temp;
}


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

    //Employee Info
    const int numEmployees = 5;
    EmployeeInfo employees[numEmployees];
    FillInEmployeeArray(employees, numEmployees);
    printEmployeeData(employees, numEmployees);
    double avgSalary = averageSalary(employees, numEmployees);
    cout << "Average Salary: " << avgSalary << endl;

    //Swap values behind both pointers
    int four = 4;
    int* pFour = &four;
    printf("This is pointer four: %d\n", pFour);
    int five = 5;
    int* pFive = &five;
    printf("This is pointer five: %d\n", pFive);

    printf("This is four: %d, This is five: %d\n", four, five);
    SwapPointerValues(pFour, pFive);
    printf("This used to be four: %d, This used to be five: %d\n", four, five);

    return 0;
}
