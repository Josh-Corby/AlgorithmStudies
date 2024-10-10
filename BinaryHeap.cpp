#include <iostream>
#include <vector>

using namespace std;

class BinaryHeap
{
private:
    vector<int> vec;
    int heapSize;

    // three helper navigation functions
    int parent(int i) { return i >> 1; }        // i/2
    int left(int i) { return i << 1; }        // i*2
    int right(int i) { return (i >> 1) + 1; }    // i*2 + 1

    void ShiftUp(int index);
    void ShiftDown(int index);

public:
    BinaryHeap();

    bool IsEmpty();
    void Insert(int key);
    int ExtractMax();
    int GetMax();
};

bool BinaryHeap::IsEmpty()
{
    return heapSize == 0;
}

void BinaryHeap::ShiftUp(int index)
{
    // Do nothing in root
    if (index == 1)
    {
        return;
    }

    if (vec[index] > vec[parent(index)])
    {
        // Swap upwards
        swap(vec[index], vec[parent(index)]);

        // Recurse until root
        ShiftUp(parent(index));
    }
}

void BinaryHeap::Insert(int key)
{
    // Add a new element in vector
    if (heapSize + 1 >= int(vec.size()))
    {
        vec.push_back(0);

        // store the key in the last position of vector
        vec[++heapSize] = key;

        // Shift upwards
        ShiftUp(heapSize);
    }
}

int BinaryHeap::GetMax()
{
    // Return root's key
    return vec[1];
}

void BinaryHeap::ShiftDown(int index)
{
    // For non-existing index
    // do nothing
    if (index > heapSize)
    {
        return;
    }

    // Initialize swapId
    int swapId = index;

    // Compare with left child, if exists
    if (left(index) <= heapSize && vec[index] < vec[left(index)])
    {
        swapId = left(index);
    }

    // Compare with right child, if exists
    if (right(index) <= heapSize && vec[swapId] < vec[right(index)])
    {
        swapId = right(index);
    }

    // Swap with the larger of the two children
    if (swapId != index)
    {
        // Swap downwards with the larger
        // of the two children
        swap(vec[index], vec[swapId]);

        // Recurse until the index
        ShiftDown(swapId);
    }
}

int BinaryHeap::ExtractMax()
{
    // Maximum value is in root
    int maxVal = vec[1];

    // Swap with the last existing leaf
    swap(vec[1], vec[heapSize - 1]);

    // Fix heap property downwards
    ShiftDown(1);

    // return the maximum value
    return maxVal;
}

int main()
{
    return 0;
}