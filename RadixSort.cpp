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

void RadixSort(int arr[], int arrSize)
{
    // Create ten buckets for each digit
    Queue<int>* buckets = new Queue<int>[10];

    // Find the largest element
    int largestElement = arr[0];
    for (int i = 0; i < arrSize; ++i)
    {
        if (largestElement < arr[i])
        {
            largestElement = arr[i];
        }
    }

    // Iterate through every digit
    // using exponential (10^exp) to find the digit
    for (int exp = 1; largestElement / exp > 1; exp *= 10)
    {
        // Iterate through the array's elements
        for (int i = 0; i < arrSize; ++i)
        {
            // Move element into respective bucket
            buckets[(arr[i] / exp) % 10].Enqueue(arr[i]);
        }

        // Reconstruct the array starting from
        // the smallest digit in the buckets
        // Reset the array counter before reconstructing
        int arrCounter = 0;
        for (int i = 0; i < 10; ++i)
        {
            // Get all elements from the buckets
            while (!buckets[i].IsEmpty())
            {
                // Get the front element
                // then restore element to array
                arr[arrCounter++] = buckets[i].Front();

                // Remove the front element
                buckets[i].Dequeue();
            }
        }
    }

    return;
}

int main()
{
    cout << "Radix Sort" << endl;
    // Initialize a new array

    int arr[] = { 429, 3309, 65, 7439, 12, 9954, 30, 4567, 8, 882 };
    int arrSize = sizeof(arr) / sizeof(*arr);

    // Display the initial array
    cout << "Initial array: ";
    for (int i = 0; i < arrSize; ++i)
        cout << arr[i] << " ";
    cout << endl;

    // Sort the array with QuickSort algorithm
    RadixSort(arr, arrSize);

    // Display the sorted array
    cout << "Sorted array : ";
    for (int i = 0; i < arrSize; ++i)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}