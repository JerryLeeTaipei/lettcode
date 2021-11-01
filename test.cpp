#include <iostream>

enum { kIsSmaller, kIsLarger, kIsSame };

// decide the order of inserted data to the current data object
class Data
{
public:
    Data(int newVal):value(newVal) {}
    ~Data() {}
    int compare(const Data&);
    void show() { std::cout << value << "\n"; }
private:
    int value;
};

// A function that decides where in the list a
// particular object belongs.
int Data::compare(const Data& otherData)
{
    if (value < otherData.value)
        return kIsSmaller;
    if (value > otherData.value)
        return kIsLarger;
    else
        return kIsSame;
}

// forward class declarations
class Node;
class HeadNode;
class TailNode;
class InternalNode;

// An ADT representing the node object in the list.
// Every derived class must override insert() and show().
class Node
{
public:
    Node() {}
    virtual ~Node() {}
    virtual Node* insert(Data* data) = 0;
    virtual void show() = 0;
private:
};

/*** InternalNode ***/
// A node to hold objects of type Data.
class InternalNode : public Node
{
public:
    InternalNode(Data* data, Node* next);
    ~InternalNode() { delete next; delete data; }
    Node* insert(Data* data);
    void show()
        { data->show(); next->show(); } // delegate!
private:
    Data* data;// the data itself
    Node* next;// points to next node in the linked list
};

InternalNode::InternalNode(Data* newData, Node* newNext):
data(newData), next(newNext)
{
}

// A function to store a new object in the list.
// The object is passed to the node which figures out
// where it goes and inserts it into the list.
Node* InternalNode::insert(Data* otherData)
{
    std::cout << "InternalNode::insert(): comapre ";
    this->data->show();
    std::cout << "\n";
    int result = data->compare(*otherData);
    switch (result)
    {
        case kIsSame:
        // fall through
        case kIsLarger:
            {
            InternalNode *dataNode = new InternalNode(otherData, this); // data, next
            return dataNode;
            }
        case kIsSmaller:
            next = next->insert(otherData);
            return this;
    }
    return this; // appease the compiler
}

/*** TailNode ***/
class TailNode : public Node
{
public:
    TailNode() {}
    ~TailNode() {}
    Node* insert(Data* data);
    void show() {}
private:
};

// If data comes to me, it must be inserted before me
// since nothing goes after the tail
Node* TailNode::insert(Data* data)
{
    InternalNode* dataNode = new InternalNode(data, this);// data, next
    std::cout << " insert a data node=" << dataNode << " before the tail=" << this << "\n";
    return dataNode;
}

/*** HeadNode ***/
// The head node:
// * holds no data
// * creates a tail node 
class HeadNode : public Node
{
public:
    HeadNode();
    ~HeadNode() { delete next; }
    Node* insert(Data* data);
    void show() { next->show(); }
private:
    Node* next;
};

// The first node in the list, which creates the tail
HeadNode::HeadNode()
{
    next = new TailNode;
    std::cout << "Created a TailNode=" << next << "\n";
}

// Since nothing comes before the head, just pass
// the data on to the next node
Node* HeadNode::insert(Data* data)
{
    std::cout << "HeadNode:insert ";
    if ( data )
        data->show();
    next = next->insert(data);
    if ( next ) {
        std::cout << ", HeadNode:->next=" << next << "\n";
    }
    return this;
}

/*** LinkedList ***/
class LinkedList
{
public:
    LinkedList();
    ~LinkedList() { delete head; }
    void insert(Data* data);
    void showAll() { head->show(); }
private:
    HeadNode* head;
};

// create the head node, which creates
// the tail node.
LinkedList::LinkedList()
{
    head = new HeadNode;
}

// Delegate to a head node
void LinkedList::insert(Data* pData)
{
    head->insert(pData);
}

/*** main ***/
int main()
{
    Data* pData;
    int val;
    LinkedList ll;
    // store user values in a linked list
    while (true)
    {
        std::cout << "What value (0 to stop)? ";
        std::cin >> val;
        if (!val)
            break;
        pData = new Data(val);
        ll.insert(pData);
    }
    // display the list
    ll.showAll();
    return 0;
}

/*

init:

      HeadNode->next = TailNode

Insert the 1st value: TailNode->insert() is called

    InternalNode->next = TailNode
    HeadNode->next = InternalNode

    
Insert other values: InternalNode->insert() is called

    if ( new value > HeadNode->next )
        next = next->insert()   // recursive 
    if ( new value <= current InternalNode )
        new_InternalNode->next = InternalNode
        

*/
