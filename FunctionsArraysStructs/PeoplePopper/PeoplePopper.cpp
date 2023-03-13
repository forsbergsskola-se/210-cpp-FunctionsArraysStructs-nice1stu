#include <iostream>
#include <vector>

using namespace std;

vector<string> PeopleArray;
int howMany = 0;

struct Person
{
    string personName;
};

void FillInPeopleArray(vector<Person>& people)
{
    for (size_t i = 0; i < people.size(); ++i)
    {
        cout << "What's the next person supposed to be called?" << i + 1 << endl;
        cin >> people[i].personName;
        cout << endl;
    }
}

void DisplayPeopleArrayNames(const vector<Person>& people)
{
    for (size_t i = 0; i < people.size(); ++i)
    {
        cout << people[i].personName;
        if (i != people.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << endl;
}


int main()
{
    cout << "How many people would you like to create?" << endl;
    cin >> howMany;

    vector<Person> PeopleArray(howMany);
    FillInPeopleArray(PeopleArray);
    DisplayPeopleArrayNames(PeopleArray);
}
