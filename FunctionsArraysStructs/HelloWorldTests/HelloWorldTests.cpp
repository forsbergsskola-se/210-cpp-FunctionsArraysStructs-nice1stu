#include "CppUnitTest.h"
#include <iostream>
#include <sstream>
#include <string>
#include "F:\Game Programming\210-cpp-FunctionsArraysStructs-nice1stu\FunctionsArraysStructs\HelloWorld\HelloWorld.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MyTest
{
    TEST_CLASS(MyTestClass)
    {
    public:
        TEST_METHOD(MyTestMethod)
        {
            std::stringstream buffer;
            std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
            std::cout << "Hello World!\n";
            std::string output = buffer.str();
            std::cout.rdbuf(old);
            Assert::AreEqual(output, std::string("Hello World!\n"));
        }
    };
}