#include "Tree.class.hpp"

int main(){

	Btree *tree = new Btree();

	// tree->insert(10);
	// tree->insert(6);
	// tree->insert(14);
	// tree->insert(5);
	// tree->insert(8);
	// tree->insert(11);
	// tree->insert(19);
	// tree->insert(13);
	// tree->insert(7);
	// tree->insert(14);
	// tree->insert(15);
	// tree->insert(7);
	// tree->insert(10);
	// tree->insert(2);
	// tree->insert(5);
	// tree->insert(8);
	// tree->insert(6);
	// tree->insert(4);
	tree->insert(2);
	tree->insert(1);
	tree->insert(3);
	tree->insert(7);
	tree->insert(10);
	tree->insert(2);
	tree->insert(5);
	tree->insert(8);
	tree->insert(6);
	tree->insert(4);

	tree->printInPrettyWay();
	// tree->printInAFantasticWay();
	// tree->printBtree();
	// tree->preorder_print();
	// tree->inorder_print();
	// tree->postorder_print();

	delete tree;

}