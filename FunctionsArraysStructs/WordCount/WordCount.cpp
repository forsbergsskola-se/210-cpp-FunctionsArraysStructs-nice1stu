#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

int main()
{
    vector<char> userInput;
    char c;
    int wordCount = 0;
    bool isWord = false;

    cout << "Please type in a sentence. Press [Enter] to finish." << endl;

    while (cin.get(c))
    {
        if (c == '\n' || c == '\r') break;
        
        userInput.push_back(c);

        if (isalpha(c)) isWord = true;
        else if (isWord)
        {
            wordCount++;
            isWord = false;
        }
    }

    if (isWord) wordCount++;

    cout << "The sentence has " << wordCount << " words." << endl;

    return 0;
}