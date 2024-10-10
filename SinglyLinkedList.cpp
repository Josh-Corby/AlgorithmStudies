#include <iostream>

using namespace std;

template <typename T>
class Node
{
public:
    T Value;
    Node<T>* Next;

    Node(T value) : Value(value), Next(NULL) {}
};

template <typename T>
class LinkedList
{
private:
    int m_count;

public:

    // The first node in the list
    Node<T>* Head;

    // The last node in the list
    Node<T>* Tail;

    // Constructor
    LinkedList();

    // Get operation
    Node<T>* Get(int index);

    // Insert operation
    void InsertHead(T val);
    void InsertTail(T val);
    void Insert(int index, T val);

    // Search operation
    int Search(T val);

    // Remove operation
    void RemoveHead();
    void RemoveTail();
    void Remove(int index);

    int Count();
    void PrintList();
};

template <typename T>
LinkedList<T>::LinkedList()
{
    m_count = 0;
    Head = nullptr;
    Tail = nullptr;
}

template <typename T>
int LinkedList<T>::Count()
{
    return m_count;
}

template <typename T>
void LinkedList<T>::PrintList()
{
    Node<T>* node = Head;

    while (node != NULL)
    {
        cout << node->Value << " -> ";
        node = node->Next;
    }

    cout << "NULL" << endl;
}

template <typename T>
Node<T>* LinkedList<T>::Get(int index)
{
    // Check if the index is out of bounds
    if (index < 0 || index > m_count)
    {
        return NULL;
    }

    // Start from the head
    Node<T>* node = Head;

    // Iterate through the linked list elements
    // until it finds the selected index
    for (int i = 0; i < index; ++i)
    {
        node = node->Next;
    }

    // return the node result
    return node;
}

template <typename T>
void LinkedList<T>::InsertHead(T val)
{
    // Create a new Node
    Node<T>* node = new Node<T>(val);

    // The current Head will no longer be a head
    // so the Next pointer o the new Node will
    // point to the current Head
    node->Next = Head;

    // The new Node is now the head
    Head = node;

    // If the linked list is empty
    // The tail is now also the head
    if (m_count == 0)
    {
        Tail = Head;
    }

    // One element has been added
    m_count++;
}

template <typename T>
void LinkedList<T>::InsertTail(T val)
{
    // If the linked list is empty,
    // invoke InserHead()
    if (m_count == 0)
    {
        InsertHead(val);
        return;
    }

    // Create a new Node
    Node<T>* node = new Node<T>(val);

    // The current Tail will no longer be the tail
    // so the Next pointer of the current Tail will
    // be set to the new node
    Tail->Next = node;

    // The new node is now the tail
    Tail = node;

    // One element has been added
    m_count++;
}

template <typename T>
void LinkedList<T>::Insert(int index, T val)
{
    // Check if the index is out of bounds
    if (index < 0 || index > m_count)
    {
        return;
    }

    // If inserting a new Head
    if (index == 0)
    {
        InsertHead(val);
        return;
    }

    // If inserting a new Tail
    else if (index == m_count)
    {
        InsertTail(val);
        return;
    }

    // Start to find previous node from the head
    Node<T>* prevNode = Head;

    // Traverse the elements until selected index is found
    for (int i = 0; i < index - 1; ++i)
    {
        prevNode = prevNode->Next;
    }

    // Create the next node which is
    // the element after the previous node
    Node<T>* nextNode = prevNode->Next;

    // Create a new node
    Node<T>* node = new Node<T>(val);

    // Insert this node between
    // the previous and the next nodes
    node->Next = nextNode;
    prevNode->Next = node;

    // One element is added
    m_count++;
}

template <typename T>
int LinkedList<T>::Search(T val)
{
    // If LinkedList is empty,
    // just return NOT_FOUND
    if (m_count == 0)
    {
        return -1;
    }

    // Need to count the index
    int index = 0;

    // Traverse from head;
    Node<T>* node = Head;

    // Traverse until the selected value
    // matches the value of the current position
    while (node->Value != val)
    {
        index++;
        node = node->Next;

        // This will happen
        // if the selected value
        // is not found
        if (node == NULL)
        {
            return -1;
        }
    }

    return index;
}

template <typename T>
void LinkedList<T>::RemoveHead()
{
    // Do nothing if list is empty
    if (m_count == 0)
    {
        return;
    }

    // Save the current Head
    // to a new Node
    Node<T>* node = Head;

    // Point the Head Pointer
    // to the element next to the current Head
    Head = Head->Next;

    // Now it is save to remove the first element
    delete node;

    // One element is removed
    m_count--;
}

template <typename T>
void LinkedList<T>::RemoveTail()
{
    // Do nothing if list is empty
    if (m_count == 0)
    {
        return;
    }

    // If List element is only one
    // call RemoveHead()
    if (m_count == 1)
    {
        RemoveHead();
        return;
    }

    // Start to find previous node from the head
    Node<T>* prevNode = Head;

    // This is the candidate of
    // removed items which is
    // the element next to the prevNode
    Node<T>* node = Head->Next;

    // Traverse the elements until the last element
    while (node->Next != NULL)
    {
        prevNode = prevNode->Next;
        node = node->Next;
    }

    // The prevNode now becomes the tail
    // So the next pointer of the prevNode
    // points to NULL
    prevNode->Next = NULL;
    Tail = prevNode;

    // Now it's safe to remove
    // the last element
    delete node;

    // One element is removed
    m_count--;
}

template <typename T>
void LinkedList<T>::Remove(int index)
{
    // Do nothing if the list is empty
    if (m_count == 0)
    {
        return;
    }

    // Do nothing if the index is out of bounds
    if (index < 0 || index >= m_count)
    {
        return;
    }

    // If removing the current Head
    if (index == 0)
    {
        RemoveHead();
        return;
    }

    // If removing the current Tail
    if (index == m_count - 1)
    {
        RemoveTail();
        return;
    }

    // Start to traverse the list
    // from the head
    Node<T>* prevNode = Head;

    // Find the selected element before
    // the selected index
    for (int i = 0; i < index - 1; ++i)
    {
        prevNode = prevNode->Next;
    }

    // The removed element is after
    // the prevNode
    Node<T>* node = prevNode->Next;

    // The nextNode will be the neighbor of
    // prevNode if the node is removed
    Node<T>* nextNode = node->Next;

    // Link the prevNode to nextNode
    prevNode->Next = nextNode;

    // It's now safe to remove
    // the selected index element
    delete node;

    // One element is removed
    m_count--;
}

int main()
{
    LinkedList<int> linkedList = LinkedList<int>();

    linkedList.InsertHead(43);
    linkedList.InsertHead(76);
    linkedList.InsertTail(15);
    linkedList.InsertTail(44);

    cout << "First Printed:" << endl;
    linkedList.PrintList();

    linkedList.Insert(4, 100);
    linkedList.Insert(3, 48);
    linkedList.Insert(0, 22);

    cout << "Second Printed:" << endl;
    linkedList.PrintList();

    // Get value of the second index
    // It should be 43
    cout << "Get value of the second index:" << endl;
    Node<int>* get = linkedList.Get(2);
    if (get != NULL)
    {
        cout << get->Value;
    }

    else
    {
        cout << "not found";
    }
    cout << endl << endl;

    // Find the position of value 15
    // It must be 3
    cout << "The position of value 15:" << endl;
    int srch = linkedList.Search(15);
    cout << srch << endl << endl;

    // Remove first element
    cout << "Remove the first element:" << endl;
    linkedList.Remove(0);

    linkedList.PrintList();
    cout << endl;

    // Remove fifth element
    cout << "Remove the fifth element:" << endl;
    linkedList.Remove(4);

    linkedList.PrintList();
    cout << endl;

    // Remove tenth element
    cout << "Remove the tenth element:" << endl;
    linkedList.Remove(9);

    // Nothing happen
    linkedList.PrintList();
    cout << endl;

    return 0;
}