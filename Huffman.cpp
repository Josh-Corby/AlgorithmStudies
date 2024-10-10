#include <iostream>
#include <queue>

using namespace std;

class MinHeapNode
{
public:
    // Input character
    char Data;

    // Frequency of the character
    unsigned Frequency;

    // Left and right child
    MinHeapNode* LeftChild;
    MinHeapNode* RightChild;

    // Constructor
    MinHeapNode(char data, unsigned freq)
    {
        // Initialize left and right child
        LeftChild = nullptr;
        RightChild = nullptr;

        Data = data;
        Frequency = freq;
    }
};

class compare
{
public:
    bool operator()(MinHeapNode* left, MinHeapNode* right)
    {
        return(left->Frequency > right->Frequency);
    }
};

void PrintCodes(MinHeapNode* root, string str)
{
    if (root == nullptr)
    {
        return;
    }

    if (root->Data != '$')
    {
        cout << root->Data << ": ";
        cout << str << endl;
    }

    PrintCodes(root->LeftChild, str + "0");
    PrintCodes(root->RightChild, str + "1");
}

void HuffmanCodes(char data[], int freq[], int dataSize)
{
    MinHeapNode* left;
    MinHeapNode* right;
    MinHeapNode* top;

    // Create a min heap & insert all characters of data[]
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

    for (int i = 0; i < dataSize; ++i)
    {
        minHeap.push(new MinHeapNode(data[i], freq[i]));
    }

    // Iterate while size of heap doesn't become 1
    while (minHeap.size() != 1)
    {
        // Extract the two minimum
        // freq items from minHeap
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        // Create a new internal node with
        // frequency equal to the sum of the
        // two nodes frequencies. Make the
        // two extracted node as left and right children
        // of this new node. Add this node
        // to the min heap '$' is a special value
        // for internal nodes, not used
        top = new MinHeapNode(
            '$', left->Frequency + right->Frequency);

        top->LeftChild = left;
        top->RightChild = right;

        minHeap.push(top);
    }

    // Print huffman code using
    // the huffman tree
    PrintCodes(minHeap.top(), "");
}

int main()
{

}