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
    Node<ItemType>* tail;

    Node<ItemType>* makeNode(const ItemType &item);

public:

    void Add(const ItemType &item);
    void Remove(const ItemType &item); //TODO

    uint64_t size();

    LinkedList();

};

template <typename ItemType>
LinkedList<ItemType>::LinkedList()
{
    head = nullptr;
}

//Add
template <typename ItemType>
void LinkedList<ItemType>::Add(const ItemType &item)
{
    auto node = makeNode(item);

    if (this->head == nullptr || this->tail == nullptr)
    {
        head = node;
        tail = node;
    }
    else
    {
        tail->next = node;
        node->previous = tail;
        tail = node;
    }
}

template <typename ItemType>
LinkedList<ItemType>::Node<ItemType> *LinkedList<ItemType>::makeNode(const ItemType &item)
{
    auto node = new Node();
    node->data = item;
    node->next = nullptr;
    node->previous = nullptr;
    return node;
}

//count
template <typename ItemType>
uint64_t LinkedList<ItemType>::size()
{
    return 0;
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
