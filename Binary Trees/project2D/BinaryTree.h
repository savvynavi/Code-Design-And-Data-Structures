#pragma once
#include"Renderer2D.h"
class TreeNode;



class BinaryTree{
	struct Node;//why is this here
public:
	BinaryTree();
	~BinaryTree();

	bool isEmpty()const;
	void insert(int nValue);
	void remove(int nValue);
	TreeNode* find(int nValue);
	void draw(aie::Renderer2D* renderer, TreeNode* selected = nullptr);
private:
	bool findNode(int nSearchValue, TreeNode** ppOutNode, TreeNode** ppOutParent);
	void draw(aie::Renderer2D* renderer, TreeNode* pNode, int x, int y, int horizontalSpacing, TreeNode* selected = nullptr);
	TreeNode* m_pRoot;
};