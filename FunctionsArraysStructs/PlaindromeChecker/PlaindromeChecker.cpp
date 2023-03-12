#include <iostream>

using namespace std;

bool isPalindrome(string userInput)
{
    int n = userInput.length();
    for (int i = 0; i < n / 2; i++)
    {
        if (userInput[i] != userInput[n - i - 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    char* userInput = new char[32];

    cout << "enter a word to check then press [Enter]" << endl;
    cin.getline(userInput, 32);

    if (isPalindrome(userInput)) cout << "It is a palindrome" << endl;
    
    else cout << "It is not a palindrome" << endl;

    delete[] userInput;

    return 0;
}