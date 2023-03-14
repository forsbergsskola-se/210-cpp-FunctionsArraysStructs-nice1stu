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
        if (length >= maxSize)
        {
            throw runtime_error("Default text is too long!");
        }
    }

    ~StringClassExercise()
    {
        cout << "Destructing string \"" << buffer << "\"\n";
    }

    void append(const char* text)
    {
        size_t textLength = strlen(text);
        if (length + textLength >= maxSize)
        {
            throw runtime_error("String would exceed max size!");
        }
        buffer.resize(length + textLength);
        for (int i = 0; i < textLength; i++)
        {
            buffer[length + i] = text[i];
        }
        buffer[length + textLength] = '\0';
        length += textLength;
    }


    void appendLine(const char* text)
    {
        size_t textLength = char_traits<char>::length(text);
        if (this->length + textLength + 1 >= this->maxSize)
        {
            throw runtime_error("String with line break would exceed max size!");
        }
        this->buffer += text;
        this->buffer += '\n';
        this->length += textLength + 1;
    }

    // Print the current buffer
    void print()
    {
        cout << "Current string: \"" << this->buffer << "\"\n";
    }

    const char* getString() const
    {
        return this->buffer.c_str();
    }


};

int main()
{
    StringClassExercise myString(20);
    myString.append("Hello ");
    myString.appendLine("world!");
    myString.print();
    const char* bufferString = myString.getString();
    std::cout << "C-style string: " << bufferString << std::endl;
    return 0;
}
