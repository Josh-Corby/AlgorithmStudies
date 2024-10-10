#include <iostream>

using namespace std;

class BSTNode
{
public:
    int Key;
    BSTNode* Left;
    BSTNode* Right;
    BSTNode* Parent;
};

class BST
{
private:
    BSTNode* root;

protected:
    BSTNode* Insert(BSTNode* node, int key);
    void PrintTreeInOrder(BSTNode* node);
    BSTNode* Search(BSTNode* node, int key);
    int FindMin(BSTNode* node);
    int FindMax(BSTNode* node);
    int Successor(BSTNode* node);
    int Predecessor(BSTNode* node);
    BSTNode* Remove(BSTNode* node, int val);

public:
    BST();

    void Insert(int key);
    void PrintTreeInOrder();
    bool Search(int key);
    int FindMin();
    int FindMax();
    int Successor(int key);
    int Predecessor(int key);
    void Remove(int y);
};

BST::BST()
{
    root = nullptr;
}

BSTNode* BST::Insert(BSTNode* node, int key)
{
    // If BST doesn't exist, create a new node at root
    // Of node has no children, insert node
    if (node == nullptr)
    {
        node = new BSTNode;
        node->Key = key;
        node->Left = nullptr;
        node->Right = nullptr;
        node->Parent = nullptr;
    }

    // if given key is greater than nodes key, go right
    else if (node->Key < key)
    {
        node->Right = Insert(node->Right, key);
        node->Right->Parent = node;
    }

    // if smaller, go left
    else
    {
        node->Left = Insert(node->Left, key);
        node->Left->Parent = node;
    }

    return node;
}

void BST::Insert(int key)
{
    // Invoke Insert() function
    // passing in root node and give key
    root = Insert(root, key);
}

void BST::PrintTreeInOrder(BSTNode* node)
{
    // stop printing if there is no nodes
    if (node == nullptr)
    {
        return;
    }

    // Get the smallest key first
    // which is in the left subtree
    PrintTreeInOrder(node->Left);

    // print the key
    cout << node->Key << " ";

    // Continue to the greatest key
    // which is on the right subtree
    PrintTreeInOrder(node->Right);
}

void BST::PrintTreeInOrder()
{
    PrintTreeInOrder(root);
    cout << endl;
}

BSTNode* BST::Search(BSTNode* node, int key)
{
    // if no nodes, exit
    if (node == nullptr)
    {
        return nullptr;
    }

    // the given key is found
    else if (node->Key == key)
    {
        return node;
    }

    // the given key is greater than nodes key
    else if (node->Key < key)
    {
        return Search(node->Right, key);
    }

    // The given key is smaller
    else
    {
        return Search(node->Left, key);
    }
}

bool BST::Search(int key)
{
    // Invoke search passing in root and key
    BSTNode* result = Search(root, key);

    return result == nullptr ? false : true;
}

int BST::FindMin(BSTNode* node)
{
    if (node == nullptr)
    {
        return -1;
    }
    else if (node->Left == nullptr)
    {
        return node->Key;
    }
    else
    {
        return FindMin(node->Left);
    }
}

int BST::FindMax(BSTNode* node)
{
    if (node == nullptr)
    {
        return -1;
    }
    else if (node->Right == nullptr)
    {
        return node->Key;
    }
    else
    {
        return FindMax(node->Right);
    }
}

int BST::FindMin()
{
    return FindMin(root);
}

int BST::FindMax()
{
    return FindMax(root);
}

int BST::Successor(BSTNode* node)
{
    // The successor is the minimum key value
    // of the rights subtree
    if (node->Right != nullptr)
    {
        return FindMin(node->Right);
    }
    // if no right subtree
    else
    {
        BSTNode* parentNode = node->Parent;
        BSTNode* currentNode = node;

        // If currentNode is not root and
        // currentNode is right of parent
        // continue moving up
        while ((parentNode != nullptr) &&
            (currentNode == parentNode->Right))
        {
            currentNode = parentNode;
            parentNode = currentNode->Parent;
        }

        // if parentNode is not null
        // than the key of parentnode is
        // the successor of node
        return parentNode == nullptr ? -1 : parentNode->Key;
    }
}

int BST::Successor(int key)
{
    // Search the key's node first
    BSTNode* keyNode = Search(root, key);

    // if key is not found, return -1
    return keyNode == nullptr ? -1 : Successor(keyNode);
}

int BST::Predecessor(BSTNode* node)
{
    // The predecessor is the maximum key value
    // of left subtree
    if (node->Left != nullptr)
    {
        return FindMax(node->Left);
    }
    // if no left subtree
    else
    {
        BSTNode* parentNode = node->Parent;
        BSTNode* currentNode = node;

        // if currentNode is not root and
        // currentNode is left of parent
        // keep moving up
        while ((parentNode != nullptr) &&
            (currentNode == parentNode->Left))
        {
            currentNode = parentNode;
            parentNode = currentNode->Parent;
        }

        // if parentNode is not null
        // than the key of parentNode
        // is the predecessor
        return parentNode == nullptr ? -1 : parentNode->Key;
    }
}

int BST::Predecessor(int key)
{
    // Search the key's node first
    BSTNode* keyNode = Search(root, key);

    // if key is not found return -1
    // otherwise return predecessor
    return keyNode == nullptr ? -1 : Predecessor(keyNode);
}

BSTNode* BST::Remove(BSTNode* node, int key)
{
    // the given node is not in bst
    if (node == nullptr)
    {
        return nullptr;
    }

    // target node is found
    if (node->Key == key)
    {
        // if the node is a leaf node
        //the node can be safely removed
        if (node->Left == nullptr && node->Right == nullptr)
        {
            node = nullptr;
        }

        // The node has only one child on right
        else if (node->Left == nullptr && node->Right != nullptr)
        {
            // the only child will be connected directly
            node->Right->Parent = node->Parent;

            // bypass node
            node = node->Right;
        }
        // The node has only one child on left
        else if (node->Left != nullptr && node->Right == nullptr)
        {
            // the only child will be connected directly
            node->Left->Parent = node->Parent;

            // bypass node
            node = node->Left;
        }
        // The node has two children(left and right)
        else
        {
            // Find successor or predecessor to avoid quarrel
            int successorKey = Successor(key);

            // Replace node's key with successor's key
            node->Key = successorKey;

            // Delete old successor's key
            node->Right = Remove(node->Right, successorKey);
        }
    }

    // Target node's key is smaller than
    // the given key, then search right
    else if (node->Key < key)
    {
        node->Right = Remove(node->Right, key);
    }

    // Targets node is greater
    else
    {
        node->Left = Remove(node->Left, key);
    }

    // return updated BST
    return node;
}

void BST::Remove(int key)
{
    root = Remove(root, key);
}

int main()
{
    BST* tree = new BST;

    // define keys
    int keys[] = { 23, 12, 31, 3, 15, 7, 29, 88, 53 };

    // insert keys
    for (const int& key : keys)
    {
        tree->Insert(key);
    }

    // traverse tree in order, then print all keys
    cout << "Tree keys: ";
    tree->PrintTreeInOrder();

    // Search key 31
    // it should be found
    cout << "Search key 31: ";
    bool b = tree->Search(31);
    if (b)
    {
        cout << "found";
    }
    else
    {
        cout << "NOT found";
    }
    cout << endl;

    // Search key 18
    // it should NOT be found
    cout << "Search key 18: ";
    b = tree->Search(18);
    if (b)
    {
        cout << "found";
    }
    else
    {
        cout << "NOT found";
    }
    cout << endl;

    // Retrieving minimum and maximum key
    cout << "Min. Key : " << tree->FindMin();
    cout << endl;
    cout << "Max. Key : " << tree->FindMax();
    cout << endl;

    // Finding successor
    // Successor(31) should be 53
    // Successor(15) should be 23
    // Successor(88) should be -1 or NULL
    cout << "Successor(31) = ";
    cout << tree->Successor(31) << endl;
    cout << "Successor(15) = ";
    cout << tree->Successor(15) << endl;
    cout << "Successor(88) = ";
    cout << tree->Successor(88) << endl;
    // Finding predecessor
    // Predecessor(12) should be 7
    // Predecessor(29) should be 23
    // Predecessor(3) should be -1 or NULL
    cout << "Predecessor(12) = ";
    cout << tree->Predecessor(12) << endl;
    cout << "Predecessor(29) = ";
    cout << tree->Predecessor(29) << endl;
    cout << "Predecessor(3) = ";
    cout << tree->Predecessor(3) << endl;

    // Removing a key
    cout << "Removing key 15" << endl;
    tree->Remove(15);
    cout << "Removing key 53" << endl;
    tree->Remove(53);

    // Printing all keys again
    // Key 15 and 53 should be disappeared
    cout << "Tree keys: ";
    tree->PrintTreeInOrder();

    return 0;
}