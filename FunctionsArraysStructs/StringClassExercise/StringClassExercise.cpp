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
        cout << endl;
        buffer[0] = '\0';
    }

    StringClassExercise(const char* defaultText, size_t maxSize) : buffer(new char[maxSize]), length(strlen(defaultText)), maxSize(maxSize)
    {
        cout << "Constructing string with default text \"" << defaultText << "\"\n";
        cout << endl;

        if (length >= maxSize) throw runtime_error("Default text is too long!");

        strcpy_s(buffer, maxSize, defaultText);
    }

    ~StringClassExercise()
    {
        cout << "Destructing string \"" << buffer << "\"\n";
        cout << endl;
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
        cout << endl;
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
        StringClassExercise joinText(20);
        joinText.append("Foo");
        joinText.appendLine("Bar");
        cout << "text1: ";
        joinText.print();

        StringClassExercise defaultText("The quick brown fox", 25);
        defaultText.append(" jumped over the lazy dog");
        cout << "text2: " << defaultText.getString() << endl;

        StringClassExercise tooLongText(5);
        tooLongText.append("test");
        tooLongText.appendLine("longer text");
        cout << "text3: " << tooLongText.getString() << endl;
    }

    catch (const exception& e)
    {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}