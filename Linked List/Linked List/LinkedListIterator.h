#pragma once

class LinkedList;
class Node;

//overrides a bunch of ops fo use in node/linked list class
//Ask if this is needed or if can use just a pointer

class LinkedListIterator{
public:
	LinkedListIterator();
	~LinkedListIterator();


private:
	Node* m_currentNode;
};