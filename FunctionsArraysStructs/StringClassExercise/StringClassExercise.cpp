#include <iostream>
#include <cstring>

using namespace std;

class StringClassExercise
{
private:
    size_t length;
    char* buffer;
    size_t maxSize;

public:
    StringClassExercise(size_t maxSize) : buffer(new char[maxSize]), length(0), maxSize(maxSize)
    {
        cout << "Constructing empty string\n";
        buffer[0] = '\0';
    }

    StringClassExercise(const char* defaultText, size_t maxSize) : buffer(new char[maxSize]), length(strlen(defaultText)), maxSize(maxSize)
    {
        cout << "Constructing string with default text \"" << defaultText << "\"\n";

        if (length >= maxSize) throw runtime_error("Default text is too long!");

        strcpy_s(buffer, maxSize, defaultText);
    }

    ~StringClassExercise()
    {
        cout << "Destructing string \"" << buffer << "\"\n";
        delete[] buffer;
    }

    void append(const char* text)
    {
        size_t textLength = strlen(text);

        if (length + textLength >= maxSize) throw runtime_error("String would exceed max size!");

        strcat_s(buffer, maxSize, text);
        length += textLength;
    }

    void appendLine(const char* text)
    {
        size_t textLength = strlen(text);

        if (length + textLength >= maxSize) throw runtime_error("String would exceed max size!");

        strcat_s(buffer, maxSize, text);
        strcat_s(buffer, maxSize, "");

        length += textLength;
    }


    void print()
    {
        cout << "Current string: \"" << this->buffer << "\"\n";
    }

    const char* getString() const
    {
        return this->buffer;
    }
};

int main()
{
    try
    {
        StringClassExercise text1(20);
        text1.append("Foo");
        text1.appendLine("Bar");
        cout << "text1: ";
        text1.print();

        StringClassExercise text2("This is a long string", 25);
        text2.append(" and this is more");
        cout << "text2: " << text2.getString() << endl;

        StringClassExercise text3(5);
        text3.append("test");
        text3.appendLine("longer text");
        cout << "text3: " << text3.getString() << endl;
    }

    catch (const exception& e)
    {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
