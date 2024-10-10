#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

list<int>::iterator GetIterator(list<int>::iterator it, int x)
{
    for (int i = 0; i < x; ++i, ++it);
    return it;
}

void PrintLinkedList(const list<int>& llist)
{
    for (auto l : llist)
    {
        cout << l << " -> ";
    }

    cout << "NULL" << endl;
}

int main()
{
    list<int> linkedList;

    linkedList.push_front(43);
    linkedList.push_front(76);
    linkedList.push_back(15);
    linkedList.push_back(44);

    // Print the list element
    cout << "First Printed:" << endl;
    PrintLinkedList(linkedList);
    cout << endl;

    list<int>::iterator itr = GetIterator(linkedList.begin(), 4);
    linkedList.insert(itr, 100);

    itr = GetIterator(linkedList.begin(), 3);
    linkedList.insert(itr, 48);

    linkedList.insert(linkedList.begin(), 22);
    // Print the list element
    cout << "Second Printed:" << endl;
    PrintLinkedList(linkedList);
    cout << endl;
    // Get value of the second index
    // It should be 43
    cout << "Get value of the second index:" << endl;
    itr = GetIterator(linkedList.begin(), 2);
    if (itr != linkedList.end())
        cout << *itr;
    else
        cout << "not found";
    cout << endl << endl;
    // Find the position of value 15
    // It should be found
    itr = find(linkedList.begin(), linkedList.end(), 15);
    if (itr != linkedList.end())
        cout << "Element found in linkedList: " << *itr;
    else
        cout << "Element not found in linkedList";
    cout << endl << endl;
    // Remove first element
    cout << "Remove the first element:" << endl;
    itr = linkedList.begin();
    linkedList.erase(itr);
    // 76->43->15->48->44->100->NULL
    PrintLinkedList(linkedList);
    cout << endl;
    // Remove fifth element
    cout << "Remove the fifth element:" << endl;
    itr = GetIterator(linkedList.begin(), 4);
    linkedList.erase(itr);
    // 76->43->15->48->100->NULL
    PrintLinkedList(linkedList);
    cout << endl;

    return 0;
}