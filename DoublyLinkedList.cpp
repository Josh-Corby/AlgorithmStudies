#include <iostream>

using namespace std;

template <typename T>
class DoublyNode
{
public:
    T Value;
    DoublyNode<T>* Previous;
    DoublyNode<T>* Next;

    DoublyNode(T value) : Value(value), Next(NULL) {}
};

template <typename T>
class DoublyLinkedList
{
private:
    int m_count;

public:

    // The first node in the list
    DoublyNode<T>* Head;

    // The last node in the list
    DoublyNode<T>* Tail;

    // Constructor
    DoublyLinkedList();

    // Get operation
    DoublyNode<T>* Get(int index);

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

    // Additional operation
    int Count();
    void PrintList();
    void PrintListBackward();
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    m_count = 0;
    Head = nullptr;
    Tail = nullptr;
}

template <typename T>
int DoublyLinkedList<T>::Count()
{
    return m_count;
}

template <typename T>
void DoublyLinkedList<T>::PrintList()
{
    DoublyNode<T>* node = Head;

    while (node != NULL)
    {
        cout << node->Value << " -> ";
        node = node->Next;
    }

    cout << "NULL" << endl;
}

template <typename T>
void DoublyLinkedList<T>::PrintListBackward()
{
    DoublyNode<T>* node = Tail;

    while (node != NULL)
    {
        cout << node->Value << " -> ";
        node = node->Previous;
    }

    cout << "NULL" << endl;
}

template <typename T>
DoublyNode<T>* DoublyLinkedList<T>::Get(int index)
{
    // Check if the index is out of bounds
    if (index < 0 || index > m_count)
    {
        return NULL;
    }

    // Start from the head
    DoublyNode<T>* node = Head;

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
void DoublyLinkedList<T>::InsertHead(T val)
{
    // Create a new Node
    DoublyNode<T>* node = new DoublyNode<T>(val);

    // The current Head will no longer be a head
    // so the Next pointer o the new Node will
    // point to the current Head
    node->Next = Head;

    // If there is a current head,
    // the Previous pointer of the current Head
    // should point to the node
    if (Head != NULL)
        Head->Previous = node;

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
void DoublyLinkedList<T>::InsertTail(T val)
{
    // If the linked list is empty,
    // invoke InserHead()
    if (m_count == 0)
    {
        InsertHead(val);
        return;
    }

    // Create a new Node
    DoublyNode<T>* node = new DoublyNode<T>(val);

    // The current Tail will no longer be the tail
    // so the Next pointer of the current Tail will
    // be set to the new node
    Tail->Next = node;

    // Also, the previous pointer of the new node
    // should point to the current Tail
    node->Previous = Tail;

    // The new node is now the tail
    Tail = node;

    // One element has been added
    m_count++;
}

template <typename T>
void DoublyLinkedList<T>::Insert(int index, T val)
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
    DoublyNode<T>* prevNode = Head;

    // Traverse the elements until selected index is found
    for (int i = 0; i < index - 1; ++i)
    {
        prevNode = prevNode->Next;
    }

    // Create the next node which is
    // the element after the previous node
    DoublyNode<T>* nextNode = prevNode->Next;

    // Create a new node
    DoublyNode<T>* node = new DoublyNode<T>(val);

    // Insert this node between
    // the previous and the next nodes
    node->Next = nextNode;
    node->Previous = prevNode;
    prevNode->Next = node;
    nextNode->Previous = node;

    // One element is added
    m_count++;
}

template <typename T>
int DoublyLinkedList<T>::Search(T val)
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
    DoublyNode<T>* node = Head;

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
void DoublyLinkedList<T>::RemoveHead()
{
    // Do nothing if list is empty
    if (m_count == 0)
    {
        return;
    }

    // Save the current Head
    // to a new Node
    DoublyNode<T>* node = Head;

    // Point the Head Pointer
    // to the element next to the current Head
    Head = Head->Next;

    // Now it is save to remove the first element
    delete node;

    // If there's still any element in the list,
    // the previous pointer of the Head
    // should point to NULL
    if (Head != NULL)
        Head->Previous = NULL;

    // One element is removed
    m_count--;
}

template <typename T>
void DoublyLinkedList<T>::RemoveTail()
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

    // Save the current Tail
    // to a new node
    DoublyNode<T>* node = Tail;

    // Point the Tail pointer 
    // to the element before the current tail
    Tail = Tail->Previous;

    // Set the new Next pointer of the new Tail
    // to NULL since we are going to delete
    // the last element
    Tail->Next = NULL;

    // Now it's safe to remove
    // the last element
    delete node;

    // One element is removed
    m_count--;
}

template <typename T>
void DoublyLinkedList<T>::Remove(int index)
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
    DoublyNode<T>* prevNode = Head;

    // Find the selected element before
    // the selected index
    for (int i = 0; i < index - 1; ++i)
    {
        prevNode = prevNode->Next;
    }

    // The removed element is after
    // the prevNode
    DoublyNode<T>* node = prevNode->Next;

    // The nextNode will be the neighbor of
    // prevNode if the node is removed
    DoublyNode<T>* nextNode = node->Next;

    // Link the prevNode to nextNode
    prevNode->Next = nextNode;
    nextNode->Previous = prevNode;

    // It's now safe to remove
    // the selected index element
    delete node;

    // One element is removed
    m_count--;
}

int main()
{
    DoublyLinkedList<int> linkedList = DoublyLinkedList<int>();

    linkedList.InsertHead(43);
    linkedList.InsertHead(76);
    linkedList.InsertTail(15);
    linkedList.InsertTail(44);

    cout << "First Printed:" << endl;
    linkedList.PrintListBackward();

    linkedList.Insert(4, 100);
    linkedList.Insert(3, 48);
    linkedList.Insert(0, 22);

    cout << "Second Printed:" << endl;
    linkedList.PrintListBackward();

    // Get value of the second index
    // It should be 43
    cout << "Get value of the second index:" << endl;
    DoublyNode<int>* get = linkedList.Get(2);
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