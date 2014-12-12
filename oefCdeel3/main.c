#include <stdio.h>
#include "tree.h"

int main()
{
	struct Tree* tree = tree_create();
	tree_insert(tree, 8);
	// tree_insert(tree, 3);
	// tree_insert(tree, 10);
	tree_print(tree);
	return 0;
}
