#include <cstdio>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    std::vector<float> userInputArray;

    while (true)
    {
        cout << "Input a number you want to add to the list" << endl;
        cout << "Press q when you are finished" << endl;

        string line;
        getline(cin, line);

        if (line.empty()) {
            continue;
        }

        if (line == "q")
        {
            break;
        }

        float number = stof(line);
        userInputArray.push_back(number);
    }

    int arrayTotal = 0;
    for (size_t i = 0; i < userInputArray.size(); ++i)
    {
        arrayTotal += userInputArray[i];
    }

    float average = (float)arrayTotal / (float)userInputArray.size();

    cout << "The numbers in the list you inputed are: ";
    for (size_t i = 0; i < userInputArray.size(); ++i)
    {
        cout << userInputArray[i] << " ";
    }
    cout << endl;
    cout << "The average of the list contents is: " << average << endl;

    return 0;
}
