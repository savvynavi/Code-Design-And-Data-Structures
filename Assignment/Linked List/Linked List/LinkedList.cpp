#include"LinkedList.h"

LinkedList::LinkedList(){

}

LinkedList::~LinkedList(){
	while(m_first != nullptr){
		Node* tmp = m_first;
		m_first = m_first->getNext();
		delete tmp;
	}
}

//returns the data stored in first element if not nullptr
int LinkedList::getFirst(){
	if(m_first != nullptr){
		return(m_first->getData());
	}
	//otherwise do something that prints an error?
}

//returns data in last element if not nullptr
int LinkedList::getLast(){
	if(m_last != nullptr){
		return(m_last->getData());
	}
	//otherwise do something that prints an error?
}

//sets first/last node data
void LinkedList::setFirst(int data){
	m_first->setData(data);
}

void LinkedList::setLast(int data){
	m_last->setData(data);
}

//returns true if list is empty(no elements)
bool LinkedList::empty(){
	return(m_elements == 0);
}

//returns how many elements in list
int LinkedList::count(){
	return m_elements;
}

//pustes data to the front of the list
void LinkedList::pushFront(int data){
	Node* node = new Node(data);
	node->setNext(m_first);
	
	if(m_last == nullptr){
		m_last = node;
	}
	if(m_first != nullptr){
		m_first->setPrevious(node);
	}

	m_first = node;
	m_elements++;
}

//pops data from the front of the list
void LinkedList::popFront(){
	if(m_first == nullptr){
		return;
	}

	Node* tmp = m_first;
	if(m_first->getNext() != nullptr){
		m_first->getNext()->setPrevious(nullptr);
	}else{
		m_last = nullptr;
	}

	m_first = m_first->getNext();
	delete tmp;
	m_elements--;
}

//pushes data to back of the list
void LinkedList::pushBack(int data){
	Node* node = new Node(data);
	node->setPrevious(m_last);

	if(m_first == nullptr){
		m_first = node;
	}
	if(m_last != nullptr){
		m_last->setNext(node);
	}

	m_last = node;
	m_elements++;
}

//pops data from the back of the list
void LinkedList::popBack(){
	if(m_last == nullptr){
		return;
	}

	Node* tmp = m_last;
	if(m_last->getPrevious() != nullptr){
		m_last->getPrevious()->setNext(nullptr);
	}else{
		m_first = nullptr;
	}

	m_last = m_last->getPrevious();
	delete tmp;
	m_elements--;
}

//clears all nodes from list, sets size to 0
void LinkedList::clear(){
	while(m_first != nullptr){
		Node* tmp = m_first;
		m_first = m_first->getNext();
		delete tmp;
	}
	m_first = nullptr;
	m_last = nullptr;
	m_elements = 0;
}

//removes all instances of given number
void LinkedList::remove(int data){
	Node* tmp = m_first;
	while(tmp != nullptr){
		Node* next = tmp->getNext();

		if(tmp->getData() == data){
			if(tmp == m_first){
				m_first = tmp->getNext();
			}
			if(tmp == m_last){
				m_last = tmp->getPrevious();
			}
			if(tmp->getNext() != nullptr){
				tmp->getNext()->setPrevious(tmp->getPrevious());
			}
			if(tmp->getPrevious() != nullptr){
				tmp->getPrevious()->setNext(tmp->getNext());
			}

			delete tmp;
			m_elements--;
		}

		tmp = next;
	}
}

//returns iterator pointing to first node
LinkedListIterator LinkedList::begin(){
	return(LinkedListIterator(m_first));
}

//points to 1 past the last node(should be a nullptr)
LinkedListIterator LinkedList::end(){
	return(LinkedListIterator());
}

void LinkedList::erase(LinkedListIterator& index){
	if(index.getNode() == nullptr){
		return;
	}

	if(m_first == index.getNode()){
		m_first = index.getNode()->getNext();
	}
	if(m_last == index.getNode()){
		m_last = index.getNode()->getPrevious();
	}
	if(index.getNode()->getPrevious() != nullptr){
		index.getNode()->getPrevious()->setNext(index.getNode()->getNext());
	}
	if(index.getNode()->getNext() != nullptr){
		index.getNode()->getNext()->setPrevious(index.getNode()->getPrevious());
	}

	delete index.getNode();
	index.setNode(nullptr);
	m_elements--;
}

LinkedListIterator LinkedList::find(const int& data){
	auto tmp = m_first;
	while(tmp != nullptr){
		if(tmp->getData() == data){
			return LinkedListIterator(tmp);
		}
		tmp = tmp->getNext();
	}
	return LinkedListIterator();
}

//inserts value 1 past given index
void LinkedList::insert(LinkedListIterator& index, int data){
	if(index.getNode() == nullptr){
		return;
	}
	Node* node = new Node(data);
	node->setPrevious(index.getNode());

	if(index.getNode()->getNext() != nullptr){
		index.getNode()->getNext()->setPrevious(node);
		node->setNext(index.getNode()->getNext());
	}else{
		m_last = node;
	}

	index.getNode()->setNext(node);
	m_elements++;
}