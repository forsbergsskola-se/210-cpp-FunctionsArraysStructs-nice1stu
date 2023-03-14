#include <iostream>
#include <vector>

using namespace std;


struct Person;
void FillInPeopleArray(vector<Person*>& people);
void DisplayPeopleArrayNames(const vector<Person*>& people);

int main()
{
    auto howMany{ 0 };
    cout << "How many people would you like to create?" << endl;
    cin >> howMany;

    vector<Person*> PeopleArray(howMany);
    FillInPeopleArray(PeopleArray);
    DisplayPeopleArrayNames(PeopleArray);

    for (size_t i = 0; i < PeopleArray.size(); ++i)
    {
        delete PeopleArray[i];
    }
    return 0;
}

struct Person
{
    string personName;
};

void FillInPeopleArray(vector<Person*>& people)
{
    for (size_t i = 0; i < people.size(); ++i)
    {
        people[i] = new Person;
        cout << "What's the next person supposed to be called?" << endl;
        cin >> people[i]->personName;
        cout << endl;
    }
}

void DisplayPeopleArrayNames(const vector<Person*>& people)
{
    for (size_t i = 0; i < people.size(); ++i)
    {
        cout << people[i]->personName;
        if (i != people.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << endl;
}