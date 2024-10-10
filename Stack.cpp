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

template <typename T>
class Stack
{
private:
    int m_count;
    Node<T>* m_top;

public:
    Stack();
    bool IsEmpty();
    T Top();
    void Push(T val);
    void Pop();
};

template <typename T>
Stack<T>::Stack()
{
    m_count = 0;
    m_top = nullptr;
}

template <typename T>
bool Stack<T>::IsEmpty()
{
    return m_count <= 0;
}

template <typename T>
T Stack<T>::Top()
{
    return m_top->Value;
}

template <typename T>
void Stack<T>::Push(T val)
{
    // Create a new node
    Node<T>* node = new Node<T>(val);

    // The next pointer of this new node
    // will point to the current m_top node
    node->Next = m_top;

    // The new node is now the top
    m_top = node;

    // One item is added
    m_count++;
}

template <typename T>
void Stack<T>::Pop()
{
    // Do nothing if stack is empty
    if (IsEmpty())
    {
        return;
    }

    // Prepare the current m_top to remove
    Node<T>* node = m_top;

    // The new m_top will be the next of the current top
    m_top = node->Next;

    // It is now safe to remove the top
    delete node;

    // One item is removed
    m_count--;
}

int main()
{
    Stack<int> stackInt = Stack<int>();
    // Store several numbers to the stack
    stackInt.Push(32);
    stackInt.Push(47);
    stackInt.Push(18);
    stackInt.Push(59);
    stackInt.Push(88);
    stackInt.Push(91);
    // list the element of stack
    while (!stackInt.IsEmpty())
    {
        // Get the top element
        cout << stackInt.Top() << " - ";
        // Remove the top element
        stackInt.Pop();
    }
    cout << "END" << endl;

    return 0;
}

bool IsValid(char expression[])
{
    int n = strlen(expression);

    Stack<char> stackChar = Stack<char>();

    for (int i = 0; i < n; ++i)
    {
        // If input is open parenthesis
        // Store it in the stack
        if (expression[i] == '{')
        {
            stackChar.Push('{');
        }
        else if (expression[i] == '[')
        {
            stackChar.Push('[');
        }
        else if (expression[i] == '(')
        {
            stackChar.Push('(');
        }
        // Check when the input
        // is closed parenthesis
        else if (
            expression[i] == '}' ||
            expression[i] == ']' ||
            expression[i] == ')')
        {
            // If the stack is empty
            // or the last parenthesis is different
            // than the one we are closed,
            // then the expression is wrong
            if (expression[i] == '}' &&
                (stackChar.IsEmpty() || stackChar.Top() != '{'))
                return false;
            else if (expression[i] == ']' &&
                (stackChar.IsEmpty() || stackChar.Top() != '['))
                return false;
            else if (expression[i] == ')' &&
                (stackChar.IsEmpty() || stackChar.Top() != '('))
                return false;
            else
                stackChar.Pop();
        }
    }
    // If the stack is empty,
    // the expression is valid
    // otherwise it's invalid
    if (stackChar.IsEmpty())
    {
        return true; //
    }
    else
    {
        return false;
    }

}

int main()
{
    // Prepare array for storing
    // the expression
    char expr[1000];
    // Ask user to input the expression
    cout << "Please type the parenthesis expression ";
    cout << "then press ENTER!" << endl;
    cin >> expr;
    // Check the validity
    bool bo = IsValid(expr);
    // Notify the user
    cout << endl;
    cout << "The " << expr << " expression is ";
    if (bo)
        cout << "valid";
    else
        cout << "invalid";
    cout << endl;
    return 0;
}