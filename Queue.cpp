#include <iostream>
#include <cstring>

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
class Queue
{
private:
    int m_count;
    Node<T>* m_front;
    Node<T>* m_back;

public:
    Queue();
    bool IsEmpty();
    T Front();
    void Enqueue(T val);
    void Dequeue();
};

template <typename T>
Queue<T>::Queue()
{
    m_count = 0;
    m_front = nullptr;
    m_back = nullptr;
}

template <typename T>
bool Queue<T>::IsEmpty()
{
    return m_count <= 0;
}

template <typename T>
T Queue<T>::Front()
{
    return m_front->Value;
}

template <typename T>
void Queue<T>::Enqueue(T val)
{
    // Create a new Node
    Node<T>* node = new Node<T>(val);

    if (m_count == 0)
    {
        // If the queue is empty
        // The new node will be
        // m_front and m_back
        node->Next = nullptr;
        m_front = node;
        m_back = node;
    }
    else
    {
        // If there is at least one element
        // in the queue the current m_back element wont
        // be the back anymore
        // so the next of the current m_back 
        // will point to the new node
        m_back->Next = node;

        // The new node is now the back
        m_back = node;
    }

    // One element was added
    m_count++;
}

template <typename T>
void Queue<T>::Dequeue()
{
    // Do nothing if list is empty
    if (m_count == 0)
    {
        return;
    }

    // Save the current front node
    Node<T>* node = m_front;

    // front is now what the front was pointing to
    m_front = node->Next;

    // It is now safe to delete old front
    delete node;

    // One element was removed
    m_count--;
}

int main()
{
    // NULL
    Queue<int> queueInt = Queue<int>();

    // Enqueue several numbers to the queue
    queueInt.Enqueue(35);
    queueInt.Enqueue(91);
    queueInt.Enqueue(26);
    queueInt.Enqueue(78);
    queueInt.Enqueue(44);
    queueInt.Enqueue(12);

    // list the element of queue
    while (!queueInt.IsEmpty())
    {
        // Get the front element
        cout << queueInt.Front() << " - ";

        // Remove the front element
        queueInt.Dequeue();
    }

    cout << "END" << endl;
    return 0;
}