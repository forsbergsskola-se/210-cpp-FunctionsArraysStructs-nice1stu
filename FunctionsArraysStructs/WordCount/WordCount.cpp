#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    char userInput [100];
    auto wordCount { 0 };
    bool isWord = false;
    // array decay
    char* pointer = userInput;

    cout << "Please type in a sentence. Press [Enter] to finish." << endl;
    cin.getline(userInput, 100);

    while (*pointer != '\0')
    {
        if (isalpha(*pointer))
        {
            if (!isWord)
            {
                ++wordCount;
                isWord = true;
            }
        }
        else isWord = false;

        ++pointer;
    }

    cout << "The sentence has " << wordCount << " words." << endl;

    return 0;
}
