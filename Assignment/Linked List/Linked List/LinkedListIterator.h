#pragma once

class LinkedList;
class Node;

//overrides a bunch of ops fo use in node/linked list class

class LinkedListIterator{
public:
	LinkedListIterator();
	~LinkedListIterator();
	Node* getNode();
	void setNode(Node* node);

	bool operator ==(const LinkedListIterator& other)const;
	bool operator !=(const LinkedListIterator& other)const;
	LinkedListIterator& operator ++();
	LinkedListIterator& operator --();
	LinkedListIterator operator++(int);
	LinkedListIterator operator--(int);

	int& operator*();
	int* operator->();
private:
	friend class LinkedList;
	LinkedListIterator(Node* node);
	Node* m_currentNode = nullptr;
};