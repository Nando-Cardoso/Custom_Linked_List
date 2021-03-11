#include "Node.hpp"


// Desc:   no parameter constructor
//         initializes the data in the node
// Parms:  data to store in the node
// Returns: n/a

Node::Node(int datain)
{
	this->data_ = datain;
	this->next_ = nullptr;
	this->prev_ = nullptr;
}

// Desc:   destructor
//         deallocates memory for the Node
// Parms:  n/a
// Returns: n/a

Node::~Node()
{
}

// Desc:   sets the next Node pointer
// Parms:  value to set the next_ Node pointer
// Returns: n/a
void Node::setNext(Node* n)
{
	this->next_ = n;
}

void Node::setPrev(Node * p) {
	this->prev_ = p;
}