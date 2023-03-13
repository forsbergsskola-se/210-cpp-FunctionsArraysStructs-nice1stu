#include <iostream>

using namespace std;

bool isPalindrome(char* letter, size_t length)
{
    char* front = letter;
    char* back = letter + length - 2;
    for (size_t i = 0; i < length-1; ++i)
    {
        if (*front != *back) return false;
    }
    return true;
}

int main()
{
    char userInput [32];

    cout << "enter a word to check then press [Enter]" << endl;
    cin.getline(userInput, 32);

    if (isPalindrome) cout << "It is a palindrome" << endl;
    
    else cout << "It is not a palindrome" << endl;

    return 0;
}