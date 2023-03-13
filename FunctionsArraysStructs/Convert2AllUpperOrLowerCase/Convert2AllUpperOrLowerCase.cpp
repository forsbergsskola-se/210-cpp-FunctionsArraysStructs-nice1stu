#include <iostream>
#include <string>
#include <cctype>

using namespace std;


int main()
{
    string userInput;

    cout << "enter a sentence to convert then press [Enter]" << endl;
    getline(cin, userInput);
    
    for (size_t i = 0; i < userInput.length(); ++i)
    {
        userInput[i] = toupper(userInput[i]);

    }
    cout << userInput << endl;

    for (size_t i = 0; i < userInput.length(); ++i)
    {
        userInput[i] = tolower(userInput[i]);

    }
    cout << userInput << endl;

    return 0;
}