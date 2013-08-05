#ifndef _NODE
#define _NODE

template<class ItemType>
class Node
{
private:
	ItemType		item; // An item in the list
	Node<ItemType>* next; // The next item in the list
public:
	Node(void);
	Node(const ItemType&);
	Node(const ItemType&, Node<ItemType>*);
	void setItem(const ItemType&);
	void setNext(Node<ItemType>*);
	ItemType getItem() const;
	Node<ItemType>* getNext() const;
	virtual ~Node(void);
};

// Default constructor
template <class ItemType>
Node<ItemType>::Node(void) : next(nullptr)
{
}

// Constructor
template <class ItemType>
Node<ItemType>::Node(const ItemType& anItem) : item(anItem), next(nullptr)
{
}
	
// Constructor
template <class ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr) : item(anItem), next(nextNodePtr)
{
}

// Set Item
template <class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem)
{
	item = anItem;
}

// Next Node
template <class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr)
{
	next = nextNodePtr;
}
	
// Get Item
template <class ItemType>
ItemType Node<ItemType>::getItem() const
{
	return item;
}

// Get Next Item
template <class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const
{
	return next;
}

// Destructor
template <class ItemType>
Node<ItemType>::~Node(void)
{
	delete next;
	next = nullptr;
}
#endif