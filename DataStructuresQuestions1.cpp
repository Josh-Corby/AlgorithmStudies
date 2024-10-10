#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node
{
	int Value;
	Node* Next;

    Node() : Value(-1), Next(nullptr);
	Node(int val) : Value(val), Next(nullptr);
};

// Linked List
// Q1: Implement a function to reverse a singly linked list in-place.
// 
// 1->2->3->4->5
// 1<-2<-3<-4<-5

class LinkedList
{
public:
    Node* Head;
    Node* Tail;

    LinkedList();

    void InsertHead(int val);
    void InsertTail(int val);

    void MergeLists(Node* list2Node);

    void ReverseList();
    void PrintList();
};

LinkedList::LinkedList()
{
    Head = nullptr;
    Tail = nullptr;
}

void LinkedList::InsertHead(int val)
{
    // Create new node
    Node* node = new Node(val);

    node->Next = Head;

    if (!Head)
    {
        Tail = node;
    }

    // Assign new head
    Head = node;
}

void LinkedList::InsertTail(int val)
{
    // if no head, inserthead
    if (!Head)
    {
        InsertHead(val);
        return;
    }

    // create new node
    Node* node = new Node(val);

    Tail->Next = node;

    Tail = node;
}

void LinkedList::ReverseList()
{
    Node* prevNode = Head;
    Node* currNode = Head->Next;
    Node* nextNode = currNode->Next;

    Head->Next = nullptr;

    while (currNode != nullptr)
    {
        currNode->Next = prevNode;

        prevNode = currNode;
        currNode = nextNode;

        if (nextNode != nullptr)
        {
            nextNode = nextNode->Next;
        }
    }

    Head = Tail;
}

void LinkedList::PrintList()
{
    Node* node = Head;

    while (node != nullptr)
    {
        cout << node->Value << " -> ";
        node = node->Next;
    }

    cout << "nullptr" << endl;
}

int main()
{
    LinkedList linkedList = LinkedList();

    linkedList.InsertHead(1);
    linkedList.InsertTail(2);
    linkedList.InsertTail(3);
    linkedList.InsertTail(4);
    linkedList.InsertTail(5);

    cout << "Forward list:" << endl;
    linkedList.PrintList();

    cout << endl;

    linkedList.ReverseList();

    cout << "Reversed list:" << endl;
    linkedList.PrintList();
}

// Q2: Merge two sorted linked lists into a single sorted linked list.
// 1->3->5->7->9
// 2->4->6->8->10
// 1->2->3->4->5->6->7->8->9->10

void LinkedList::MergeLists(Node* list2Node)
{
    // use a dummy node to handle edge case
    // of list2 nodes smaller than head
    Node dummyNode;
    dummyNode.Next = Head;

    // pointers for traversal
    Node* prevNode = &dummyNode;
    Node* currNode = Head;

    // while there is a list1 node to compare to, and a list 2 node to insert
    while (currNode != nullptr && list2Node != nullptr)
    {
        // list2 node is smaller than list1 node
        // sorted position has been found
        if (list2Node->Value < currNode->Value)
        {
            // insert node into list
            prevNode->Next = list2Node;

            // traverse list2
            list2Node = list2Node->Next;

            // set prev node to list2 node
            prevNode = prevNode->Next;

            // point list2 node to curr node
            prevNode->Next = currNode;
        }
        else
        {
            // sorted position has not been found
            // traverse list 1
            prevNode = currNode;
            currNode = currNode->Next;
        }
    }

    // if list2 still has node, append them to list1
    if (list2Node != nullptr)
    {
        prevNode->Next = list2Node;
    }

    // update head of list to new head
    Head = dummyNode.Next;
}

int main()
{
    LinkedList linkedList = LinkedList();

    linkedList.InsertHead(1);
    linkedList.InsertTail(3);
    linkedList.InsertTail(5);
    linkedList.InsertTail(7);
    linkedList.InsertTail(9);

    LinkedList linkedList2 = LinkedList();
    linkedList2.InsertHead(2);
    linkedList2.InsertTail(4);
    linkedList2.InsertTail(6);
    linkedList2.InsertTail(8);
    linkedList2.InsertTail(10);

    linkedList.MergeLists(linkedList2.Head);
}

// Doubly Linked List
class DoublyNode
{
public:
    int Value;
    DoublyNode* Prev;
    DoublyNode* Next;

    DoublyNode(int val) : Value(val), Prev(nullptr), Next(nullptr) {}
};

class DoublyLinkedList
{
    DoublyNode* Head;
    DoublyNode* Tail;

    DoublyLinkedList();

    void InsertHead(int val);
    void InsertTail(int val);
};

DoublyLinkedList::DoublyLinkedList()
{
    Head = nullptr;
    Tail = nullptr;
}

DoublyLinkedList::InsertHead(int val)
{
    // create head
    DoublyNode* node = new DoublyNode(val);

    node->Prev = Head;

    bool bHadHead = Head;
    if (bHadHead)
    {
        Head->Next = node;
    }

    Head = node;

    if (!bHadHead)
    {
        Tail = Head;
    }
}

DoublyLinkedList::InsertTail(int val)
{
    if (!Head)
    {
        InsertHead(val);
    }

    // Create new node
    DoublyNode* node = new DoublyNode(val);

    node->Prev = Tail;
    Tail->Next = node;
    Tail = node;
}

// Q1: Implement a LRU (Least Recently Used) cache using a doubly linked list and a hash map.
struct Node
{
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int k, int v) :
        key(k), value(v), prev(nullptr), next(nullptr)
    {
    }
};

class LRUCache
{
private:

    int capacity;
    unordered_map<int, Node*> cache;
    Node* Head;
    Node* Tail;

    void Remove(Node* node);
    void InsertHead(Node* node);

public:
    LRUCache(int cap) :
        capacity(cap), Head(nullptr), Tail(nullptr)
    {
    }

    ~LRUCache();

    int Get(int key);
    void Insert(int key, int value);
};

void LRUCache::Remove(Node* node)
{
    if (node == nullptr)
    {
        return;
    }

    Node* currNode = node;

    if (node->prev)
    {
        node->prev->next = node->next;
    }
    else
    {
        Head = node->next;
    }
    if (node->next)
    {
        node->next->prev = node->next;
    }
    else
    {
        Tail = node->prev;
    }

    delete currNode;
}

void LRUCache::InsertHead(Node* node)
{
    node->next = Head;
    node->prev = nullptr;
    if (Head)
    {
        Head->prev = node;
    }
    Head = node;
    if (!Tail)
    {
        Tail = Head;
    }
}

int LRUCache::Get(int key)
{
    if (cache.find(key) == cache.end())
    {
        return -1; // key not found
    }

    Node* node = cache[key];
    Remove(node);
    InsertHead(node);
    return node->value;
}

void LRUCache::Insert(int key, int value)
{
    if (cache.find(key) != cache.end())
    {
        // if the key already exists, update the value
        // and move it to the front
        Node* node = cache[key];
        node->value = value;
        Remove(node);
        InsertHead(node);
    }
    else
        // if cache is at capacity
        // remove LRU (tail)
    {
        if (cache.size() == capacity)
        {
            cache.erase(Tail->key);
            Remove(Tail);
        }

        // create a new node and add it to
        // front of list
        Node* node = new Node(key, value);
        InsertHead(node);
        cache[key] = node;
    }
}

LRUCache::~LRUCache()
{
    while (Head)
    {
        Node* temp = Head;
        Head = Head->next;
        delete temp;
    }
}

// Q2: Design a music player playlist with the ability to move forward, backward, and delete songs.
class Song: public DoublyNode
{
public:
    string Name;
};

class MusicPlayer 
{
public:
    Song* CurrentSong;
    Song* Head;
    Song* Tail;

    MusicPlayer();

    void AddSong(Song* song);

    Song* PrevSong();
    Song* NextSong();

    void DeleteHead();
    void DeleteTail();
    void DeleteSong();
}

MusicPlayer::MusicPlayer()
{
    CurrentSong = nullptr;
    Head = nullptr;
    Tail = nullptr;
}

void MusicPlayer::AddSong(Song* song)
{
    // if no songs currently
    if (!Head)
    {
        // add new song to list as head
        Head = song;
        Tail = Head;
        song->Prev = nullptr;
        song->Next = nullptr;
        return;
    }

    // add song to end of playlist

    // old tail points to song
    Tail->Next = song;
    song->Prev = Tail;
    song->Next = nullptr;
    Tail = song;
}

Song* MusicPlayer::PrevSong()
{
    CurrentSong = CurrentSong->Prev;
    return CurrentSong;
}

Song* MusicPlayer::NextSong()
{
    CurrentSong = CurrentSong->Next;
    return CurrentSong;
}

void MusicPlayer::DeleteHead()
{
    if (!Head)
    {
        return;
    }

    // store song to delete
    Song* song = Head;

    // assign new head
    Head = Head->Next;

    delete song;

    if (Head)
    {
        Head->Prev = nullptr;
    }
}

void MusicPlayer::DeleteTail()
{
    if (!Head)
    {
        return;
    }

    if (Tail == Head)
    {
        DeleteHead();
        return;
    }

    // store song to delete
    Song* song = Tail;

    // assign new tail
    Tail = song->Prev;

    // clear new tail->Next
    Tail->Next = nullptr;

    delete song;
}

void MusicPlayer::DeleteSong(Song* song)
{
    // fill the gap
    song->Prev->Next = currSong->Next;
    song->Next->Prev = currSong->Prev;

    // delete song
    delete song;
}

int main()
{
    MusicPlayer musicPlayer;

    return 0;
}
// Circular Linked List
// Q1: Implement a round-robin scheduler for processes using a circular linked list.
// 
class Process
{
public:
    string Name;
    int RemainingTime;
    Process* Next;

    Process(string name, int time) : Name(name), RemainingTime(time), Next(nullptr) {}
};

class RoundRobinScheduler
{
public:
    Process* Head;
    Process* Tail;
    int TimeSlice;
    int TimeRemainingInSlice;

    RoundRobinScheduler(int ts) : Head(nullptr), Tail(nullptr), TimeSlice(ts) {}

    void AddProcess(string name, int time);

    void RunSchedule();
    
private:
    void AddProcess(Process process);
    void RemoveProcess(Process* process);
};

void RoundRobinScheduler::AddProcess(string name, int time)
{
    Process* process = new Process(name, time);
    AddProcess(process);
}

void RoundRobinScheduler::AddProcess(Process process)
{
    // if scheduler is empty
    if (!Head)
    {
        Head = process;
        Tail = process;

        Head->Next = Head;
    }
    else
    {
        Tail->Next = process;
        Tail = process;
        Tail->Next = Head;
    }
}

void RoundRobinScheduler::RemoveProcess(Process* process)
{
    // if deleting head
    if(process == Head)
    {
        Head = Head->Next;
        Tail->Next = Head; 
    }

    // if deleting tail
    else if(process == Tail)
    {
        // iterate through list to process before tail
        process* prevProcess = Head;
        while (prevProcess->Next != Tail)
        {
            prevProcess = prevProcess->Next;
        }

        // assign new tail
        Tail = prevProcess;
        prevProcess->Next = Head;
    }

    delete process;
}

void RoundRobinScheduler::RunSchedule()
{
    if (!Head)
    {
        return;
    }

    // run current process
    Process* current = head;

    while (current)
    {
        // 1. subtract time left in slice from current task
        // 2. store how much time is left if slice
        // 2. if task is out of time
        // 4. iterate to next task
        // 5. remove task from schedule
        

        // 1.
        current->RemainingTime -= TimeRemainingInSlice;
        int remainingTimeInTask = current->RemainingTime;

        // 2.
        TimeRemainingInSlice = remainingTimeInTask < 0 ? (remainingTimeInTask * -1) : TimeSlice;

        // 3.
        if (current->RemainingTime <= 0)
        {
            // store process to delete
            Process* processToDelete = current;
            // 4. assign new current task
            current = current->Next;

            // 5. delete previous task from schedule
            RemoveProcess(processToDelete);
        }
    }
}


// Q2: Detect if a given linked list is circular and find the starting point of the loop.
Node* DetectAndFindCycleHead(Node* head)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    Node* slow = Head;
    Node* fast = Head;

    // step 1: detect cycle
    while (fast != nullptr && fast->Next != nullptr)
    {
        slow = slow->Next;
        fast = fast->Next->Next;

        // cycle detected
        if (slow == fast)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->Next;
                fast = fast->Next;
            }

            return slow;
        }
    }

    return nullptr;
}


// Doubly Circular Linked List
// Q1: Implement a text editor's undo-redo functionality using a doubly circular linked list.

class TextEditor
{
public:
    DoublyNode* Current;
    DoublyNode* Head;
    DoublyNode* Tail;

    TextEditor() : Current(nullptr), Head(nullptr), Tail(nullptr) {}

    void AddState(int newState);
    int Undo();
    int Redo();
};

void TextEditor::AddState(int newState)
{
    DoublyNode* node = new DoublyNode(newState);

    // add state to start of list
    if (!Head)
    {
        Head = node;
        Head->Next = Head;
        Head->Prev = Head;
        Current = Head;
    }

    // insert new node at head of list
    else
    {
        node->Prev = Current;
        node->Next = Head;
        Current->Next = node;
        Head->Prev = node;
    }

    Current = node;
}

int TextEditor::Undo()
{
    if (!Current)
    {
        return -1;
    }

    int text = Current->Value;
    Current = Current->Prev;
    return text;
}

int TextEditor::Redo()
{
    if (!Current)
    {
        return -1;
    }

    Current = Current->Next;
    return Current->Value;
}

int main()
{
    TextEditor actions;

    actions.AddState(3);
    actions.AddState(5);
    cout << actions.Undo() << endl;

    actions.AddState(4);
    cout << actions.Undo() << endl;
    cout << actions.Undo() << endl;

    cout << actions.Redo() << endl;
    cout << actions.Redo() << endl;

    return 0;
}

// 
// Q2: Design a playlist with repeat functionality (both for single song and entire playlist).
enum eLoopType
{
    none,
    song,
    playlist
};

class Playlist
{
public:
    Song* CurrentSong;
    Song* Head;
    Song* Tail;

    eLoopType LoopType;

    Playlist();

    void AddSong(Song* song);

    Song* PrevSong();
    Song* NextSong();

    void DeleteHead();
    void DeleteTail();
    void DeleteSong();

    void SetLoopType(eLoopType loopType)
    {
        LoopType = loopType;
    }
}

Playlist::Playlist()
{
    CurrentSong = nullptr;
    Head = nullptr;
    Tail = nullptr;
}

void Playlist::AddSong(Song* song)
{
    // if no songs currently
    if (!Head)
    {
        // add new song to list as head
        Head = song;
        Tail = Head;
        song->Prev = nullptr;
        song->Next = nullptr;
        return;
    }

    // add song to end of playlist

    // old tail points to song
    Tail->Next = song;
    song->Prev = Tail;
    song->Next = nullptr;
    Tail = song;
}

Song* Playlist::PrevSong()
{
    if (LoopType == song)
    {
        return CurrentSong;
    }

    if (CurrentSong == Head)
    {
        if (LoopType == none)
        {
            return nullptr;
        }
    }

    // base case
    return CurrentSong->Prev;
}

Song* Playlist::NextSong()
{
    if (LoopType == song)
    {
        return CurrentSong;
    }

    if (CurrentSong == Tail)
    {
        if (LoopType == none)
        {
            return nullptr;
        }
    }

    // base case
    CurrentSong = CurrentSong->Next;
}

void Playlist::DeleteHead()
{
    if (!Head)
    {
        return;
    }

    // store song to delete
    Song* song = Head;

    // assign new head
    Head = Head->Next;

    delete song;

    if (Head)
    {
        Head->Prev = nullptr;
    }
}

void Playlist::DeleteTail()
{
    if (!Head)
    {
        return;
    }

    if (Tail == Head)
    {
        DeleteHead();
        return;
    }

    // store song to delete
    Song* song = Tail;

    // assign new tail
    Tail = song->Prev;

    // clear new tail->Next
    Tail->Next = nullptr;

    delete song;
}

void Playlist::DeleteSong(Song* song)
{
    // fill the gap
    song->Prev->Next = currSong->Next;
    song->Next->Prev = currSong->Prev;

    // delete song
    delete song;
}

// Stack
// Q1: Implement a function to evaluate postfix expressions using a stack.

// LIFO
class Stack
{
    Node* m_Top;

    Stack() : m_Top(nullptr) {}

    void Input(string input);

    void Push(int val);
    void Pop();
    int Top();
};

void Stack::Input(string input)
{
    if (isdigit(input))
    {
        Push(stoi(input));
    }

    else
    {
        int val1 = Pop();
        int val2 = Pop();

        switch (input)
        {
        case '+':
            Push(val2 + val1);
            break;
        case'-':
            Push(val2 - val1);
            break;
        case '*':
            Push(val2 * val1);
            break;
        case '/':
            Push(val2 / val1);
            break;
        }
    }
}

Stack::Push(int val)
{
    // create new node
    Node* node = new Node(val);

    node->Next = m_top;
    m_Top = node;
}

Stack::Pop()
{
    if (!m_Top)
    {
        return;
    }
    // store node to delete
    Node* node = m_top;

    m_Top = node->Next;

    delete node;
}

int Stack::Top()
{
    if (!m_Top)
    {
        return -1;
    }

    return m_Top->Value;
}

// Q2: Design a min stack that supports push, pop, top, and retrieving the minimum element in constant time.

class minStackNode
{
    int Value;
    minStackNode* Next;
    minStackNode* Min;

    minStackNode(int val) : Value(val), Next(nullptr), Min(nullptr) {}
};

class MinStack
{
    minStackNode* Head;

    MinStack() : Head(nullptr) {}

    void Push(int val);
    void Pop();
    int Top();
    int GetMin();
}

void MinStack::Push(int val)
{
    // create new node
    minStackNode* node = new minStackNode(val);

    if (!Head)
    {
        Head = node;
        node->Min = node;
    }
    else
    {
        node->Min = node->Value < Head->Min ? node->Value : Head->Min;
        node->Next = Head;

        Head = node;
    }
}

void MinStack::Pop()
{
    if (!Head)
    {
        return;
    }

    // hold node to delete
    minStackNode* node = Head;

    // set new head
    Head = node->Next;

    // delete old head
    delete node;
}

int MinStack::Top()
{
    return Head->Value;
}

int MinStack::GetMin()
{
    return Head->Min;
}

// Queue
// Q1: Implement a task scheduler using a priority queue.
#include <queue>

class Task
{
public:
    string Name;
    int Priority;

    Task(string name, int priority) : Name(name), Priority(priority) {}

    bool operator<(const Task& other) const
    {
        return Priority < other.Priority;
    }
};
class TaskScheduler
{
    priority_queue<Task> taskQueue;

    TaskScheduler();

    void AddTask(const string& taskName, int taskPriority);
    void ExecuteTask();
    bool HasTasks();
};

TaskScheduler::AddTask(const string& taskName, int taskPriority)
{
    Task newTask = new Task(taskName, taskPriority);
    taskQueue.push(newTask);
}

void TaskScheduler::ExecuteTask()
{
    if (taskQueue.empty())
    {
        return;
    }

    taskQueue.pop();
}

bool TaskScheduler::HasTasks()
{
    return !taskQueue.empty();
}

// 
// Q2: Design a circular queue with dynamic resizing.
class CircularQueue
{
    int front;
    int rear;

    int* arr;
    int size;

    CircularQueue(int s)
    {
        front = rear = -1;
        size = s;
        arr = new int[s];
    }

    void Enqueue(int val);
    void Dequeue();
    void Resize(int newSize);

    int Front() const;
    int Rear() const;
};

void CircularQueue::Enqueue(int val)
{
    if ((front == 0 && rear == size - 1) || ((rear + 1) % size == front))
    {
        cout << "Queue is full";
        return;
    }

    // insert first element
    else if (front == -1)
    {
        front = rear = 0;
        arr[rear] = value;
    } 

    else if (rear == size - 1 && front != 0)
    {
        rear = 0;
        arr[rear] = val;
    }

    else
    {
        rear++;
        arr[rear] = val;
    }
}

void CircularQueue::Dequeue()
{
    //queue is empty
    if (front == -1)
    {
        cout << "Queue is empty"
        return;
    }
    int data = arr[front];
    arr[front] = -1;
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }

    else if (front == size - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}

void CircularQueue::Resize(int newSize)
{
    // make new array
    int* newArr = new int[newSize];

    // copy elements from old array
    int j = 0;

    // no wrapping
    if (front <= rear)
    {
        for (int i = 0; i < newSize; ++i)
        {
            newArr[j++] = arr[i];
        }
    } // wrapping
    else
    {
        // populate from front-size
        for (int i = front; i < size; ++i)
        {
            newArr[j++] arr[i];
        }
        // populate from 0-rear
        for (int i = 0; i <= rear; ++i)
        {
            newArr[j++] = arr[i];
        }
    }

    front = 0;
    rear j - 1;

    // delete old array
    delete[] arr;
    arr = newArr;
    size = newSize;
}

int CircularQueue::Front() const
{
    if (front == -1)
    {
        cout << "Queue is empty" << endl;
        return -1;
    }
    return arr[front];
}

int CircularQueue::Rear() const
{
    if (rear == -1)
    {
        cout << "Queue is empty" << endl;
        return -1;
    }
    return arr[rear];
}

// Deque (Double-ended Queue)
// Q1: Implement a sliding window maximum algorithm using a deque.
void PrintMax(const vector<int>& array, int windowSize)
{
    deque<int> deque(windowSize);

    // process first window
    int i;
    for (i = 0; i < windowSize; ++i)
    {
        // for every element, previous smaller elements are useless
        // remove them from deque
        while (!deque.empty() && array[i] >= array[deque.back()])
        {
            // remove from back of deque
            deque.pop_back();
        }
        // add new element at rear of deque
        deque.push_back(i);
    }

    // process the rest of the elements
    for (i; i < array.size(); ++i)
    {
        // the element at the front of the deque is largest, of previous window, so print it
        cout << array[deque.front()] << endl;

        // remove elements which are out of the window
        while (!deque.empty() && deque.front() <= i - windowSize)
        {
            deque.pop_front();
        }

        // remove all elements smaller than the currently being added element
        while (!deque.empty() && array[i] >= array[deque.back()])
        {
            deque.pop_back();
        }

        // add current element to rear of deque
        deque.push_back(i);
    }

    // print the maximum element of last window

    cout << array[deque.front()];
}
// Q2: Design a data structure that supports adding and removing elements from both ends in amortized O(1) time, and finding the middle element.
class DequeWithMiddle
{
private:
    deque<int> left;
    deque<int> right;

    void Balance();

public:

    void AddFront(int val);
    void AddBack(int val);
    void RemoveFront();
    void RemoveBack();
    int GetMiddle() const;
    void Print() const;
};

void DequeWithMiddle::Balance()
{
    if (left.size() > right.size() + 1)
    {
        right.push_front(left.back());
        left.pop_back();
    }
    else if (right.size() > left.size())
    {
        left.push_back(right.front());
        right.pop_front();
    }
}

void DequeWithMiddle::AddFront(int val)
{
    left.push_front(val);
    Balance();
}

void DequeWithMiddle::AddBack(int val)
{
    right.push_back(val);
    Balance();
}

void DequeWithMiddle::RemoveFront()
{
    if (left.empty())
    {
        return;
    }

    left.pop_front();
    Balance();
}

void DequeWithMiddle::RemoveBack()
{
    if (right.empty())
    {
        return;
    }

    right.pop_back();
    Balance();
}

int DequeWithMiddle::GetMiddle() const
{
    if (left.empty())
    {
        return -1;
    }
    return left.back();
}

void DequeWithMiddle::Print() const
{
    cout << "Left: ";
    for (int i : left)
    {
        cout << i << " ";
    }

    cout << endl;

    cout << "Right: ";
    for (int i : right)
    {
        cout << i << " ";
    }

    cout << endl;

    cout << "Middle: " << GetMiddle() << endl;

}
