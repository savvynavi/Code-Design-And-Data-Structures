#include"BinaryTree.h"
#include"TreeNode.h"
#include"Renderer2D.h"
#include<iostream>
#include<list>

BinaryTree::BinaryTree(){
	m_pRoot = nullptr;
}

BinaryTree::~BinaryTree(){

}

//returns true if the root is null
bool BinaryTree::isEmpty()const{
	return(m_pRoot == nullptr);
}

//inserts value into tree
void BinaryTree::insert(int nValue){
	//if tree is empty, places data at root
	if(this->isEmpty() == true){
		m_pRoot = new TreeNode(nValue);
		return;
	}

	//travels down tree in balanced way to find last nore to attach value to while also keeping track of parent node
	TreeNode* currentNode = m_pRoot;
	TreeNode* currentParent = nullptr;
	while(currentNode != nullptr){
		if(nValue < currentNode->getData()){
			currentParent = currentNode;
			currentNode = currentNode->getLeft();
		}else if(nValue > currentNode->getData()){
			currentParent = currentNode;
			currentNode = currentNode->getRight();
		}else if(nValue == currentNode->getData()){
			return;
		}
	}

	// places the data into node either left or right of parent
	if(nValue < currentParent->getData()){
		currentParent->setLeft(new TreeNode(nValue));
	}else{
		currentParent->setRight(new TreeNode(nValue));
	}
}

int BinaryTree::searchMin(TreeNode* currentNode) {
	TreeNode* top = nullptr;
	currentNode = currentNode->getRight();
	int smallestNum = currentNode->getData();
	while(currentNode->hasLeft() == true){
		if(currentNode->getLeft()->getData() < smallestNum){
			smallestNum = currentNode->getLeft()->getData();
		}
		currentNode = currentNode->getLeft();
	}
	return smallestNum;
}

//goes through tree, removes the value inputed and cleans up branches
void BinaryTree::remove(int nValue){
	TreeNode* currentNode = m_pRoot;
	TreeNode* currentParent = nullptr;

	bool found = this->findNode(nValue, &currentNode, &currentParent);

	if(found == true){
		if(currentNode->hasRight() == true){
			int value = this->searchMin(currentNode);
			//Holds the node with the smallest value and its parent
			TreeNode* minNode = m_pRoot;
			TreeNode* minParent = nullptr;

			findNode(value, &minNode, &minParent);

			//Put the min value in current node
			currentNode->setData(value);
			if(minParent->getLeft() == minNode){
				//Set the left child of the parent to the its former child's right child.
				minParent->setLeft(minNode->getRight());
			}else{
				//Set the parent's right child node to it former childs right node
				minParent->setRight(minNode->getRight());
			}
		}else if(currentNode->hasRight() == false){
			//Check if we are deleting the left child of a parent
			if(currentParent != nullptr && currentParent->getLeft() == currentNode){
				//set the childs left node as the former parents left node
				currentParent->setLeft(currentNode->getLeft());
			}
			//Check if we are deleting the right child of a parent
			if(currentParent != nullptr && currentParent->getRight() == currentNode){
				//set the childs left node as the former parents right node
				currentParent->setRight(currentNode->getLeft());
			}
			//Check if we are deleting the root node
			if(currentParent == nullptr){
				m_pRoot = currentNode->getLeft();
			}

		}

	}
}

//returns node where value is found at, also keeps track of parent node => Somehow make it return 2 values?
TreeNode* BinaryTree::find(int nValue){
	TreeNode* currentNode = m_pRoot;
	TreeNode* currentParent = nullptr;
	findNode(nValue, &currentNode, &currentParent);
	return currentNode;
}

//retunrs true if specified node is found -> maybe store parent as member var as too hard
bool BinaryTree::findNode (int nSearchValue, TreeNode** ppOutNode, TreeNode** ppOutParent){
	while(*ppOutNode != nullptr){
		if(nSearchValue == (*ppOutNode)->getData()){
			return true;
		}else{
			if(nSearchValue < (*ppOutNode)->getData()){
				(*ppOutParent) = (*ppOutNode);
				(*ppOutNode) = (*ppOutNode)->getLeft();
			}else{
				(*ppOutParent) = (*ppOutNode);
				(*ppOutNode) = (*ppOutNode)->getRight();
			}
		}
	}
	return false;
}

TreeNode* BinaryTree::findRoot(){
	return m_pRoot;
}

//tree searches
void BinaryTree::DepthFirstPostOrder(TreeNode* pNode){
	if(pNode == nullptr){
		return;
	}

	DepthFirstPostOrder(pNode->getLeft());
	DepthFirstPostOrder(pNode->getRight());
	std::cout << pNode->getData() << std::endl;
}

void BinaryTree::DepthFirstPreOrder(TreeNode* pNode){
	if(pNode == nullptr){
		return;
	}

	std::cout << pNode->getData() << std::endl;
	DepthFirstPreOrder(pNode->getLeft());
	DepthFirstPreOrder(pNode->getRight());
}

void BinaryTree::DepthFirstInOrder(TreeNode* pNode){
	if(pNode == nullptr){
		return;
	}

	DepthFirstInOrder(pNode->getLeft());
	std::cout << pNode->getData() << std::endl;
	DepthFirstInOrder(pNode->getRight());
}

void BinaryTree::BredthFirst(TreeNode* pNode){
	if(pNode == nullptr){
		return;
	}
	
	std::list<TreeNode*> processNodes;
	processNodes.push_back(pNode);

	while(processNodes.size() > 0){
		TreeNode* currentNode = processNodes.front();
		std::cout << currentNode->getData() << std::endl;
		processNodes.pop_front();
		if(currentNode->hasLeft() == true){
			processNodes.push_back(currentNode->getLeft());
		}
		if(currentNode->hasRight() == true){
			processNodes.push_back(currentNode->getRight());
		}
	}
}

void BinaryTree::draw(aie::Renderer2D* renderer, TreeNode* selected){
	draw(renderer, m_pRoot, 640, 680, 640, selected);
}

//recursive fn, keeps drawing nodes/lines between them until there are no more nodes left in tree
void BinaryTree::draw(aie::Renderer2D* renderer, TreeNode* pNode, int x, int y, int horizontalSpacing, TreeNode* selected){
	horizontalSpacing /= 2;

	if(pNode){
		if(pNode->hasLeft() == true){
			renderer->setRenderColour(1, 0, 0);
			renderer->drawLine(x, y, x - horizontalSpacing, y - 80);
			draw(renderer, pNode->getLeft(), x - horizontalSpacing, y - 80, horizontalSpacing, selected);
		}

		if(pNode->hasRight() == true){
			renderer->setRenderColour(1, 0, 0);
			renderer->drawLine(x, y, x + horizontalSpacing, y - 80);
			draw(renderer, pNode->getRight(), x + horizontalSpacing, y - 80, horizontalSpacing, selected);
		}

		pNode->draw(renderer, x, y, (selected == pNode));
	}
}
