#include "pch.h"
#include "CppUnitTest.h"
#include "D:\Game Programming\210-cpp-FunctionsArraysStructs-nice1stu\FunctionsArraysStructs\StringClassExercise\StringClassExercise.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringClassExerciseTests
{
    TEST_CLASS(StringClassExerciseTests)
    {
    public:

        TEST_METHOD(TestDefaultConstructor)
        {
            StringClassExercise str;
            Assert::AreEqual("", str.getString());
        }

        TEST_METHOD(TestSizeConstructor)
        {
            StringClassExercise str(10);
            Assert::AreEqual("", str.getString());
        }
    };
}
