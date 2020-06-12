#include "Tree.h"
#include <iostream>


Tree::Tree():
	root{nullptr}
{
}


Tree::~Tree()
{
	if (root) {
		delete root;
	}
}

void Tree::add(int value)
{
	TreeItem* new_item = new TreeItem();
	new_item->data = value;

	TreeItem* temp = nullptr;
	TreeItem* current = root;
	while (current != nullptr){
		temp = current;
		if (new_item->data < current->data) {
			current = current->left;
		} else {
			current = current->right;
		}
	}
	new_item->parent = temp;
	if (temp == nullptr) {
		root = new_item;
	} else if (new_item->data < temp->data) {
		temp->left = new_item;
	}else{ 
		temp->right = new_item;
	}
}

void Tree::add_rc(int value)
{
	root = add(root, value);
}

bool Tree::remove(int)
{
	return false;
}

TreeItem* Tree::find(int value)
{
	return find(root, value);
}

void Tree::show()
{
	print(root);
}

void Tree::print(TreeItem* item)
{
	if (item){
		print(item->left);
		std::cout << item->data	<< std::endl;
		print(item->right);
	}
}

TreeItem* Tree::add(TreeItem* parent, int value)
{
	if (parent) {
		if (parent->data > value) {
			parent->left = add(parent->left, value);
		} else {
			parent->right = add(parent->right, value);
		}
	} else {
		parent = new TreeItem();
		parent->data = value;
	}
	return parent;
}

TreeItem* Tree::find(TreeItem*parent, int value)
{
	TreeItem* tmp = parent;
	if (tmp) {
		if (tmp->data > value) {
			return find(tmp->left, value);
		} else if (tmp->data < value) {
			return find(tmp->right, value);
		}
	}
	return tmp;
}
