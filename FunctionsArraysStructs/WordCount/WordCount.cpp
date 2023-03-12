#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

int main()
{
    vector<char> userInput = { 'H', 'e', 'l', 'l', 'o', ',', ' ', 'm', 'y', ' ', 'n', 'a', 'm', 'e', ' ', 'i', 's', ' ', 'M', 'a', 'r', 'c' };
    int wordCount = 0;
    bool isWord = false;

    for (auto c : userInput)
    {
        if (isalpha(c))
        {
            isWord = true;
        }
        else if (isWord)
        {
            wordCount++;
            isWord = false;
        }
    }

    if (isWord)
    {
        wordCount++;
    }

    cout << "The sentence has " << wordCount << " words." << endl;

    return 0;
}
