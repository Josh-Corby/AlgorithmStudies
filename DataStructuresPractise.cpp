

template <typename T>
class Node()
{
public:
	T Value;
	Node<T>* Next;

	Node(T value) : Value(value), Next(nullptr);
};

template <typename T>
void PrintNode(Node<T>* node)
{
	while (node != nullptr)
	{
		cout << node->Value << " -> ";
		node = node->Next;
	}

	cout << "nullptr" << endl;
}

class List()
{
private:
	int m_count;
	int* m_items;

public:
	List();
	~List();
	int Get(int index);
	void Insert(int index, int val);
	int Search(int val);
	void Remove(int index);
	int Count();
};

List::List()
{
	m_count = 0;
	m_items = nullptr;
}

List::~List()
{
	delete[] m_items;
}

int List::Get(int index)
{
	if (index < 0 || index > m_count)
	{
		return -1;
	}

	return m_items[index];
}

void List::Insert(int index, int val)
{
	// Check if the index is in bounds
	if (index < 0 || index > m_count)
	{
		return;
	}

	// Copy the old array
	int* oldArray = m_items;

	// increment count
	m_count++;

	// Initialize new array
	m_items = new int[m_count];

	// fill the new array with inserted data
	// i increments through new array, populating it
	// j increments through old array, putting its items into new array
	for (int i = 0, j = 0; i < m_count; ++i)
	{
		if (index == i)
		{
			m_items[i] = val;
		}
		else
		{
			m_items[i] = oldArray[j];
			++j;
		}
	}

	// remove copied array
	delete[] oldArray;
}

// Search through m_items until val is found
int List::Search(int val)
{
	for (int i = 0; i = m_count; ++i)
	{
		if (m_items[i] == val)
		{
			return m_items[i]
		}
	}

	return -1;
}

void List::Remove(int index)
{
	// check if index is out of bounds
	if (index < 0 || index > m_count)
	{
		return;
	}

	// copy the current array
	int* oldArray = m_items;

	// decrease m_count
	m_count--;

	// make new array
	int* newArray = new int[m_count];

	// fill new array
	for (int i = 0, j = 0; i < m_count; ++i)
	{		
		// if j = index to skip in old array, skip that element in old array
		if (index == j)
		{
			++j;
		}

		newArray[i] = oldArray[j];
	}

	// delete old array
	delete[] oldArray;
}

int List::Count()
{
	return m_count;
}

template<typename T>
class SinglyLinkedList()
{
private:
	int m_count;

public:
	Node<T>* Head;
	Node<T>* Tail;

	SinglyLinkedList();

	Node<T>* Get(int index);

	void InsertHead(T val);
	void InsertTail(T val);
	void Insert(int index, T val);

	int Search(T val);

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
Node<T>* SinglyLinkedList<T>::Get(int index)
{
	// Check if index is out of bounds
	if (index < 0 || index > m_count)
	{
		return nullptr;
	}

	// start from the head
	Node<T>* node = Head;

	// iterate through linked list
	for (int i = 0; i < index; ++i)
	{
		node = node->Next;
	}

	// return node at index
	return node;
}

template<typename T>
void SinglyLinkedList<T>::InsertHead(T val)
{
	// create a new node
	Node<T>* node = new Node<T>(val);

	// this node will be the new head, and point to the current head
	node->Next = Head;

	// Assign new head
	Head = node;

	// if the list is empty,
	// the head is also the tail
	if (m_count == 0)
	{
		tail = Head;
	}

	// one element has been added
	m_count++;
}

template<typename T>
void SinglyLinkedList<T>::InsertTail(T val)
{
	// if there are no elements
	// call InsertHead and early return
	if (m_count == 0)
	{
		InsertHead(val);
		return;
	}

	// create a new node
	Node<T>* node = new Node<T>(val);

	// current tail will point to new tail
	Tail->Next = node;

	// assign new tail
	Tail = node;

	// an element was added
	m_count++;
}

template<typename T>
void SinglyLinkedList<T>::Insert(int index, T val)
{
	// check if index is out of bounds
	if (index < 0 || index > m_count)
	{
		return;
	}

	// check if index is 0 for head, if so, early return
	if (index == 0)
	{
		InsertHead(val);
		return;
	}

	// check if index is m_count for tail, if so, early return
	if (index == m_count)
	{
		InsertTail(val);
		return;
	}

	// this function needs the previous and next node that the new node will be between
	// start from the head node and iterate to index-1, result will be desired previous node
	Node<T>* prevNode = Head;

	for (int i = 0; i < index-1; ++i)
	{
		prevNode = prevNode->Next;
	}

	// Create the new node which will be inserted
	Node<T>* node = new Node<T>(val);

	// Get the next node
	Node<T>* nextNode = prevNode->Next;

	// insert new node after prev node
	prevNode->Next = node;

	// point new node to next node
	node->Next = nextNode;

	// an element was added
	m_count++;
}

template<typename T>
int SinglyLinkedList<T>::Search(T val)
{
	// if list is empty, there are no values
	if (m_count == 0)
	{
		return -1;
	}

	// This function gets the index in list that contains val
	// Store index
	int index = 0;

	// Start at head
	Node<T>* node = Head;

	// traverse until the selected value
	// matches the value at the current position
	while (node->Value != val)
	{
		index++;
		node = node->next;

		// we have reached the end of the list, and value was not found
		if (node == nullptr)
		{
			return -1;
		}
	}

	return index;
}

template<typename T>
void SinglyLinkedList<T>::RemoveHead()
{
	// check if list is empty
	if (m_count == 0)
	{
		return;
	}

	// store old head
	Node<T>* node = Head;

	Head = Head->Next;

	// delete old head
	delete node;

	// element was removed
	m_count;
}

template<typename T>
void SinglyLinkedList<T>::RemoveTail()
{
	// check if list is empty
	if (m_count == 0)
	{
		return;
	}

	// if count is 1, call remove head
	if (m_count == 1)
	{
		RemoveHead();
		return;
	}

	// this is the element that will be the new head
	Node<T>* prevNode = Head;

	// this is the element that will be removed
	Node<T>* node = Head->Next;

	// traverse until node == head
	while (node->Next != nullptr)
	{
		prevNode = prevNode->Next;
		node = node->Next;
	}

	// traversal is done
	// prevNode = new tail
	// node = tail to be removed
	// 
	// set prev node to tail
	prevNode->Next = nullptr;
	Tail = prevNode;

	// delete old tail
	delete node;

	// element was removed
	m_count--;
}

template<typename T>
void SinglyLinkedList<T>::Remove(int index)
{
	// do nothing if list is empty
	if (m_count == 0)
	{
		return;
	}

	// do nothing if index is out of bounds
	if (index < 0 || index > m_count)
	{
		return;
	}

	// if index == 0(removing head), call remove head and early return
	if (index == 0)
	{
		RemoveHead();
		return;
	}

	// if index == m_count-1(removing tail), call remove tail and early return
	if (index == m_count - 1)
	{
		RemoveTail();
		return;
	}

	// otherwise we are traversing through the list
	// we need the previous and next nodes
	// of the index we are removing

	// start from head
	node<T>* prevNode = Head;

	// find element before index to remove
	for (int i = 0; i = index - 1; ++i)
	{
		prevNode = prevNode->Next;
	}

	// the element we want to remove is next of prevNode
	Node<T>* nodeToRemove = prevNode->Next;

	Node<T>* nextNode = nodeToRemove->Next;

	// fill the gap
	prevNode->Next = nextNode;

	delete nodeToRemove;

	// element was removed
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
	// traverse through list and print values
	Node<T>* node = Head;

	while (node != nullptr)
	{
		cout << node->Value << " -> ";
		node = node->Next;
	}

	cout << "nullptr" << endl;
}

template<typename T>
class DoublyNode()
{
	T Value;
	DoublyNode<T>* Prev;
	DoublyNode<T>* Next;

	DoublyNode(T value);
};

template<typename T>
DoublyNode<T>::DoublyNode(value)
{
	Value = value;
	Prev = nullptr;
	Next = nullptr;
}

tempate<typename T>
class DoublyLinkedList()
{
private:
	int m_count;

public:
	DoublyNode<T>* Head;
	DoublyNode<T>* Tail;

	DoublyLinkedList();

	DoublyNode<T>* Get(int index);

	void InsertHead(T val);
	void InsertTail(T val);
	void Insert(int index, T val);

	void RemoveHead();
	void RemoveTail();
	void Remove(int index);

	int Count();
	void PrintList();
	void PrintListBackward();
};

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	m_count = 0;
	Head = nullptr;
	Tail = nullptr;
}

DoublyNode<T>* DoublyLinkedList<T>::Get(int index)
{
	// check if index is out of bounds
	if (index < 0 || index >= m_count)
	{
		return nullptr;
	}

	// check looking for head
	if (index == 0)
	{
		return Head;
	}

	// check if looking for tail
	if (index == m_count - 1)
	{
		return Tail;
	}

	// Travel from head or tail, depending on which is closer to index
	DoublyNode<T>* node;

	// Index is closeer to head
	if (index < m_count / 2)
	{
		node = Head;
		// can start looping at 1, as index == 0 is already accounted for
		for (int i = 0; i < index; ++i)
		{
			node = node->Next;
		}
	} // Index is closer to tail
	else
	{
		node = Tail;
		// can start looping at m_count - 2, as index == m_count - 1 is already accounted for
		for (int i = m_count - 2; i > index; --i)
		{
			node = node->Prev;
		}
	}

	return node;
}

template<typename T>
void DoublyLinkedList<T>::InsertHead(T val)
{
	// Create new head node
	DoublyNode<T>* node = new DoublyNode<T>(val);

	// new node->next = head
	node->Next = Head;

	if (Head != nullptr)
	{
		// head->prev = new node
		head->Prev = node;
	}

	// assign new head
	Head = node;

	// If list is empty, tail is also head
	if (m_count == 0)
	{
		Tail = Head;
	}

	// element was added
	m_count++;
}

template<typename T>
void DoublyLinkedList<T>::InsertTail(T val)
{
	// if list is empty, call InsertHead
	if (m_count == 0)
	{
		InsertHead(val);
		return;
	}

	// Create new tail node
	DoublyNode<T>* node = new DoublyNode<T>(val);

	// Current tail->Next points to new tail
	Tail->Next = node;

	// New tail->Prev points to old tail
	node->Prev = Tail;

	// Assign new tail
	Tail = node;

	m_count++
}


template<typename T>
void DoublyLinkedList<T>::Insert(int index, T val)
{
	// check if index is in bounds
	if (index < 0 || index > m_count)
	{
		return;
	}

	// Create the new node
	DoublyNode<T>* newNode = new DoublyNode<T>(val);
	if (!newNode) // check if new node is valid
	{
		return;
	}

	// check if trying to insert at head, early exit
	if (index == 0)
	{
		InsertHead(val);
		return;
	}

	// check if trying to insert at tail, early exit
	if (index == m_count)
	{
		InsertTail(val);
		return;
	}

	// traverse to node before index
	DoublyNode<T>* prevNode = Head;
	for (int i = 0; i < index; ++i)
	{
		prevNode = prevNode->Next;
	}

	// Connect the new node
	newNode->Next = prevNode->Next;		// point to next node
	nextNode->Prev = prevNode;			// point back to prev node
	if (prevNode->Next)					// check if next node is not null
	{
		prevNode->Next->Prev = newNode; // point back to new node
	}

	prevNode->Next = newNode;

	// one element added
	m_count++:

	// strategy above skips the allocation of next node as it is not needed
	
	//// Create the next node which is after prevNode
	//DoublyNode<T>* nextNode = prevNode->Next;
	//// insert new node between other nodes

	//prevNode->Next = newNode;
	//newNode->Next = nextNode;
	//newNode->Prev = prevNode;
	//nextNode->Prev = newNode;
}

template<typename T>
void DoublyLinkedList<T>::RemoveHead()
{
	// check if list is empty
	if (m_count == 0)
	{
		return;
	}

	// copy current head
	DoublyNode<T>* node = Head;

	// Assign new head
	Head = Head->Next;

	// delete old head
	delete node;

	// clear prev of new head
	if (Head != nullptr)
	{
		Head->Prev = nullptr;
	}

	// element removed
	m_count--;
}

template<typename T>
void DoublyLinkedList<T>::void RemoveTail()
{
	// check if list is empty
	if (m_count == 0)
	{
		return;
	}

	if (m_count == 1)
	{
		RemoveHead();
		return;
	}

	// copy old tail
	DoublyNode<T>* node = Tail;

	// assign new tail
	Tail = Tail->Prev;

	// clear next of new tail
	Tail->Next = nullptr;

	// delete old tail
	delete node;

	// element removed
	m_count--;
}

template<typename T>
void DoublyLinkedList<T>::Remove(int index)
{
	// check if list is empty
	if (m_count == 0)
	{
		return;
	}

	// check if index is out of bounds
	if (index < 0 || index >= m_count)
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

	// start to traverse the list
	DoublyNode<T>* prevNode = Head;
	for (int i = 1; i < index - 1; ++i)
	{
		prevNode = prevNode->Next;
	}

	DoublyNode<T>* nodeToDelete = prevNode->Next;
	DoublyNode<T>* nextNode = nodeToDelete->Next;

	prevNode->Next = nextNode;
	if (nextNode)
	{
		nextNode->Prev = prevNode;
	}

	delete nodeToDelete;

	m_count--;
}

template<typename T>
int DoublyLinkedList<T>::Count()
{
	return m_count;
}

template<typename T>
void DoublyLinkedList<T>::PrintList()
{
	DoublyNode<T>* node = Head;

	while (node != nullptr)
	{
		cout << node->Value << " -> ";
		node = node->Next;
	}

	cout << "nullptr" << endl;
}

template<typename T>
void DoublyLinkedList<T>::PrintListBackward()
{
	DoublyNode<T>* node = Tail;

	while (node != nullptr)
	{
		cout << node->Value << " -> ";
		node = node->Prev;
	}

	cout << "nullptr" << endl;
}