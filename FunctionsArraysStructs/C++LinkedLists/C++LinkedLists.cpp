//C++ Linked List

#include <iostream>

using namespace std;


template <typename ItemType>
class LinkedList
{
public:
	LinkedList();
	~LinkedList();

private:
    template <typename LLElement>
    struct Node
    {
        Node<LLElement>* next;
        Node<LLElement>* previous;

        LLElement data;
    };
    Node<ItemType>* head;
};

template <typename ItemType>
LinkedList<ItemType>::LinkedList()
{
    LinkedList::head = nullptr;
}
template <typename ItemType>
LinkedList<ItemType>::~LinkedList()
{
}

int main()
{
    auto lL = new LinkedList<int>();
}

// node
// count
// AddRange
// Add
// Get
// Set
// Remove
// Clear
// IEnumeraotr?
