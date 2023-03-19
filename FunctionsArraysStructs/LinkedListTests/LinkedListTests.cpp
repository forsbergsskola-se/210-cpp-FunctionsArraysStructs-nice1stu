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
            ClearStdList();
            Assert::AreEqual(list.Count(), 0u, L"Size of list should be 0", LINE_INFO());
        }

        TEST_METHOD(TestMultiAdd)
        {
            vector<int> items{ 0, -2, 54 };
            list.MultiAdd(items);
            Assert::AreEqual(list.Count(), 8u, L"Size of list should be 8", LINE_INFO());
        }

        TEST_METHOD(TestGetItemFromCorrectIndex)
        {
            Assert::AreEqual(list.Get(2), 100, L"Item at index 1 should be 100", LINE_INFO());
        }

        TEST_METHOD(TestSetIteminCorrectIndex)
        {
            list.Set(3, 999);
            Assert::AreEqual(list.Get(3), 999, L"Item at index 3 should be 999", LINE_INFO());
        }
    };
}