#include <iostream>
#include "MyLinkedList.hpp"
#include <cassert>
#include <vector>


// Desc:   no parameter constructor
//         initializes the LinkedList
// Parms:  n/a
// Returns: n/a
MyLinkedList::MyLinkedList()
{
}

// Desc:   no parameter constructor
//         initializes the LinkedList
// Parms:  n/a
// Returns: n/a
MyLinkedList::MyLinkedList(vector<int>& v)
{

	for (size_t i = 0; i < v.size(); i++)
	{
		push_back(v.at(i));
		
	}


}

// Desc:   destructor
//         releases all the nodes from memory
// Parms:  n/a
// Returns: n/a
MyLinkedList::~MyLinkedList() {
	// delete all the nodes
	Node *delptr = nullptr;
	Node *next = nullptr;
	Node *prev = nullptr;
	delptr = this->head_;
	next = delptr->next_;
	if (this->head_ == nullptr) { return; }
	int cnt = 0;
	while (delptr != nullptr) {
		cnt++;
		next = delptr->next_;
		std::cout << "Deleting Node: " << cnt << std::endl;
		delete delptr;
		delptr = next;
	}
	size = 0;
}
 
// Desc:   add a new node to the end of the linked list
// Parms:  data to put in the last node
// Returns: n/a
void MyLinkedList::push_back(int data)
{
	if (this->head_ == nullptr) // if the list is empty
	{							
		this->head_ = new Node(data);
		this->tail_ = this->head_;
		this->head_->next_ = nullptr;
		this->head_->prev_ = nullptr;
	}
	else // create a new node, set the tail to point to the new node
	{    // and the new tail next_ should be a nullptr
		Node *tmp = new Node(data);
		this->tail_->next_ = tmp;
		tmp->prev_ = this->tail_;
		this->tail_ = tmp;
		this->tail_->next_ = nullptr;
	}
	size++;
}
		
// Desc:    remove the last node from the end of the linked list
// Parms:   n/a
// Returns: n/a 
void MyLinkedList::pop_back() 
{
	if (this->head_ == nullptr) return; // empty list
	// find the last node (tail)
	Node *current = this->head_;
	Node *previous = nullptr;
	while (current->next_ != nullptr)
	{
		previous = current;
		current = current->next_;
	}
	tail_ = previous;   // set the previous to last to the new tail
	previous->setNext(nullptr); // the next_ at the tail should be nullptr
	delete current;     // delete the last node
	size--;
}

void MyLinkedList::push_front(int data) 
{
	if (this->head_ == nullptr) {
		this->head_ = new Node(data);
		this->tail_ = this->head_;
		this->head_->next_ = nullptr;
		this->head_->prev_ = nullptr;
	}
	else {
		Node* temp = new Node(data);
		this->head_->prev_ = temp;
		temp->next_ = this->head_;
		this->head_ = temp;
		this->head_->prev_ = nullptr;
	}
	size++;
}

void MyLinkedList::pop_front()
{
	if (this->head_ == nullptr) return; // empty list
	// find the first node (head)
	Node* current = this->tail_;
	Node* next = nullptr;
	while (current->prev_ != nullptr)
	{
		next = current;
		current = current->prev_;
	}
	head_ = next;   // set the previous to last to the new tail
	next->setPrev(nullptr); // the next_ at the tail should be nullptr
	delete current;     // delete the last node
	size--;
}

void MyLinkedList::remove(int val)
{
	if (this->head_ == nullptr) return; // empty list
	// find all nodes with data_ as val
	Node* current = this->head_;
	Node* previous = nullptr;
	while (current != nullptr)
	{
		
		if (current->data_ != val)
		{
			previous = current;
			current = current->next_;
		}
		else
		{
			if (current == this->head_)
			{
				this->head_ = this->head_->next_;
				delete current;
				current = this->head_;
			}
			else
			{
				previous->next_ = current->next_;
				delete current;
				current = previous->next_;
			}
		}
	}
	tail_ = previous;   // set the previous to last to the new tail
	previous->setNext(nullptr); // the next_ at the tail should be nullptr
	delete current;     // delete the last node
	size--;
}

void MyLinkedList::remove(Node* n) {
	
	if (n->prev_ == nullptr)
	{
		head_ = n->next_;
		delete n;
	}
	else if (n->next_ == nullptr)
	{
		tail_ = n->prev_;
		delete n;
	}
	else 
	{
		delete n;
	}
	size--;
}

// Desc:   add a new node to the end of the linked list
// Parms:  data to put in the last node
// Returns: n/a
void MyLinkedList::insert(Node *here,int val)
{
	if (this->head_ == nullptr ) // if the list is empty
	{
		if (here != this->head_)
			assert("Here is invalid pointer");
		this->head_ = new Node(val);
		this->tail_ = this->head_;
		this->head_->next_ = nullptr;
		this->head_->prev_ = nullptr;
	
	}
	else // create a new node, set the tail to point to the new node
	{    // and the new tail next_ should be a nullptr
		Node* tmp = new Node(val);
		if (here == head_)
		{
			tmp->prev_ = head_->prev_;
			head_->prev_ = tmp;
			tmp->next_ = head_;
			head_ = tmp;
		}
		else
		{
			Node* current = this->head_->next_;
			Node* previous = this->head_;
			while (current != nullptr)
			{

				if (current != here)
				{
					previous = current;
					current = current->next_;
				}
				else
				{
					tmp->next_ = current;
					tmp->prev_ = previous;
					previous->next_ = tmp;
					current->prev_ = tmp;
					break;
				}
			}
		}
	}
	size++;
}

Node* MyLinkedList::find(int data) {

	Node* current = this->head_;

	while (current != nullptr)
	{
		if (current->data_ == data) {
			return current;
		}

		current = current->next_;
	}
	return nullptr;
}

void MyLinkedList::swap(Node* node1, Node* node2) {
	int temp;
	temp = node1->data_;
	node1->data_ = node2->data_;
	node2->data_ = temp;
}

template <typename T>
void MyLinkedList::swap(T data1, T data2) {
	T temp;
	temp = data1;
	data1 = data2;
	data2 = temp;
}

void MyLinkedList::print() 
{
	// print out all contents in MyLinkedList
	Node* it = this->head_;
	while (it != nullptr)
	{
		cout << "MyLinkedList Value: " << it->data_ << endl;
		it = it->next_;
	}
}

//AT
int MyLinkedList::at(int index)
{
	Node* ptr = head_;
	for (size_t i = 0; i < index; i++)
	{
		ptr = ptr->next_;
	}

	return ptr->data_;

}

void MyLinkedList::put(int index, int val)
{
	Node* ptr = head_;
	for (size_t i = 0; i < index; i++)
	{
		ptr = ptr->next_;
	}

	ptr->data_ = val;

}

void MyLinkedList::insertionSort()
{
	int first_unsorted, j;


	for (size_t i = 0; i < this->size; ++i)
	{
		first_unsorted = this->at(i);
		j = i - 1;
		while (j >= 0 && this->at(j) > first_unsorted)
		{
			this->put(j + 1, this->at(j));

			--j;

		}

		this->put(j + 1, first_unsorted);


	}

}

void MyLinkedList::bubbleSort()
{
	int temp;
	for (size_t i = 0; i < (this->size - 1); i++)
	{
		for (size_t j = 0; j < this->size - i - 1; j++)
		{

			if (this->at(j) > this->at(j + 1))
			{      // compare adjacent values
				temp = at(j);
				put(j, at(j + 1));
				put(j + 1, temp);

			}
				
		}
	}
}

void MyLinkedList::selectionSort()
{
	int min_index , temp;
	for (size_t i = 0; i < this->size - 1; i++)
	{
		min_index = i;
		for (size_t j = i + 1; j < this->size; j++)
		{
			if (this->at(j) < this->at(min_index)) // if found a smaller value
				min_index = j;       // set new min_index
		}

		temp = at(i);
		put(i, at(min_index));
		put(min_index, temp);
	}
}


