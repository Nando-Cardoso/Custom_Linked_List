#include <iostream>
#include "Node.hpp"
#include "MyLinkedList.hpp"
#include "Sortable.h"


using namespace std;

int main()
{

	Sortable* sortable = new Sortable();

	//Printing the Linked List.
	cout << "Printed List" << endl << endl;
	sortable->printList();

	//Sorting List - Unfinished.
	cout << endl;
	sortable->insertionSort();
	sortable->printList();


	//Testing the functions of my list.
	MyLinkedList* testList = new MyLinkedList();
	
	cout << endl;

	//push_back
	cout << "push_back" << endl << endl;
	testList->push_back(1);
	testList->push_back(2);
	testList->push_back(3);
	testList->push_back(4);
	testList->push_back(5);
	testList->print();
	cout << endl;

	//popback
	cout << "pop_back" << endl << endl;
	testList->pop_back();
	testList->print();
	cout << endl;

	//push_front
	cout << "push_front" << endl << endl;
	testList->push_front(30);
	testList->print();
	cout << endl;

	//pop_front
	cout << "pop_front" << endl << endl;
	testList->pop_front();
	testList->print();
	cout << endl;
	
	//find
	cout << "find" << endl << endl;
	cout << testList->find(4);
	cout << endl << endl;


	//swap
	Node* n1 = testList->head_;
	Node* n2 = testList->tail_;

	cout << "swap" << endl << endl;
	testList->swap(n1, n2);
	testList->print();
	cout << endl;

	//Remove
	cout << "Remove" << endl << endl;
	testList->remove(n1);
	testList->print();
	cout << endl;

	//Insert
	cout << "Insert" << endl << endl;
	testList->insert(n2, 1);
	testList->print();
	cout << endl;

	cout << "TEST SORT" << endl;
	testList->print();
	cout << endl;
	testList->selectionSort();
	cout << endl;
	testList->print();

}