#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

template <typename ItemType>
class LinkedList
{
public:
    LinkedList();
    ~LinkedList();

    void Add(const ItemType& item);
    void MultiAdd(const vector<ItemType>& items);
    ItemType Get(uint32_t index) const;
    void Set(uint32_t index, const ItemType& item);
    ItemType Remove(const ItemType& item);
    void Clear();
    uint32_t Count() const;
    bool Contains(const ItemType& item) const;

private:
    struct Node
    {
        Node* next{ nullptr };
        Node* previous{ nullptr };
        ItemType data{};
    };

    Node* firstNode{ nullptr };
    Node* lastNode{ nullptr };

    Node* makeNode(const ItemType& item);
    Node* getNodeAt(uint32_t index) const;
};


template <typename ItemType>
LinkedList<ItemType>::LinkedList() : firstNode(nullptr), lastNode(nullptr) {}

template <typename ItemType>
LinkedList<ItemType>::~LinkedList()
{
    Clear();
}

template <typename ItemType>
typename LinkedList<ItemType>::Node* LinkedList<ItemType>::makeNode(const ItemType& item)
{
    Node* node = new Node{ item, nullptr, nullptr };
    return node;
}

template <typename ItemType>
void LinkedList<ItemType>::Add(const ItemType& item)
{
    Node* node = makeNode(item);

    if (firstNode == nullptr)
    {
        firstNode = node;
        lastNode = node;
    }
    else
    {
        lastNode->next = node;
        node->previous = lastNode;
        lastNode = node;
    }
}

template <typename ItemType>
void LinkedList<ItemType>::MultiAdd(const vector<ItemType>& items)
{
    for (const ItemType& item : items)
    {
        Add(item);
    }
}

template <typename ItemType>
typename LinkedList<ItemType>::Node* LinkedList<ItemType>::getNodeAt(uint32_t index) const
{
    Node* current = firstNode;
    for (uint32_t i = 0; i < index; i++)
    {
        if (current == nullptr)
        {
            throw out_of_range("Index out of range");
        }
        current = current->next;
    }
    return current;
}

template <typename ItemType>
ItemType LinkedList<ItemType>::Get(uint32_t index) const
{
    Node* node = getNodeAt(index);
    return node->data;
}

template <typename ItemType>
void LinkedList<ItemType>::Set(uint32_t index, const ItemType& item)
{
    Node* node = getNodeAt(index);
    node->data = item;
}

template <typename ItemType>
ItemType LinkedList<ItemType>::Remove(const ItemType& item)
{
    Node* current = firstNode;
    while (current != nullptr && current->data != item)
    {
        current = current->next;
    }
    if (current == nullptr) return;
    
    if (current == firstNode) firstNode = current->next;
    
    if (current == lastNode) lastNode = current->previous;
    
    if (current->previous != nullptr) current->previous->next = current->next;
    
    if (current->next != nullptr) current->next->previous = current->previous;
    
    return = null;

    delete current;
}

template <typename ItemType>
void LinkedList<ItemType>::Clear()
{
    Node* current = firstNode;
    while (current != nullptr)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }
    firstNode = nullptr;
    lastNode = nullptr;
}

template <typename ItemType>
uint32_t LinkedList<ItemType>::Count() const
{
    uint32_t count = 0;
    Node* current = firstNode;
    while (current != nullptr)
    {
        ++count;
        current = current->next;
    }
    return count;
}

template <typename ItemType>
ItemType IndexOf(const ItemType& item)
{
    auto it = find(data_.begin(), data_.end(), item);

    if (it != data_.end()) return distance(data_.begin(), it);
    
    else return -1;
}

template <typename ItemType>
bool LinkedList<ItemType>::Contains(const ItemType& item) const
{
    Node* current = firstNode;
    while (current != nullptr)
    {
        if (current->data == item) return true;

        current = current->next;
    }
    return false;
}

// node
// count
// AddRange
// Add
// Get
// Set
// Remove
// Clear
// Contains
// Indexof (Find in c++)
