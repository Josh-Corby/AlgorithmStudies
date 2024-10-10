#include <iostream>

using namespace std;

class BSTNode
{
public:
    int Key;
    BSTNode* Left;
    BSTNode* Right;
    BSTNode* Parent;
    int Height;
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

class AVL : public BST
{
private:
    BSTNode* root;

    int GetHeight(BSTNode* node);
    BSTNode* RotateLeft(BSTNode* node);
    BSTNode* RotateRight(BSTNode* node);
    BSTNode* Insert(BSTNode* node, int key);
    BSTNode* Remove(BSTNode* node, int key);

public:
    AVL();

    void Insert(int v);
    void Remove(int v);
};

int AVL::GetHeight(BSTNode* node)
{
    // return the height of the node
    // or -1 is node is null
    return node == nullptr ? -1 : node->Height;
}

BSTNode* AVL::RotateLeft(BSTNode* node)
{
    // the node must have a right child(tree must be right skewed)

    // create a new node as a result
    // that will be a balanced node
    BSTNode* balancedNode = node->Right;

    // the balanced node will replace the currentnode
    balancedNode->Parent = node->Parent;

    // the current node will be child of the balanced node
    node->Parent = balancedNode;

    // the right child of current node
    // will be balanced node's left child
    node->Right = balancedNode->Left;

    // if the balanced node has a left child
    // point parent to the current node
    if (balancedNode->Left != nullptr)
    {
        balancedNode->Left->Parent = node;
    }

    // the left child of balanced node will be the current node
    balancedNode->Left = node;

    // Refresh the node's height
    node->Height = max(GetHeight(node->Left), GetHeight(node->Right)) + 1;

    // Refresh the balanced node's height
    balancedNode->Height = max(
        GetHeight(balancedNode->Left),
        GetHeight(balancedNode->Right)) + 1;

    return balancedNode;
}

BSTNode* AVL::RotateRight(BSTNode* node)
{
    // The node must have a left child(tree must be left skewed)

    // create a new node that will be
    // the balanced node
    BSTNode* balancedNode = node->Left;

    // the balanced node will replace the current node
    balancedNode->Parent = node->Parent;

    // the current node will be child of the balanced node
    node->Parent = balancedNode;

    // the left child of current node will be
    // balanced node's right child
    node->Left = balancedNode->Right;

    // if balanced node has a right child
    // point the parent to the current node
    if (balancedNode->Right != nullptr)
    {
        balancedNode->Right->Parent = node;
    }

    // The right child of balanced node will be the current node
    balancedNode->Right = node;

    // Refresh the node's height
    node->Height = max(GetHeight(node->Left), GetHeight(node->Right)) + 1;

    // Refresh balanced node's height
    balancedNode->Height = max(
        GetHeight(balancedNode->Left),
        GetHeight(balancedNode->Right)) + 1;

    return balancedNode;
}

BSTNode* AVL::Insert(BSTNode* node, int key)
{
    // if AVL tree doesnt exist
    // create new node as root
    // or if there are no child nodes
    // we can insert a node here
    if (node == nullptr)
    {
        node = new BSTNode;
        node->Key = key;
        node->Left = nullptr;
        node->Right = nullptr;
        node->Parent = nullptr;
        node->Height = 0;
    }

    // if the given key is greater than nodes key, go right
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

    // Get the balance
    int balance =
        GetHeight(node->Left) - GetHeight(node->Right);

    // if left heavy
    if (balance == 2)
    {
        // get left subtrees height
        int balance2 =
            GetHeight(node->Left->Left) -
            GetHeight(node->Left->Right);

        // left-left heavy
        if (balance2 == 1)
        {
            node = RotateRight(node);
        }
        else
        {
            // left-right heavy
            // counter right, then left
            node->Left = RotateLeft(node->Left);
            node = RotateRight(node);
        }
    }

    // If right heavy
    else if (balance == -2)
    {
        // Get right subtree's height
        int balance2 =
            GetHeight(node->Right->Left) -
            GetHeight(node->Right->Right);

        // right-right heavt
        if (balance2 == -1)
        {
            node = RotateLeft(node);
        }
        else
        { // 1
            //right-left heavt
            // counter right, than left
            node->Right = RotateRight(node->Right);
            node = RotateLeft(node);
        }
    }
    // Refresh node's height
    node->Height = std::max(
        GetHeight(node->Left),
        GetHeight(node->Right)) + 1;

    return node;
}

BSTNode* AVL::Remove(BSTNode* node, int key)
{
    // The given node is
    // not found in AVL tree
    if (node == NULL)
    {
        return NULL;
    }
    // Target node is found
    if (node->Key == key)
    {
        // If the node is a leaf node
        // The node can be safely removed
        if (node->Left == NULL && node->Right == NULL)
        {
            node = NULL;
        }
        // The node have only one child at right
        else if (node->Left == NULL && node->Right != NULL)
        {
            // The only child will be connected to
            // the parent's of node directly
            node->Right->Parent = node->Parent;
            // Bypass node
            node = node->Right;
        }
        // The node have only one child at left
        else if (node->Left != NULL && node->Right == NULL)
        {
            // The only child will be connected to
            // the parent's of node directly
            node->Left->Parent = node->Parent;
            // Bypass node
            node = node->Left;
        }
        // The node have two children (left and right)
        else
        {
            // Find successor or predecessor to avoid quarrel
            int successorKey = Successor(key);
            // Replace node's key with successor's key
            node->Key = successorKey;
            // Delete the old successor's key
            node->Right = Remove(node->Right, successorKey);
        }
    }
    // Target node's key is smaller than
    // the given key then search to right
    else if (node->Key < key)
    {
        node->Right = Remove(node->Right, key);
    }
    // Target node's key is greater than
    // the given key then search to left
    else
    {
        node->Left = Remove(node->Left, key);
    }
    // Only perform rotation if node is not NULL
    if (node != NULL)
    {
        // Get the balance
        int balance =
            GetHeight(node->Left) - GetHeight(node->Right);
        // If left heavy
        if (balance == 2)
        {
            // Get left subtree's height
            int balance2 =
                GetHeight(node->Left->Left) -
                GetHeight(node->Left->Right);
            if (balance2 == 1)
            {
                node = RotateRight(node);
            }
            else
            {
                node->Left = RotateLeft(node->Left);
                node = RotateRight(node);
            }
        }
        // If right heavy
        else if (balance == -2)
        {
            // Get right subtree's height
            int balance2 =
                GetHeight(node->Right->Left) -
                GetHeight(node->Right->Right);
            if (balance2 == -1)
            {
                node = RotateLeft(node);
            }
            else
            { // 1
                node->Right = RotateRight(node->Right);
                node = RotateLeft(node);
            }
        }
        // Refresh node's height
        node->Height = std::max(
            GetHeight(node->Left),
            GetHeight(node->Right)) + 1;
    }
    // Return the updated AVL tree
    return node;
}


int main()
{
    return 0;
}