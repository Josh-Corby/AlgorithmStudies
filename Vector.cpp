#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> vectorList;
    vectorList.push_back(35);
    vectorList.push_back(41);
    vectorList.push_back(94);

    int i = vectorList.at(1);
    int j = vectorList[0];

    vector<int>::iterator itr;
    itr = vectorList.begin();
    vectorList.insert(itr, 58);

    itr = vectorList.end();
    vectorList.insert(itr, 37);

    itr = vectorList.begin();
    vectorList.insert(itr + 3, 67);

    // Search 41 element
    // It should be found
    itr = find(vectorList.begin(), vectorList.end(), 41);
    if (itr != vectorList.end())
    {
        cout << "Element found in vectorList: " << *itr;
    }
    else
    {
        cout << "Element not found in vectorList";
    }

    cout << endl << endl;

    // Remove the 2nd element
    itr = vectorList.begin();
    vectorList.erase(itr + 1);



}