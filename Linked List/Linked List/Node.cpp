#include"Node.h"

Node::Node(int data){
	m_data = data;
	m_next = nullptr;
	m_previous = nullptr;
}

Node::Node(){
	m_data = 0;
	m_next = nullptr;
	m_previous = nullptr;
}

Node::~Node(){

}

int& Node::getData(){
	return m_data;
}

Node* Node::getNext(){
	return m_next;
}

Node* Node::getPrevious(){
	return m_previous;
}

void Node::setData(int data){
	m_data = data;
}

void Node::setNext(Node* next){
	m_next = next;
}

void Node::setPrevious(Node* previous){
	m_previous = previous;
}