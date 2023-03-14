#include <iostream>
#include <string>

using namespace std;

class StringClassExercise
{
private:
    size_t length; // use size_t instead of int
    string buffer; // use string instead of char*
    size_t maxSize; // use size_t instead of int

public:
    StringClassExercise(size_t maxSize) : buffer(""), length(0), maxSize(maxSize)
    {
        cout << "Constructing empty string\n";
    }

    StringClassExercise(const char* defaultText, size_t maxSize) : buffer(defaultText), length(buffer.size()), maxSize(maxSize)
    {
        cout << "Constructing string with default text \"" << defaultText << "\"\n";

        if (length >= maxSize) throw runtime_error("Default text is too long!");
    }

    ~StringClassExercise()
    {
        cout << "Destructing string \"" << buffer << "\"\n";
    }

    void append(const char* text)
    {
        size_t textLength = strlen(text);

        if (length + textLength >= maxSize) throw runtime_error("String would exceed max size!");

        buffer.append(text, textLength);
        length += textLength;
    }

    void appendLine(const string& text)
    {
        if (length + text.length() >= maxSize) throw runtime_error("String would exceed max size!");

        buffer.append(text);
        length += text.length();
    }

    void print()
    {
        cout << "Current string: \"" << this->buffer << "\"\n";
    }

    const char* getString() const
    {
        return this->buffer.data();
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