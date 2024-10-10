#include <iostream>

using namespace std;

class List
{
private:
    int m_count;
    int* m_items;

public:
    List();
    ~List();
    int Get(int index);
    void Insert(int index, int val);
    int Search(int val);
    void Remove(int index);
    int Count();
};

List::List()
{
    m_count = 0;
    m_items = nullptr;
}

List::~List()
{
    delete[] m_items;
}

int List::Count()
{
    return m_count;
}

int List::Get(int index)
{
    // Check if the index is out of bounds
    if (index < 0 || index > m_count)
    {
        return -1;
    }

    return m_items[index];
}

void List::Insert(int index, int val)
{
    // Check if the index is out of bounds
    if (index < 0 || index > m_count)
    {
        return;
    }

    // Copy the current array
    int* oldArray = m_items;

    m_count++;

    // Initialize a new array
    m_items = new int[m_count];

    // Fill the new array with the inserted data
    for (int i = 0, j = 0; i < m_count; ++i)
    {
        if (index == i)
        {
            m_items[i] = val;
        }
        else
        {
            m_items[i] = oldArray[j];
            ++j;
        }
    }

    // Remove copied array
    delete[] oldArray;
}

int List::Search(int val)
{
    // Looping through the array elements
    // return the array index if value is found
    for (int i = 0; i < m_count; ++i)
    {
        if (m_items[i] == val)
        {
            return i;
        }
    }

    return -1;
}

void List::Remove(int index)
{
    // Check if the index is out of bounds
    if (index < 0 || index > m_count)
    {
        return;
    }

    // Copy the current array
    int* oldArray = m_items;

    // Decrease the array length
    m_count--;

    // Initialize a new Array
    m_items = new int[m_count];

    // Fill the new array
    // and remove the selected index
    for (int i = 0, j = 0; i < m_count; ++i, ++j)
    {
        if (index == j)
        {
            ++j;
        }

        m_items[i] = oldArray[j];
    }

    // Remove copied array
    delete[] oldArray;
}

int main()
{

    // Initialize a List
    List list = List();

    // Add several items to the List
    list.Insert(0, 21);
    list.Insert(1, 47);
    list.Insert(2, 87);
    list.Insert(3, 35);
    list.Insert(4, 92);

    // Print current List
    cout << "List elements:" << endl;
    for (int i = 0; i < list.Count(); ++i)
    {
        cout << list.Get(i) << " ";
    }

    cout << endl << endl;

    // Insert several items in the middle of the list
    list.Insert(2, 25);
    list.Insert(2, 71);

    // Print the new List again
    cout << "New List elements:" << endl;
    for (int i = 0; i < list.Count(); ++i)
    {
        cout << list.Get(i) << " ";
    }

    cout << endl << endl;

    // Search value 71
    cout << "Search element 71" << endl;
    int result = list.Search(71);
    if (result == -1)
        cout << "71 is not found";
    else
        cout << "71 is found at index " << result;

    cout << endl << endl;

    // Remove index 2
    cout << "Remove element at index 2" << endl;
    list.Remove(2);
    cout << endl;
    // Print the List again
    cout << "New List elements:" << endl;
    for (int i = 0; i < list.Count(); ++i)
    {
        cout << list.Get(i) << " ";
    }

    cout << endl << endl;

    // Search value 71 again
    cout << "Search element 71 again" << endl;
    result = list.Search(71);
    if (result == -1)
        cout << "71 is not found";
    else
        cout << "71 is found at index " << result;
    cout << endl;

    return 0;
}