#include"LinkedListIterator.h"
#include"LinkedList.h"
#include"Node.h"

LinkedListIterator::LinkedListIterator(Node* node){
	m_currentNode = node;
}

LinkedListIterator::LinkedListIterator(){

}

LinkedListIterator::~LinkedListIterator(){

}

//returns current node iterator pointing to
Node* LinkedListIterator::getNode(){
	return(m_currentNode);
}

void LinkedListIterator::setNode(Node* node){
	m_currentNode = node;
}

//op overloading
bool LinkedListIterator::operator ==(const LinkedListIterator& other)const{
	return(m_currentNode == other.m_currentNode);
}

bool LinkedListIterator::operator !=(const LinkedListIterator& other)const{
	return(m_currentNode != other.m_currentNode);
}

//prefix ops
LinkedListIterator& LinkedListIterator::operator ++(){
	m_currentNode = m_currentNode->getNext();
	return *this;
}

LinkedListIterator& LinkedListIterator::operator --(){
	m_currentNode = m_currentNode->getPrevious();
	return *this;
}

//postfix ops
LinkedListIterator LinkedListIterator::operator++(int){
	LinkedListIterator tmp(m_currentNode);
	m_currentNode = m_currentNode->getNext();
	return tmp;
}

LinkedListIterator LinkedListIterator::operator--(int){
	LinkedListIterator tmp(m_currentNode);
	m_currentNode = m_currentNode->getPrevious();
	return tmp;
}

int& LinkedListIterator::operator*(){
	return(m_currentNode->getData());
}

int* LinkedListIterator::operator->(){
	return&(m_currentNode->getData());
}