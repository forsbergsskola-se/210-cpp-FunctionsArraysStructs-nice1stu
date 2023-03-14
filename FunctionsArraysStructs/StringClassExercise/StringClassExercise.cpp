#include <iostream>
#include <cstring>

using namespace std;

class StringClassExercise
{
private:
    int length;
    char* buffer;
    int maxSize;

public:
    StringClassExercise(int maxSize) : buffer(new char[maxSize]), length(0), maxSize(maxSize)
    {
        cout << "Constructing empty string\n";
        buffer[0] = '\0';
    }

    
};

int main()
{
    StringClassExercise myString(10);

    return 0;
}