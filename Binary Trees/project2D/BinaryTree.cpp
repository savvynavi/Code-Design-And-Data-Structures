#include"BinaryTree.h"
#include"TreeNode.h"
#include"Renderer2D.h"

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
		m_pRoot->setData(nValue);
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
		currentParent->setLeft(currentNode);
	}else{
		currentParent->setRight(currentNode);
	}
}

void BinaryTree::remove(int nValue){
	TreeNode* currentNode = this->find(nValue);
	//TreeNode* currentParent = ;
}

//returns node where value is found at, also keeps track of parent node => Somehow make it return 2 values?
TreeNode* BinaryTree::find(int nValue){
	TreeNode* currentNode = m_pRoot;
	TreeNode* currentParent = nullptr;
	while(currentNode != nullptr){
		if(nValue == currentNode->getData()){
			return(currentNode);
		}else{
			if(nValue < currentNode->getData()){
				currentParent = currentNode;
				currentNode = currentNode->getLeft();
			}else{
				currentParent = currentNode;
				currentNode = currentNode->getRight();
			}
		}
	}

	return nullptr;
}

void BinaryTree::draw(aie::Renderer2D* renderer, TreeNode* selected){
	draw(renderer, m_pRoot, 640, 680, 640, selected);
}

//retunrs true if specified node is found
bool BinaryTree::findNode(int nSearchValue, TreeNode** ppOutNode, TreeNode** ppOutParent){
	if(this->find(nSearchValue) == nullptr){
		return false;
	}
	return true;
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
