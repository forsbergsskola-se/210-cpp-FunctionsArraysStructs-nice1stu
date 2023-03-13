#include <iostream>
#include <math.h>

using namespace std;

enum class MathOperation : int
{
    Add,
    Subtract,
    Multiply,
    Divide
};

class Calculator
{
public:
    Calculator(MathOperation op);
    ~Calculator();
    void Calculate();
    void setNum1(float num) { num1 = num; }
    void setNum2(float num) { num2 = num; }
    float getAnswer() const { return answer; }

private:
    float num1;
    float num2;
    float answer;
    MathOperation operation;
};

Calculator::Calculator(MathOperation op)
{
    operation = op;
}

Calculator::~Calculator() {}

void Calculator::Calculate()
{
    if (operation == MathOperation::Add) answer = num1 + num2;

    else if (operation == MathOperation::Subtract) answer = num1 - num2;

    else if (operation == MathOperation::Multiply) answer = num1 * num2;

    else if (operation == MathOperation::Divide) answer = num1 / num2;

    else
    {
        cout << "I can't do that Dave." << endl;
        return;
    }

}

int main()
{
    float num1, num2;
    int operation;

    cout << "Welcome to C++ Calculator" << endl;
    cout << "Enter the 1st number: ";
    cin >> num1;

    cout << "What calculation would you like to carry out?" << endl;
    cout << "0 - Add" << endl;
    cout << "1 - Subtract" << endl;
    cout << "2 - Multiply" << endl;
    cout << "3 - Divide" << endl;
    cin >> operation;
        cout << "Enter the 2nd number: ";
    cin >> num2;

    Calculator calc(static_cast<MathOperation>(operation));
    calc.setNum1(num1);
    calc.setNum2(num2);
    calc.Calculate();
    cout << "Answer: " << calc.getAnswer() << endl;

    return 0;
}
