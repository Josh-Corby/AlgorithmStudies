#include <iostream>
#include <cstring>

using namespace std;

template <typename T>
class DoublyNode
{
public:
    T Value;
    DoublyNode<T>* Next;
    DoublyNode<T>* Previous;

    DoublyNode(T value) :
        Value(value),
        Next(nullptr),
        Previous(nullptr)
    {
    }
};

template <typename T>
class Deque
{
private:
    int m_count;
    DoublyNode<T>* m_front;
    DoublyNode<T>* m_back;

public:
    Deque();
    bool IsEmpty();
    T Front();
    T Back();
    void EnqueueFront(T val);
    void EnqueueBack(T val);
    void DequeueFront();
    void DequeueBack();
};

template <typename T>
Deque<T>::Deque()
{
    m_count = 0;
    m_front = nullptr;
    m_back = nullptr;
}

bool Deque::isEmpty()
{
    return false;
}

template <typename T>
bool Deque<T>::IsEmpty()
{
    return m_count <= 0;
}

template <typename T>
T Deque<T>::Front()
{
    return m_front->Value;
}

template <typename T>
T Deque<T>::Back()
{
    return m_back->Value;
}

template <typename T>
void Deque<T>::EnqueueFront(T val)
{
    // Make new node
    DoublyNode<T>* node = new DoublyNode<T>(val);

    // new node next is old front
    node->Next = m_front;

    //if there is currently a front
    if (m_front != nullptr)
    {
        // old front previous is new node
        m_front->Previous = node;
    }

    // new node is now front
    m_front = node;

    // if the deque is emtpy
    // then m_back is also m_front
    if (m_count == 0)
    {
        m_back = m_front;
    }

    // one element added
    m_count++;
}

template <typename T>
void Deque<T>::EnqueueBack(T val)
{
    // if the deque is empty
    // invoke EnqueueFront
    if (m_count == 0)
    {
        EnqueueFront(val);
        return;
    }

    // make new Node
    DoublyNode<T>* node = new DoublyNode<T>(val);

    // current back next points to new node
    m_back->Next = node;

    // new node previous points to current back
    node->Previous = m_back;

    // new node is now back
    m_back = node;

    // one element added
    m_count++;
}

template <typename T>
void Deque<T>::DequeueFront()
{
    // Do nothing if queue is empty
    if (m_count == 0)
    {
        return;
    }

    // store current front
    DoublyNode<T>* node = m_front;

    // Set front to next of current front
    m_front = m_front->Next;

    // clear old front
    delete node;

    if (m_front != nullptr)
    {
        m_front->Previous = nullptr;
    }

    m_count--;
}

template <typename T>
void Deque<T>::DequeueBack()
{
    // Do nothing if queue is empty
    if (m_count == 0)
    {
        return;
    }

    // if there is only one element
    // call dequeue front
    if (m_count == 1)
    {
        DequeueFront();
        return;
    }

    // store current back
    DoublyNode<T>* node = m_back;

    // set back to previous of current back
    m_back = m_back->Previous;

    // Set the next of new back to null
    m_back->Next = nullptr;

    // clear of back
    delete node;

    m_count--;
}

int main()
{
    // NULL
    Deque<int> deque = Deque<int>();
    // Enqueue several numbers to the deque
    // 26
    deque.EnqueueFront(26);
    // 26 - 78
    deque.EnqueueBack(78);
    // 26 - 78 - 44
    deque.EnqueueBack(44);
    // 91 - 26 - 78 - 44
    deque.EnqueueFront(91);
    // 35 - 91 - 26 - 78 - 44
    deque.EnqueueFront(35);
    // 35 - 91 - 26 - 78 - 44 - 12
    deque.EnqueueBack(12);
    // list the element of queue
    while (!deque.IsEmpty())
    {
        // Get the front element
        cout << deque.Back() << " - ";
        // Remove the front element
        deque.DequeueBack();
    }
    cout << "END" << endl;

    return 0;
}