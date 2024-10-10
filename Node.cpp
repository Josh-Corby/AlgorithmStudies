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

template<typename T>
void PrintNode(Node<T>* node)
{
    // It will print the initial node
    // until it finds NULL for the Next pointer
    // that indicate the end of the node chain
    while (node != NULL)
    {
        cout << node->Value << " -> ";
        node = node->Next;
    }

    cout << "NULL" << endl;
}

int main()
{
    Node<float>* node1 = new Node<float>(1.23);
    Node<float>* node2 = new Node<float>(2.34);
    Node<float>* node3 = new Node<float>(3.45);

    node1->Next = node2;
    node2->Next = node3;

    PrintNode(node1);

    return 0;
}