#include <iostream>
#include <list>

using namespace std;

#define TABLE_SIZE 7

class HashTable
{
private:
    list<pair<int, string>> tableList[TABLE_SIZE];

    int HashFunction(int key);

public:
    HashTable();

    void Insert(int key, string value);
    string Search(int key);
    void Remove(int key);
    bool IsEmpty();
};

HashTable::HashTable()
{

}

int HashTable::HashFunction(int key)
{
    return key % TABLE_SIZE;
}

void HashTable::Insert(int key, string value)
{
    bool isKeyFound = false;

    // Get hash key from hash function
    int hashKey = HashFunction(key);

    // Iterate through chaining node (linked list)
    // in selected cell
    for (auto& keyValue : tableList[hashKey])
    {
        // if the key is found
        // update the data
        if (keyValue.first == key)
        {
            isKeyFound = true;
            keyValue.second = value;
        }
    }

    // If key is not found
    // append at the back
    if (!isKeyFound)
    {
        tableList[hashKey].emplace_back(key, value);
    }
}

string HashTable::Search(int key)
{
    // Get hash key from hash function
    int hashKey = HashFunction(key);

    // Iterate through chaining node (linked list)
    // in selected cell
    for (auto& keyValue : tableList[hashKey])
    {
        // if the key is found
        // return the value of name
        if (keyValue.first == key)
        {
            return keyValue.second;
        }
    }

    // if we get here no key was found
    // return empty string
    return "";
}

void HashTable::Remove(int key)
{
    // Get hash key from hash function
    int hashKey = HashFunction(key);

    // Get the cell
    auto& cell = tableList[hashKey];

    // Traverse the chaining node (linked list)
    for (auto it = cell.begin(); it != cell.end(); ++it)
    {
        // if the key is found
        // delete the list's element
        if (it->first == key)
        {
            cell.erase(it);
            break;
        }
    }
}

bool HashTable::IsEmpty()
{
    // Initialize total element
    int totalElement = 0;

    // Count all elements in table hash
    for (int i = 0; i < TABLE_SIZE; ++i)
    {
        totalElement += (int)tableList[i].size();
        // if the total element is not zero
        // the hash table must not be empty
        if (totalElement > 0)
        {
            return false;
        }
    }

    // if this statement is reached
    // the table is empty
    return true;
}

int main()
{
    HashTable* hashTable = new HashTable();

    // Check if hash table is empty
    bool b = hashTable->IsEmpty();
    if (b)
        cout << "Hash table is empty";
    else
        cout << "Hash table is not empty";
    cout << endl;

    // Adding a data then
    // check if hash table is empty
    cout << "Adding a data" << endl;
    hashTable->Insert(434, "Dylan");
    b = hashTable->IsEmpty();
    if (b)
        cout << "Hash table is empty";
    else
        cout << "Hash table is not empty";
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
    hashTable->Remove(key); name = hashTable->Search(key);
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