#include <iostream>

using namespace std;

bool isPalindrome(string userInput)
{
    for (size_t i = 0; i < userInput.length() / 2; ++i)
    {
        if (userInput[i] != userInput[userInput.length() - i - 1])
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