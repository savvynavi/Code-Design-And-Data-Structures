#pragma once
#include"Renderer2D.h"
#include"Font.h"


class TreeNode{
public:
	TreeNode(int value);
	~TreeNode();

	bool hasLeft();
	bool hasRight();

	int getData();
	TreeNode* getLeft();
	TreeNode* getRight();

	void setData(int value);
	void setLeft(TreeNode* node);
	void setRight(TreeNode* node);

	void draw(aie::Renderer2D* renderer, int x, int y, bool selected = false);
private:
	int m_value;

	//nodes children
	TreeNode* m_left;
	TreeNode* m_right;
	aie::Font* m_font;
};