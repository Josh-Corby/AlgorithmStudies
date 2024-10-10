// List

#pragma region LinkedList
// Singly Linked List
// Singly Linked List uses Singly Linked Node
template<typename T>
class Node
{
public:
	T Value;
	Node<T>* Next;

	Node(T value) : Value(value), Next(nullptr);
}

template<typename T>
class SinglyLinkedList
{
private:
	int m_count;

public:
	Node<T>* Head;
	Node<T>* Tail;

	// Constructor
	SinglyLinkedList();

	// Insertion
	void InsertHead(T val);
	void InsertTail(T val);
	void Insert(T val, int index);

	// Get node index of val;
	int Search(T val);

	// Removal
	void RemoveHead();
	void RemoveTail();
	void Remove(int index);

	int Count();
	void PrintList();
};

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList()
{
	m_count = 0;
	Head = nullptr;
	Tail = nullptr;
}

template<typename T>
void SinglyLinkedList<T>::InsertHead(T val)
{
	// create new node
	Node<T>* node = new Node<T>(val);

	// if list is empty, new node becomes head and tail
	if (m_count == 0)
	{
		Head = node;
		Tail = node;
	}

	// otherwise insert new node at head
	else
	{
		// New node points to current head
		node->Next = Head;
		// new node becomes head
		Head = node;
	}

	// an element was added
	m_count++;
}

template<typename T>
void SinglyLinkedList<T>::InsertTail(T val)
{
	// If list is empty
	// Call InsertHead()
	if (m_count == 0)
	{
		InsertHead(val);
	}

	// otherwise create new node for insertion
	Node<T>* node = new Node<T>(val);
	// current tail points to new node
	Tail->Next = node;
	// new node becomes tail
	Tail = new;
	// an element was added
	m_count++;
}

template<typename T>
void SinglyLinkedList<T>::Insert(T val, int index)
{
	// Check if index is out of bounds
	if (index < 0 || index > m_count)
	{
		return;
	}

	// if inserting at head
	if (index == 0)
	{
		InsertHead(val);
		return;
	}

	// if inserting at tail
	if (index == m_count)
	{
		InsertTail();
		return;
	}

	// otherwise inserting at desired index
	// Traverse from Head to node before index
	Node<T>* currentNode = Head;

	for (int = i; i < index; ++i)
	{
		currentNode = currentNode->Next;
	}

	// Create new node
	Node<T>* node = new Node<T>(val);

	// put node between current node and current node->next
	node->Next = currentNode->Next;
	currentNode->Next = Node;

	// an element was added
	m_count++;
}

template<typename T>
int SinglyLinkedList<T>::Search(T val)
{
	// return -1 if list is empty
	if (m_count <= 0)
	{
		return -1;
	}

	// Traverse from head
	Node<T>* node = Head;
	int index = 0;

	while (node != nullptr)
	{
		if (node->Value == val)
		{
			return index;
		}

		++index;
	}

	return -1;
}

template<typename T>
void SinglyLinkedList<T>::RemoveHead()
{
	// if list is empty, do nothing
	if(m_count == 0)
	{
		return;
	}

	// Store node to delete
	Node<T>* node = Head;

	// Assign new head
	Head = node->Next;

	// Clear tail if there is no new head
	if (Head == nullptr)
	{
		Tail = nullptr;
	}

	// delete old head
	delete node;

	// an element was remove
	m_count--;
}

template<typename T>
void SinglyLinkedList<T>::RemoveTail()
{
	// if list is empty, do nothing
	if (m_count <= 0)
	{
		return;
	}

	// if list has one element, remove head
	if (m_count == 1)
	{
		RemoveHead();
		return;
	}

	// store previous node
	Node<T>* previousNode = Head;

	// Traverse through list to find node before tail
	while (previousNode->Next != Tail)
	{
		previousNode = previousNode->Next;
	}

	// store Tail to delete
	Node<T>* node = Tail;

	// previous node becomes new tail
	Tail = previousNode;

	// delete old tail
	delete node;

	// an element was removed
	m_count--;
}

template<typename T>
void SinglyLinkedList<T>::Remove(int index)
{
	// Check if index is out of bounds
	if (index < 0 || index > m_count)
	{
		return;
	}

	// check if removing head
	if (index == 0)
	{
		RemoveHead();
		return;
	}

	// check if removing tail
	if (index == m_count - 1)
	{
		RemoveTail();
		return;
	}

	// Traverse through list until node before index
	// need previous and next node to fill gap
	Node<T>* previousNode = Head;

	for (int i = 0; i < index - 1; ++i)
	{
		previousNode = previousNode->Next;
	}

	// Store node to remove
	Node<T>* currentNode = previousNode->Next;

	// fill gap
	previousNode->Next = currentNode->Next;

	// delete node
	delete currentNode;

	// an element was removed
	m_count--;
}

template<typename T>
int SinglyLinkedList<T>::Count()
{
	return m_count;
}

template<typename T>
void SinglyLinkedList<T>::PrintList()
{
}
#pragma endregion

#pragma region DoublyLinkedList
// Doubly Linked List
// Doubly Linked List needs Doubly Node
template<typename T>
class DoublyNode
{
public:
	T Value;
	DoublyNode<T>* Next;
	DoublyNode<T>* Prev;

	DoublyNode(T val) : Value(val), Next(nullptr), Prev(nullptr);
};

template<typename T>
class DoublyLinkedList
{
private:
	int m_count;

public:
	DoublyNode<T>* Head;
	DoublyNode<T>* Tail;

	// Constructor
	DoublyLinkedList();

	// Insertions
	void InsertHead(T val);
	void InsertTail(T val);
	void Insert(T val, int index);

	// Search
	int Search(T val);

	// Removals
	void RemoveHead();
	void RemoveTail();
	void Remove(int Index);

	int Count();
};

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	m_count = 0;
	Head = nullptr;
	Tail = nullptr;
}

template<typename T>
void DoublyLinkedList<T>::InsertHead(T val)
{
	// create new node
	DoublyNode<T>* node = new DoublyNode<T>(val);
	// if list is empty assign node to head and tail
	if (m_count == 0)
	{
		Head = node;
		Tail = node;
	}

	else
	{
		// Point new head to old
		node->Next = Head;
		// Assign new head
		Head = node;
	}

	// an element was added
	m_count++;
}

template<typename T>
void DoublyLinkedList<T>::InsertTail(T val)
{
	// if list is empty, call insertHead
	if (m_count == 0)
	{
		InsertHead(val);
		return;
	}

	// Create new node to insert
	DoublyNode<T>* node = new DoublyNode<T>(val);

	// Point tail->next to new node
	Tail->Next = node;

	// Point node->prev to tail
	node->Prev = Tail;

	// assing new tail
	Tail = node;

	// an element was added
	m_count++;
}

template<typename T>
void DoublyLinkedList<T>::Insert(T val, int index)
{
	// check if index is out of bounds
	if (index < 0 || index > m_count)
	{
		return;
	}

	// check if inserting at head
	if (index == 0)
	{
		InsertHead(val);
		Return;
	}

	// check if inserting at tail
	if (index == m_count)
	{
		InsertTail(val);
		return;
	}

	// store traversal starting node, will be assigned later when figuring out
	// where to start traversing from
	DoublyNode<T>* prevNode;
	DoublyNode<T>* nextNode;

	// if index is closer to head
	if (index < m_count / 2)
	{
		prevNode = Head;
		// traverse to node before index
		for (int i = 1; i < index; ++i)
		{
			prevNode = prevNode->Next;
		}

		nextNode = prevNode->Next;
	} // index is closer to tail
	else
	{
		nextNode = Tail;
		// traverse to node after index
		for (int i = m_count - 1; i > index; --i)
		{
			nextNode = nextNode->Prev;
		}

		prevNode = nextNode->Prev;
	}

	// create new node
	DoublyNode<T>* node = new DoublyNode<T>(val);

	// point prev node to new
	// point next to new
	prevNode->Next = node;
	node->Prev = prevNode;
	node->Next = nextNode;
	nextNode->Prev = node;

	m_count++
}

template<typename T>
int DoublyLinkedList<T>::Search(T val)
{
	// check if list is empty
	if (m_count == 0)
	{
		return -1;
	}

	// traverse through list until val is found
	DoublyNode<T>* node = Head;
	int index = 0;
	while (node != nullptr)
	{
		if (node->Value == val)
		{
			return index;
		}

		++index;
	}

	// value was not found
	return -1;
}

template<typename T>
void DoublyLinkedList<T>::RemoveHead()
{
	// check if list is empty
	if (m_count == 0)
	{
		return;
	}

	// store current head to remove
	DoublyNode<T>* node = Head;

	// assign new head
	Head = Head->Next;

	// delete old head
	delete node;

	// clear prev of new head
	if (Head != nullptr)
	{
		Head->Prev = nullptr;
	}

	// element was removed
	m_count--;
}

template<typename T>
void DoublyLinkedList<T>::RemoveTail()
{
	// check if list is empty
	if (m_count == 0)
	{
		return;
	}

	// if count is 1, remove head
	if (m_count == 1)
	{
		RemoveHead();
		return;
	}

	// store tail to delete
	DoublyNode<T>* node = Tail;

	// assign new tail
	Tail = Tail->Prev;

	// delete old tail
	delete Tail;

	// clear next of new tail
	Tail->Next = nullptr;

	// element was removed
	m_count--;
}

template<typename T>
void DoublyLinkedList<T>::Remove(int Index)
{
	// check if list is empty
	if (m_count == 0)
	{
		return;
	}

	// check if index is out of bounds
	if (Index < 0 || index > m_count - 1)
	{
		return;
	}

	if (index == 0)
	{
		RemoveHead();
		return;
	}

	if (Index == m_count - 1)
	{
		RemoveTail();
		return;
	}

	// store prev and next node
	DoublyNode<T>* prevNode = nullptr;
	DoublyNode<T>* nextNode = nullptr;
	DoublyNode<T>* nodeToRemove = nullptr;

	// check if closer to head
	if (index < m_count / 2)
	{
		prevNode = Head;

		// traverse to node before index from head
		if (int i = 0; i < index; ++i)
		{
			prevNode = prevNode->Next;
		}

		nodeToRemove = prevNode->Next;
		nextNode = nodeToRemove->Next;
	} // closer to tail
	else
	{
		nextNode = Tail;

		// traverse to node after index from tail
		if (int i = m_count - 1; i > index; --i)
		{
			nextNode = nextNode->Prev;
		}

		nodeToRemove = nextNode->Prev;
		prevNode = nodeToRemove->Prev;
	}

	// fill the gap
	prevNode->Next = nextNode;
	nextNode->Prev = prevNode;

	// delete old node
	delete nodeToRemove;

	// an element was removed
	m_count--;
}

template<typename T>
int DoublyLinkedList<T>::Count()
{
	return m_count;
}
#pragma endregion

#pragma region CircularLinkedList
// Circular Linked List
template<typename T>
class CircularLinkedList
{
private:
	int m_count;

public:
	Node<T>* Tail;

	CircularLinkedList();

	void InsertHead(T val);
	void InsertTail(T val);
	void Insert(T val, int index);

	int Search(T val);

	void RemoveHead();
	void RemoveTail();
	void Remove(int index);

	int Count();
};

template<typename T>
CircularLinkedList<T>::CircularLinkedList()
{
	m_count = 0;
	Tail = nullptr;
}

template<typename T>
void CircularLinkedList<T>::InsertHead(T val)
{
	// Create new node
	Node<T>* node = new Node<T>(val);

	// check if list is empty
	if (m_count == 0)
	{
		// point new node to itself
		node->Next = node;

		// assign new node as tail
		Tail = node;
		return;
	}

	// insert new node at beginning
	node->Next = Tail->Next;
	Tail->Next = node;

	// an element was added
	m_count++;
}

template<typename T>
void CircularLinkedList<T>::InsertTail(T val)
{
	// check if list is empty, if so insert head
	if (m_count == 0)
	{
		InsertHead(val);
		return;
	}

	// Create new node
	Node<T>* node = new Node<T>(val);

	// point new tail to front
	node->Next = Tail->Next;

	// point old tail to new tail
	Tail->Next = node;

	// assign new node as tail
	Tail = node;

	// an element was added
	m_count++;
}

template<typename T>
void CircularLinkedList<T>::Insert(T val, int index)
{
	// check if index is out of bounds
	if (index < 0 || index > m_count)
	{
		return;
	}

	// check if inserting at head
	if (index == 0)
	{
		InsertHead(val);
		return;
	}

	// check if inserting at tail
	if (index == m_count)
	{
		InsertTail(val);
		return;
	}

	Node<T>* currentNode = Tail->Next;

	// traverse through list to element before index
	for (int i = 0; i < index; ++i)
	{
		currentNode = currentNode->Next;
	}

	// Create new node
	Node<T>* node = new Node<T>(val);

	// insert new node between current and next node
	node->Next = currentNode->Next;
	currentNode->Next = node;

	// an element was added
	m_count++;
}

template<typename T>
int CircularLinkedList<T>::Search(T val)
{
	// if list is empty return -1
	if (m_count == 0)
	{
		return -1;
	}

	// iterate through list, starting at head
	Node<T>* node = Tail->Next;
	for (int i = 0; i < m_count; ++i)
	{
		if (node->Value == val)
		{
			return i;
		}

		node = node->Next;
	}

	return -1;
}

template<typename T>
void CircularLinkedList<T>::RemoveHead()
{
	// check if list is empty
	if (m_count == 0)
	{
		return;
	}

	// if there is only the head/tail
	if (m_count == 1)
	{
		delete Tail;
		Tail = nullptr;
		m_count--;
		return;
	}

	// store node to delete
	Node<T>* node = Tail->Next;

	//fill the gap
	Tail->Next = node->Next;

	// delete old head
	delete node;

	// an element was removed
	m_count--;
}

template<typename T>
void CircularLinkedList<T>::RemoveTail()
{
	// if list is empty, do nothing
	if (m_count == 0)
	{
		return;
	}

	// if there is only the head/tail
	if (m_count == 1)
	{
		delete Tail;
		Tail = nullptr;
		m_count--;
		return;
	}

	// Store traversal node
	Node<T>* Prevnode = Tail->Next;

	// traverse to node before tail
	while (Prevnode->Next != Tail)
	{
		Prevnode = Prevnode->Next;
	}

	// store current tail to delete
	Node<T>* node = Tail;

	// fill the gap
	Prevnode->Next = Tail->Next;

	// assign new tail
	Tail = Prevnode;

	// delete old tail
	delete node;

	m_count--;
}

template<typename T>
void CircularLinkedList<T>::Remove(int index)
{
	// check if index is out of bounds
	if (index < 0 || index > m_count)
	{
		return;
	}

	// if removing head
	if (index == 0)
	{
		RemoveHead();
		return;
	}

	// if removing tail
	if (index == m_count - 1)
	{
		RemoveTail();
		return;
	}

	// Store node to iterate with, starting from head
	Node<T>* prevNode = Tail->Next;
	// Iterate to node before index
	for (int i = 0; i < index; ++i)
	{
		prevNode = prevNode->Next;
	}

	// store node to delete
	Node<T>* node = prevNode->Next;

	// fill the gap
	prevNode->Next = node->Next;

	// delete node
	delete node;

	// an element was removed
	m_count--;
}

template<typename T>
int CircularLinkedList<T>::Count()
{
	return m_count;
}

#pragma endregion

#pragma region DoublyCircularLinkedList
// Doubly Circular Linked list
template<typename T>
class DoublyCircularLinkedList
{
private:
	m_count;

public:
	DoublyNode<T>* Tail;

	// constructor
	DoublyCircularLinkedList();

	// insertions
	void InsertHead(T val);
	void InsertTail(T val);
	void Insert(T val, int index);

	// search
	int Search(T val);

	// removals
	void RemoveHead();
	void RemoveTail();
	void Remove(int index);

	// count
	int count();
};

template<typename T>
DoublyCircularLinkedList<T>::DoublyCircularLinkedList()
{
	m_count = 0;
	Tail = nullptr;
}

template<typename T>
void DoublyCircularLinkedList<T>::InsertHead(T val)
{
	// create new node
	DoublyNode<T>* node = new DoublyNode<T>(val);

	// check if list is empty
	if (m_count == 0)
	{
		// node becomes tail, and points to itself both ways
		node->Prev = node;
		node->Next = node;
		Tail = node;
	}

	else
	{
		// insert new node
		node->Next = Tail->Next;
		node->Prev = Tail;
		Tail->Next->Prev = node;
		Tail->Next = node;
	}

	// an element was added
	m_count++;
}

template<typename T>
void DoublyCircularLinkedList<T>::InsertTail(T val)
{
	// if list is empty, insert head
	if (m_count == 0)
	{
		InsertHead(val);
		return;
	}

	// create new node
	DoublyNode<T>* node = new DoublyNode<T>(val);
	
	// insert new node
	node->Next = Tail->Next;
	node->Prev = Tail;
	Tail->Next->Prev = node;
	Tail->Next = node;

	// assign new tail
	Tail = node;

	// element addded
	m_count++;
}

template<typename T>
void DoublyCircularLinkedList<T>::Insert(T val, int index)
{
	// check if index is out of bounds
	if (index < 0 || index > m_count)
	{
		return;
	}

	// if inserting head
	if (index == 0)
	{
		InsertHead(val);
	}

	// if inserting tail
	if (index == m_count)
	{
		InsertTail(val);
	}

	DoublyNode<T>* prevNode = nullptr;
	DoublyNode<T>* nextNode = nullptr;

	// check if index is closer to head
	// if so traverse from head
	if (index < m_count / 2)
	{
		prevNode = Tail->Next;
		// traverse to node before index
		for (int i = 0; i < index; ++i)
		{
			prevNode = prevNode->Next;
		}

	} // otherwise traverse from tail
	else
	{
		nextNode = Tail;
		// traverse to node after index
		for (int i = m_count - 1; i > index; --i)
		{
			nextNode = nextNode->Prev;
		}
	}

	DoublyNode<T>* node = new DoublyNode<T>(val);

	// insert the node
	node->Prev = prevNode;
	node->Next = nextNode;
	prevNode->Next = node;
	nextNode->Prev node;

	m_count++;
}

template<typename T>
int DoublyCircularLinkedList<T>::Search(T val)
{
	if (m_count == 0)
	{
		return -1;
	}

	// traverse through list
	DoublyNode<T>* node = Tail->Next;
	for (int i = 0; i < m_count; ++i)
	{
		if (node->Value == val)
		{
			return i;
		}
	}

	return -1;
}

template<typename T>
void DoublyCircularLinkedList<T>::RemoveHead()
{
	// check if list is empty
	if (m_count == 0)
	{
		return;
	}

	if (m_count == 1)
	{
		delete Tail;
		Tail = nullptr;
		m_count--;
		return;
	}

	//store head to remove
	DoublyNode<T>* node = Tail->Next;

	// fill the gap
	Tail->Next = node->Next;
	Tail->Next->Prev = Tail;

	// delete old head
	delete node;

	m_count--;
}

template<typename T>
void DoublyCircularLinkedList<T>::RemoveTail()
{
	// check if list is empty
	if (m_count == 0)
	{
		return;
	}

	// check if list has 1 element
	if (m_count == 1)
	{
		delete tail;
		Tail = nullptr;
		m_count--;
		return;
	}

	// store tail to delete
	DoublyNode<T>* node = Tail;

	// fill the gap
	Tail->Prev->Next = Tail->Next;
	Tail->Next->Prev = Tail->Prev;
	Tail = Tail->Prev;

	// delete old tail
	delete node;

	// an element was removed
	m_count--;
}

template<typename T>
void DoublyCircularLinkedList<T>::Remove(int index)
{
	// check if list is empty
	if (m_count == 0)
	{
		return;
	}

	// check if removing head
	if (index == 0)
	{
		RemoveHead();
	}

	// check if removing tail
	if (index == m_count - 1)
	{
		RemoveTail();
	}

	// create prev and next node
	DoublyNode<T>* prevNode = nullptr;
	DoublyNode<T>* nextNode = nullptr;
	DoublyNode<T>* nodeToRemove = nullptr;

	// check if closer to head
	if (index < m_count - 1)
	{
		// iterate from head to index-1
		prevNode = Tail->Next;
		for (int i = 0; i < index; ++i)
		{
			prevNode = prevNode->Next;
		}

		nodeToRemove = prevNode->Next;
		nextNode = nodeToRemove->Next;
	} // closer to tail
	else
	{
		nextNode = Tail;
		for (int i = m_count - 1; i > index; ++i)
		{
			nextNode = nextNode->Prev;
		}

		nodeToRemove = nextNode->Prev;
		prevNode = nodeToRemove->Prev;
	}

	// fill the gap
	prevNode->Next = nextNode;
	nextNode->Prev = prevNode;

	// delete node
	delete nodeToRemove;

	// element removed
	m_count--;
}

template<typename T>
int DoublyCircularLinkedList<T>::count()
{
	return m_count;
}
#pragma endregion

#pragma region Stack
// Stack (LIFO)
template<typename T>
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

template<typename T>
Stack<T>::Stack()
{
	m_count = 0;
	m_top = nullptr;
}

template<typename T>
bool Stack<T>::IsEmpty()
{
	return m_count == 0;
}

template<typename T>
T Stack<T>::Top()
{
	return m_top;
}

template<typename T>
void Stack<T>::Push(T val)
{
	// add new node to top of stack
	// create new node
	Node<T>* node = new Node<T>(val);

	// top points to new node
	m_top->Next = node;

	// node becomes top
	m_top = node;

	// element added
	m_count++;
}

template<typename T>
void Stack<T>::Pop()
{
	// check if stack is empty
	if (IsEmpty())
	{
		return;
	}

	// store node to remove
	Node<T>* node = m_top;

	// point to new top
	m_top = node->Next;

	delete node;

	m_count--;
}
#pragma endregion

#pragma region Queue
// Queue (FIFO)
template<typename T>
class Queue
{
private:
	int m_count;

	Node<T>* m_front;
	Node<T>* m_back;

public:
	Queue();

	bool IsEmpty();
	T Front();
	void Enqueue(T val);
	void Dequeue();
};


template<typename T>
Queue<T>::Queue()
{
	m_count = 0;
	m_front = nullptr;
	m_back = nullptr;
}

template<typename T>
bool Queue<T>::IsEmpty()
{
	return m_count == 0;
}

template<typename T>
T Queue<T>::Front()
{
	return m_front;
}

template<typename T>
void Queue<T>::Enqueue(T val)
{
	// create new node
	Node<T>* node = new Node<T>(val);
	
	// if queue is empty
	// node will be front and back
	if (m_count == 0)
	{
		node->Next = nullptr;
		m_front = node;
		m_back = node;
	}

	else
	{
		m_back->Next = node;
		m_back = node;
	}

	m_count++;
}

template<typename T>
void Queue<T>::Dequeue()
{
	if (IsEmpty())
	{
		return;
	}

	// store node to delete
	Node<T>* node = m_front;

	// select new front
	m_front = node->Next;

	delete node;

	m_count--;
}
#pragma endregion

#pragma region Deque
// Dequeue
template<typename T>
class Deque
{
private:
	m_count;
	DoublyNode<T>* m_front;
	DoublyNode<T>* m_back;

	Deque();
	bool isEmpty();
	T Front();
	T Back();
	void EnqueueFront(T val);
	void DequeueFront();
	void EnqueueBack(T val);
	void DequeueBack();
};


template<typename T>
Deque<T>::Deque()
{
	m_count = 0;
	m_front = nullptr;
	m_back = nullptr;
}

template<typename T>
bool Deque<T>::isEmpty()
{
	return m_count == 0;
}

template<typename T>
T Deque<T>::Front()
{
	return m_front;
}

template<typename T>
T Deque<T>::Back()
{
	return m_back;
}

template<typename T>
void Deque<T>::EnqueueFront(T val)
{
	// create new node to insert
	DoublyNode<T>* node = new DoublyNode<T>(val);

	// if queue is empty, new will be head and tail
	if (m_count == 0)
	{
		m_front = node;
		m_back = node;
	}

	else
	{
		// insert node at front of deque
		node->Next = m_front;
		m_front->Prev = node;
		m_front = node;
	}

	m_count++;
}

template<typename T>
void Deque<T>::DequeueFront()
{
	// if deque is empty
	if (isEmpty())
	{
		return;
	}

	// store node to delete
	DoublyNode<T>* node = m_front;

	// assign new front
	m_front = node->Next;

	// delete old front
	delete node;

	if (m_front != nullptr)
	{
		m_front->Prev = nullptr;
	}

	m_count--;
}

template<typename T>
void Deque<T>::EnqueueBack(T val)
{

	if (m_count == 0)
	{
		EnqueueFront();
		return;
	}

	// create new node to insert
	DoublyNode<T>* node = new node<T>(val);

	// point to new back
	m_back->Next = node;

	node->Prev = m_back;

	// assign new back
	m_back = node;

	// element added
	m_count++
}

template<typename T>
void Deque<T>::DequeueBack()
{
	// if deque is empty do nothing
	if (isEmpty())
	{
		return;
	}

	// if only one element, deque front
	if (m_count == 1)
	{
		DequeueFront();
		return;
	}

	// store back to delete
	DoublyNode<T>* node = m_back;

	// fill the gap
	m_back = node->Prev;

	m_back->Next = nullptr;

	// delete old back
	delete node;

	// element deleted
	m_count--;
}
#pragma endregion

// Binary Tree
class BinaryTreeNode
{
public:
	int Key;
	BinaryTreeNode* Left;
	BinaryTreeNode* Right;

	BinaryTreeNode(int key) : Key(key), Left(nullptr), Right(nullptr);
};

// Binary Search Tree
class BSTNode
{
public:
	int Value;
	BSTNode* Parent;
	BSTNode* Left;
	BSTNode* Right;
	int Height;

	BSTNode(int key);
};

BSTNode::BSTNode(int val)
{
	Value = val;
	Parent = nullptr;
	Left = nullptr;
	Right = nullptr;
	Height = -1;
}

class BST
{
public:
	BSTNode* Root;

	BST();

	void Insert(int val);
	void Remove(int val);
	bool Search(int val) const;

	int FindMin() const;
	int FindMax() const;
	int Successor(int val) const;
	int Predecessor(int val) const;

	void PrintTreeInOrder() const;

protected:

	BSTNode* Insert(BSTNode* node, int val);
	BSTNode* Remove(BSTNode* node, int val);
	BSTNode* Search(BSTNode* node, int val);

	int FindMin(BSTNode* node) const;
	int FindMax(BSTNode* node) const;
	int Successor(BSTNode* node) const;
	int Predecessor(BSTNode* node) const;

	void PrintTreeInOrder(BSTNode* node) const;
};

BST::BST()
{
	Root = nullptr;
}

void BST::Insert(int val)
{
	Root = Insert(Root, val);
}

BSTNode* BST::Insert(BSTNode* node, int val)
{
	// if tree is emtpy
	if (node == nullptr)
	{
		// create new root
		BSTNode* newNode = new BSTNode(val);
	} // insert as left child
	else if (val < node->Value)
	{
		node->Left = Insert(val);
	} // insert as right child
	else
	{
		node->Right = Insert(val);
	}

	return node;
}

void BST::Remove(int val)
{
	Root = Remove(Root, val);
}

BSTNode* BST::Remove(BSTNode* node, int val)
{
	// if tree is empty
	if (node == nullptr)
	{
		return nullptr;
	}

	// node we want to remove is found
	if (node->Value == val)
	{
		// node is leaf, can remove safely
		if (!node->Left && !node->Right)
		{
			node = nullptr;
		}
		// node has one child(left)
		else if (node->Left && !node->Right)
		{
			// fill the gap
			node->Left->Parent = node->Parent;
			node = node->Left;
		}
		// node has one child(right)
		else if (node->Right && !node->Left)
		{
			// fill the gap
			node->Right->Parent = node->Parent;
			node = node->Right;
		} // node has two children
		else
		{
			// find successor or predecessor
			int successorValue = Successor(val);

			// replace nodes val with successors val
			node->Value = successorValue;

			// delete old successors key
			node->Right = Remove(node->Right, successorValue);
		}
	} // node->val < val
	else if (node->Value < val)
	{
		node->Right = Remove(node->Right, val);
	} // node->Val > val
	else
	{
		node->Left = Remove(node->Left, val);
	}

	return node;
}

bool BST::Search(int val) const
{
	BSTNode* result = Search(Root, val);

	return result == nullptr? false : true;
}

BSTNode* BST::Search(BSTNode* node, int val)
{
	// no more nodes to search
	if (node == nullptr)
	{
		return nullptr;
	} // node is found
	else if (node->Value == val)
	{
		return node;
	} // val < node->Val, traverse left
	else if (val < node->Value)
	{
		return Search(node->Left, val)
	} // val > node->Val, traverse right
	else
	{
		return Search(node->Right, val);
	}
}

int BST::FindMin() const
{
	return FindMin(Root);
}

int BST::FindMin(BSTNode* node) const
{
	// tree is empty
	if (node == nullptr)
	{
		return -1;
	} // no left child
	else if(node->Left == nullptr)
	{
		return node->Value;
	}// if left child exists, traverse left
	else 
	{
		return FindMin(node->Left);
	}
}

int BST::FindMax() const
{
	return FindMax(Root);
}

int BST::FindMax(BSTNode* node) const
{
	// tree is empty
	if (node == nullptr)
	{
		return -1;
	} // no right child
	else if (node->Right == nullptr)
	{
		return node->Value;
	} // right child exists
	else
	{
		return FindMax(node->Right);
	}
}

int BST::Successor(int val) const
{
	BSTNode* node = Search(Root, val);

	return node == nullptr ? -1 : Successor(node);
}

int BST::Successor(BSTNode* node) const
{
	// rules
	// 1. if right subtree exists, successor is min value of right subtree
	if (node->Right)
	{
		return FindMin(node->Right);
	}
	// 2. if no right subree, successor is first larger ancestor
	//
	else
	{
		BSTNode* parent = node->Parent;
		BSTNode* current = node;

		// if current is not root, and current is a right subchild, move up
		while (parent != nullptr && current == parent->Right)
		{
			current = parent;
			parent = current->Parent;
		}

		// if parentNode is not null
		// than the key of the parent node
		// is the successor 
		return parent == nullptr ? -1 : parent->Value;
	}
}

int BST::Predecessor(int val) const
{
	BSTNode* node = Search(root, val);

	return node == nullptr ? -1 : Predecessor(node);
}

int BST::Predecessor(BSTNode* node) const
{
	// rules
	// 1. left subtree exists, predecessor will be max of left subtree
	if (node->Left)
	{
		return FindMax(node->Left);
	}
	// 2. no left subtree, predecessor is first ancestor smaller than node
	// 2. if the parent is a rightsubchild of its parent, the grandparent is the predecessor
	// 2. eg. GP(23)->R = P(31)->L = C(29)
	else
	{
		BSTNode* parent = node->Parent;
		BSTNode* current = node;

		// while the node has a parent(is not the root), and it is the left child of its parent
		// keep going, a smaller node is found when current > parent(right child of parent)
		while (parent != null && current == parent->Left)
		{
			current = parent;
			parent = current->parent;
		}

		return parent == nullptr ? -1 : parent->Value;
	}
}

void BST::PrintTreeInOrder() const
{
	PrintTreeInOrder(Root);
	cout << endl;
}


void BST::PrintTreeInOrder(BSTNode* node) const
{
	// stop printing if no node found
	if (node == nullptr)
	{
		return;
	}

	// get smallest value
	// down left subtree
	PrintTreeInOrder(node->Left);

	// print the value
	cout << node->Value;

	// continue to largest value
	PrintTreeInOrder(node->Right);
}