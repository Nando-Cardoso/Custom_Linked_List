#pragma once

using namespace std;

// Node class used in the linked list
// Each node contains an int data value and a pointer to the next
//		node in the Linked List

class Node{
public:
	
	int data_;
	Node *next_ = nullptr;
	Node* prev_ = nullptr;

	Node(int datain);
	~Node();
	void setNext(Node * n);
	void setPrev(Node * p);
};

