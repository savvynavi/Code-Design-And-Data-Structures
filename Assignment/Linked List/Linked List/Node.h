#pragma once

class Node{
public:
	Node(int data);
	Node();
	~Node();
	int& getData();
	Node* getNext();
	Node* getPrevious();

	void setData(int data);
	void setNext(Node* next);
	void setPrevious(Node* previous);
private:
	int m_data;
	Node* m_next;
	Node* m_previous;
};