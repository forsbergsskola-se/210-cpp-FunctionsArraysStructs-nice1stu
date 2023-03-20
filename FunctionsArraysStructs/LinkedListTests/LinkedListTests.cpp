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
using namespace std;

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
            Assert::AreEqual(list.Count(), 5u, L"List size should be 5", LINE_INFO());
            list.Add(4);
            Assert::AreEqual(list.Count(), 6u, L"List size should be 6", LINE_INFO());
        }

        TEST_METHOD(TestEmptyList)
        {
            ClearStdList();
            Assert::AreEqual(list.Count(), 0u, L"List size should be 0", LINE_INFO());
        }

        TEST_METHOD(TestMultiAdd)
        {
            vector<int> items{ 0, -2, 54 };
            list.MultiAdd(items);
            Assert::AreEqual(list.Count(), 8u, L"List size should be 8", LINE_INFO());
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

        TEST_METHOD(TestCountIsZeroAfterClear)
        {
            list.Clear();
            Assert::AreEqual(list.Count(), 0u, L"List size should be 0", LINE_INFO());
        }

        TEST_METHOD(TestRemoveIndexAt)
        {
            list.Remove(1);
            Assert::AreEqual(list.Count(), 4u, L"List size should be 4", LINE_INFO());
            Assert::AreEqual(list.Get(1), 101, L"Item at index 1 should be 101", LINE_INFO());
        }

        TEST_METHOD(TestContainsValueAtCorrectIndex)
        {
            Assert::IsTrue(list.Contains(5), L"List should contain 5", LINE_INFO());
            Assert::IsFalse(list.Contains(4), L"List should not contain 4", LINE_INFO());
        }

        TEST_METHOD(TestIndexOf)
        {
            std::vector<int> list = { 1, 2, 3, 4, 5 };
            auto it = std::find(list.begin(), list.end(), 0);
            Assert::AreEqual(distance(list.begin(), it), 13, L"Index of 0 should be 13", LINE_INFO());

            it = std::find(list.begin(), list.end(), 2);
            Assert::AreEqual(distance(list.begin(), it), 100, L"Index of 100 should be 2", LINE_INFO());

            it = std::find(list.begin(), list.end(), 4);
            Assert::AreEqual(distance(list.begin(), it), -1, L"Index of 4 should be -1", LINE_INFO());
        }

        TEST_METHOD(TestRemove)
        {
            Assert::IsTrue(list.Remove(2), L"Item 2 should be removed", LINE_INFO());
            Assert::AreEqual(list.Count(), 4u, L"Size of list should be 4", LINE_INFO());
            Assert::AreEqual(list.Get(1), 101, L"Item at index 1 should be 101", LINE_INFO());
            Assert::IsFalse(list.Remove(4), L"Item 4 should not be removed", LINE_INFO());
        }
    };
}