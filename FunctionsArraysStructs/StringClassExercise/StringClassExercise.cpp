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

        if (length + textLength >= maxSize) throw std::runtime_error("String would exceed max size!");

        buffer.append(text, textLength);
        length += textLength;
    }

    void appendLine(const std::string& text)
    {
        if (length + text.length() >= maxSize) throw std::runtime_error("String would exceed max size!");

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
    try {
        StringClassExercise s1(20);
        s1.append("Foo");
        s1.appendLine("Bar");
        cout << "s1: ";
        s1.print();

        StringClassExercise s2("This is a long string", 25);
        s2.append(" and this is more");
        cout << "s2: " << s2.getString() << endl;

        StringClassExercise s3(5);
        s3.append("test");
        s3.appendLine("longer text");
        cout << "s3: " << s3.getString() << endl;
    }
    catch (const exception& e)
    {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}

