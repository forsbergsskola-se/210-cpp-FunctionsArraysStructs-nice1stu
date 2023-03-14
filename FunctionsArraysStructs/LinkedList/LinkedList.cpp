//C++ Linked List
#include <iostream>

using namespace std;

template <typename ItemType>
class LinkedList
{
public:
    LinkedList();
    ~LinkedList();

    void Add(const ItemType& item);
    void Remove(const ItemType& item);
    uint64_t size();

private:
    struct Node
    {
        Node* next;
        Node* previous;
        ItemType data;
    };

    Node* head;
    Node* tail;

    Node* makeNode(const ItemType& item);
};

template <typename ItemType>
LinkedList<ItemType>::LinkedList()
{
    head = nullptr;
    tail = nullptr;
}

template <typename ItemType>
LinkedList<ItemType>::~LinkedList()
{
    Node* current = head;
    while (current != nullptr)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

template <typename ItemType>
typename LinkedList<ItemType>::Node* LinkedList<ItemType>::makeNode(const ItemType& item)
{
    Node* node = new Node;
    node->data = item;
    node->next = nullptr;
    node->previous = nullptr;
    return node;
}

template <typename ItemType>
void LinkedList<ItemType>::Add(const ItemType& item)
{
    Node* node = makeNode(item);

    if (head == nullptr)
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
void LinkedList<ItemType>::Remove(const ItemType& item)
{
    // TODO: Implement Remove function
}

template <typename ItemType>
uint64_t LinkedList<ItemType>::size()
{
    uint64_t count = 0;
    Node* current = head;
    while (current != nullptr)
    {
        count++;
        current = current->next;
    }
    return count;
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
