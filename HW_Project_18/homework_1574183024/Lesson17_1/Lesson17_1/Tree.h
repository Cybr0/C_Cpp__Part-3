#pragma once
class TreeItem {
public:
	TreeItem():data{0},parent{nullptr},
		       left{ nullptr },right{ nullptr }{}
	int data;
	TreeItem* parent;
	TreeItem* left;
	TreeItem* right;
};

class Tree
{
public:
	Tree();
	~Tree();
	void add(int);
	void add_rc(int);
	bool remove(int);
	TreeItem* find(int);
	void show();
	void print(TreeItem *);
private:
	TreeItem* add(TreeItem*, int);
	TreeItem* find(TreeItem* ,int);
	TreeItem* root;
};

