// Setup
// TestGetValueFromCorrectIndex()
// TestSetIteminCorrectIndex()
// TestCountIsZeroAfterClear()
// TestRemoveIndexAt()
// TestContainsValueAtCorrectIndex()
// TestIndexOf()
// TestRemove()

#include "pch.h"
#include "CppUnitTest.h"
#include "../LinkedList/LinkedList.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LinkedListTest
{
    TEST_CLASS(UnitTestLinkedList)
    {
    private:
        LinkedList<int> list;

    public:
        void SetUpStdList(SetUp)
        {
            list.Add(1);
            list.Add(2);
            list.Add(3);
        }


        TEST_METHOD(TestAddOne)
        {
            Assert::AreEqual(list.Count(), 3u, L"Size of list should be 3", LINE_INFO());
            list.Add(4);
            Assert::AreEqual(list.Count(), 4u, L"Size of list should be 4", LINE_INFO());
        }

        TEST_METHOD(TestEmptyList)
        {
            list.Clear();
            Assert::AreEqual(list.Count(), 0u, L"Size of list should be 0", LINE_INFO());
        }

        TEST_METHOD(TestMultiAdd)
        {
            LinkedList<int> list;
            vector<int> items{ 1, 2, 3 };
            list.MultiAdd(items);
            Assert::AreEqual(list.Count(), 3u, L"Size of list should be 3", LINE_INFO());
        }

        TEST_METHOD(TestGetItemFromCorrectIndex)
        {
            LinkedList<int> list;
            list.Add(1);
            list.Add(2);
            list.Add(3);
            Assert::AreEqual(list.Get(1), 2, L"Item at index 1 should be 2", LINE_INFO());
        }

        TEST_METHOD(TestSetIteminCorrectIndex)
        {
            LinkedList<int> list;
            list.Add(1);
            list.Add(2);
            list.Add(3);
            list.Set(1, 4);
            Assert::AreEqual(list.Get(1), 4, L"Item at index 1 should be 4", LINE_INFO());
        }

        TEST_METHOD(TestSetIteminCorrectIndex)
        {
            LinkedList<int> list;
            list.Add(1);
            list.Add(2);
            list.Add(3);
            list.Set(1, 4);
            Assert::AreEqual(list.Get(1), 4, L"Item at index 1 should be 4", LINE_INFO());
        }
    };
}