#pragma once
using namespace std;
#include "Node.hpp"
#include <vector>


class MyLinkedList
{
private:

public:
	Node* head_ = nullptr;
	Node* tail_ = nullptr;

	int size = 0;

	MyLinkedList();
	MyLinkedList(vector<int>& v);
	~MyLinkedList();

	void print();
	void push_back(int data);
	void pop_back();
	void push_front(int data);
	void pop_front();
	void remove(int data);
	void remove(Node* n);
	void insert(Node*, int);
	Node* find(int n);
	void swap(Node* n1, Node* n2);
	template <typename T>
	void swap(T node1, T node2);
	int at(int index);
	void put(int index, int val);
	void insertionSort();
	void bubbleSort();
	void selectionSort();
};

