#include "pch.h"
#include "CppUnitTest.h"
#include "../LinkedList/LinkedList.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LinkedListTest
{
    TEST_CLASS(UnitTestLinkedList)
    {
    public:
        TEST_METHOD(TestAddOne)
        {
            LinkedList<int> list;
            list.Add(1);
            Assert::AreEqual(1, list.Size(), L"Size of list should be 1", LINE_INFO());
        }

        TEST_METHOD(TestEmptyList)
        {
            LinkedList<int> list;
            Assert::AreEqual(0, list.Size(), L"Size of list should be 0", LINE_INFO());
        }
    };
}

// Setup
// TestGetValueFromCorrectIndex()
// TestSetIteminCorrectIndex()
// TestCountIsZeroAfterClear()
// TestRemoveIndexAt()
// TestContainsValueAtCorrectIndex()
// TestIndexOf()
// TestRemove()