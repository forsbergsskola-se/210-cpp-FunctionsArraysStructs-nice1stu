#include <iostream>
#include <cstring>

class FixedString
{
public:
    FixedString(int maxSize);
    FixedString(const char* defaultText, int maxSize);
    ~FixedString();
    void append(const char* text);
    void appendLine(const char* text);
    void print();
    const char* getString();

private:
    int length;
    char* buffer;
    int maxSize;
};

int main() {
    FixedString str1(10);
    FixedString str2("Hello", 10);
    str1.append("World");
    str1.appendLine("!");
    str1.print();
    std::cout << "String contents: " << str1.getString() << std::endl;
    return 0;
}

FixedString::FixedString(int maxSize) : length(0), maxSize(maxSize)
{
    buffer = new char[maxSize];
    std::cout << "Constructed empty string" << std::endl;
}

FixedString::FixedString(const char* defaultText, int maxSize) : maxSize(maxSize)
{
    int defaultLength = std::strlen(defaultText);
    if (defaultLength > maxSize)
    {
        throw std::invalid_argument("defaultText is longer than maxSize");
    }
    buffer = new char[maxSize];
    std::memcpy(buffer, defaultText, defaultLength + 1);
    length = defaultLength;
    std::cout << "Constructed string with text: " << buffer << std::endl;
}

FixedString::~FixedString()
{
    std::cout << "Deconstructed string: " << buffer << std::endl;
    delete[] buffer;
}

void FixedString::append(const char* text)
{
    int textLength = std::strlen(text);
    if (length + textLength > maxSize)
    {
        throw std::overflow_error("String would exceed maximum size");
    }
    std::memcpy(buffer + length, text, textLength + 1);
    length += textLength;
}

void FixedString::appendLine(const char* text)
{
    append(text);
    append("\n");
}

void FixedString::print()
{
    std::cout << buffer;
}

const char* FixedString::getString()
{
    return buffer;
}
