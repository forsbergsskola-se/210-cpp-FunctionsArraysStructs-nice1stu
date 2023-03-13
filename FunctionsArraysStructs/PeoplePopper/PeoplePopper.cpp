#include <iostream>
#include <vector>

int howMany = 0;

using namespace std;

vector<string> PeopleArray;

//People struct
struct Person
{
    string personName;
};

void FillInPeopleArray(vector<Person>& arr)
{
    for (size_t i = 0; i < arr.size(); ++i)
    {
        cout << "What's the next person supposed to be called?" << i + 1 << endl;
        cin >> arr[i].personName;
        cout << endl;
    }
}

int main()
{
    cout << "How many people would you like to create?" << endl;
    cin >> howMany;
}
