#pragma once

//has all the functionality(template out int value at some point)

class Node{
public:
	Node();
	~Node();

	void pushFront(int data);
	void pushBack(int data);

	Node::iterator begin();
private:
	Node* m_first;
	Node* m_last;

	Node* m_head;
	Node* m_tail;

	Node* m_next;
	Node* m_previous;

	int m_data;
};