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
        void SetUpStdList()
        {
            list.Add(13);
            list.Add(5);
            list.Add(100);
            list.Add(101);
            list.Add(69);
        }

        void ClearStdList()
        {
            list.Clear();
        }

        TEST_METHOD_INITIALIZE(SetUp)
        {
            SetUpStdList();
        }

        TEST_METHOD_CLEANUP(TearDown)
        {
            ClearStdList();
        }

        TEST_METHOD(TestAddOne)
        {
            Assert::AreEqual(list.Count(), 5u, L"Size of list should be 5", LINE_INFO());
            list.Add(4);
            Assert::AreEqual(list.Count(), 6u, L"Size of list should be 6", LINE_INFO());
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