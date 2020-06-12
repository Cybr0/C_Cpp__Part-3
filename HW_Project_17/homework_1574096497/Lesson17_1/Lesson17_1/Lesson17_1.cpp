#include <iostream>
#include "Tree.h"

int main()
{
	Tree tree;
	tree.add(3);
	tree.add(6);
	tree.add(1);
	tree.add(2);
	tree.add(5);
	tree.add(7);
	
	tree.show();
	Tree tree2;
	tree2.add_rc(3);
	tree2.add_rc(6);
	tree2.add_rc(1);
	tree2.add_rc(2);
	tree2.add_rc(5);
	tree2.add_rc(7);
	tree2.show();
	TreeItem* res = tree2.find(2);
	if (res) {
		std::cout << res->data << std::endl;
	}

}
