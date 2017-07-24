#pragma once
#include "Node.h"
#include"LinkedListIterator.h"
//just calls functions from node

class LinkedList{
public:
	LinkedList();
	~LinkedList();

	int getFirst();
	int getLast();
	void setFirst(int data);
	void setLast(int data);
	bool empty();
	int count();

	void pushFront(int data);
	void popFront();
	void pushBack(int data);
	void popBack();
	void clear();
	void remove(int data);

	LinkedListIterator begin();
	LinkedListIterator end();
	void erase(LinkedListIterator& index);
	LinkedListIterator find(const int& data);
	void insert(LinkedListIterator& index, int data);
private:
	Node* m_first = nullptr;
	Node* m_last = nullptr;
	unsigned int m_elements = 0;
};