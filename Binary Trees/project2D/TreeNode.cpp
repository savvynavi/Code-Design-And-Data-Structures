#include"TreeNode.h"
#include"Font.h"
#include<stdio.h>

extern aie::Font* g_systemFont;

TreeNode::TreeNode(int value){
	m_value = value;
	m_font = new aie::Font("/font/consolas.ttf", 10);
}

TreeNode::~TreeNode(){

}

//returns true if the node has left/right children
bool TreeNode::hasLeft(){
	return(m_left != nullptr);
}

bool TreeNode::hasRight(){
	return(m_right != nullptr);
}

//returns value stored in node
int TreeNode::getData(){
	return m_value;
}

//returns left/right node
TreeNode* TreeNode::getLeft(){
	return m_left;
}

TreeNode* TreeNode::getRight(){
	return m_right;
}

//sets the data in the node
void TreeNode::setData(int value){
	m_value = value;
}

//sets the left/right node to be another node
void TreeNode::setLeft(TreeNode* node){
	m_left = node;
}

void TreeNode::setRight(TreeNode* node){
	m_right = node;
}

void TreeNode::draw(aie::Renderer2D* renderer, int x, int y, bool selected){
	static char buffer[10];

	sprintf(buffer, "%d", m_value);

	renderer->setRenderColour(1, 1, 0);
	renderer->drawCircle(x, y, 30);

	if(selected == true){
		renderer->setRenderColour(0.5, 0.5, 0);
	}else{
		renderer->setRenderColour(1, 1, 1);
	}
	renderer->drawCircle(x, y, 28);

	renderer->setRenderColour(1, 1, 1);
	renderer->drawText(g_systemFont, buffer, x - 12, y - 10);
}