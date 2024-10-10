#include <iostream>
#include <list>

using namespace std;

#define TABLE_SIZE 7

class HashElement
{
public:
    int Key;
    string Value;

    HashElement(int key, string value)
    {
        Key = key;
        Value = value;
    }
};

class HashTable
{
private:
    int currentSize;
    HashElement** arr;
    HashElement* deletedElement;

    int HashFunction(int key);

public:
    HashTable();

    void Insert(int key, string value);
    string Search(int key);
    void Remove(int key);
    bool IsEmpty();
    void PrintHashTable();
};

HashTable::HashTable()
{
    // Initialize current size to 0
    currentSize = 0;

    // Initialize table
    arr = new HashElement * [TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; ++i)
    {
        arr[i] = nullptr;
    }

    // Specify deleted node conted
    deletedElement = new HashElement(-1, "");
}

int HashTable::HashFunction(int key)
{
    return key % TABLE_SIZE;
}

void HashTable::Insert(int key, string value)
{
    // It's impossible to store a new element
    // if hash table doesnt have free space
    if (currentSize >= TABLE_SIZE)
    {
        return;
    }

    // Create a temporary element
    // to be inserted
    HashElement* temp = new HashElement(key, value);

    // Get hash key from hash function
    int hashIndex = HashFunction(key);

    // Find next free space
    // using linear probing
    while (arr[hashIndex] != nullptr &&
        arr[hashIndex]->Key != key &&
        arr[hashIndex]->Key != -1)
    {
        ++hashIndex;
        hashIndex %= TABLE_SIZE;
    }

    // if there is a new element to be inserted
    // then increase the current size
    if (arr[hashIndex] == nullptr ||
        arr[hashIndex]->Key == -1)
    {
        ++currentSize;
        arr[hashIndex] = temp;
    }
}

string HashTable::Search(int key)
{
    // Get hash key from hash function
    int hashIndex = HashFunction(key);

    // Find the element with given key
    while ((arr[hashIndex] != nullptr) &&
        arr[hashIndex]->Key != deletedElement->Key)
    {
        // if element is found
        // return its value
        if (arr[hashIndex]->Key == key)
        {
            return arr[hashIndex]->Value;
        }

        // Keep looking for the key
        // using linear probing
        ++hashIndex;
        hashIndex &= TABLE_SIZE;
    }

    // element not found
    return "";
}

void HashTable::Remove(int key)
{
    // Get hash key from hash function
    int hashIndex = HashFunction(key);

    // find the element with given key
    while (arr[hashIndex] != nullptr &&
        arr[hashIndex]->Key != deletedElement->Key)
    {
        // if element is found
        // then mark the cell as deleted element
        if (arr[hashIndex]->Key == key)
        {
            arr[hashIndex] = deletedElement;

            // reduce current size
            --currentSize;

            // no need to search anymore
            return;
        }

        // keep looking for the key
        // using linear probing
        ++hashIndex;
        hashIndex %= TABLE_SIZE;
    }
}

bool HashTable::IsEmpty()
{
    return currentSize == 0;
}

void HashTable::PrintHashTable()
{
    // Iterate through array
    for (int i = 0; i < currentSize; ++i)
    {
        // print the element
        // if it exists
        if (arr[i] != nullptr && arr[i]->Key != -1)
        {
            cout << "Cell: " << i;
            cout << " Key: " << arr[i]->Key;
            cout << " Value: " << arr[i]->Value;
            cout << std::endl;
        }
    }
}

int main()
{
    cout << "Hash Table - Open Addressing - Linear Probe";
    cout << endl;
    HashTable* hashTable = new HashTable();

    // Check if hash table is empty
    bool b = hashTable->IsEmpty();
    if (b)
    {
        cout << "Hash table is empty";
    }
    else
    {
        cout << "Hash table is not empty";
    }
    cout << endl;

    // Adding a data then
    // check if hash table is empty
    cout << "Adding a data" << endl;
    hashTable->Insert(434, "Dylan");
    b = hashTable->IsEmpty();
    if (b)
    {
        cout << "Hash table is empty";
    }
    else
    {
        cout << "Hash table is not empty";
    }
    cout << endl;

    // Adding others data
    hashTable->Insert(391, "Dominic");
    hashTable->Insert(806, "Adam");
    hashTable->Insert(117, "Lindsey");
    hashTable->Insert(548, "Cameron");
    hashTable->Insert(669, "Terry");
    hashTable->Insert(722, "Brynn");
    hashTable->Insert(276, "Jody");
    hashTable->Insert(953, "Frankie");
    hashTable->Insert(895, "Vanessa");

    // Print the table
    hashTable->PrintHashTable();

    // Search key 669
    // it should be found
    int key = 669;
    cout << "Search value for key ";
    cout << key << endl;
    string name = hashTable->Search(key);
    if (name != "")
    {
        cout << "Value for key " << key;
        cout << " is " << name;
    }
    else
    {
        cout << "Value for key " << key;
        cout << " is not found";
    }
    cout << endl;

    // Remove key 669
    // then search the key
    // it should not be found
    cout << "Remove node of key ";
    cout << key << endl;
    hashTable->Remove(key);

    name = hashTable->Search(key);
    if (name != "")
    {
        cout << "Value for key " << key;
        cout << " is " << name;
    }
    else
    {
        cout << "Value for key " << key;
        cout << " is not found";
    }
    cout << endl;

    return 0;
}