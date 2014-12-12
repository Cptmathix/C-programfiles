#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

// Create an empty tree

struct Tree* tree_create()
{
	struct Tree* tree = malloc(sizeof(struct Tree));
	tree->root = NULL;
	return tree;
}

void tree_insert(struct Tree* tree, int value)
{
	struct TreeNode* node = malloc(sizeof(struct TreeNode));
	node->value = value;
	node->left_child = NULL;
	node->right_child = NULL;
	
	if (tree->root == NULL)
		tree->root = node;
	else
	{
		struct TreeNode* treeroot = tree->root;
		int check = 0;
		while (check != 1)
		{
			puts("hey\n");
			struct TreeNode* current = tree->root;
			if (current->value < value)
			{
				if (current->left_child == NULL)
				{
					current->left_child = node;
					node->value = value;
					check = 1;
				}
				else
				{
					tree->root = current->left_child;
				}
			}
			else 
			{
				if (current->right_child == NULL)
				{
					current->right_child = node;
					node->value = value;
					check = 1;
				}
				else
				{
					tree->root = current->right_child;
				}
			}
		}
		puts("hey after\n");
		tree->root = treeroot;
	}
}

void tree_print(struct Tree* tree)
{
	printf("[");
	
	struct TreeNode* current = tree->root;
	
	if (current->left_child == NULL)
	{
		tree->root = current->right_child;
		printf("%i", current->value);
		tree_print(tree);
	}
	else
	{
		tree->root = current->left_child;
		tree_print(tree);
	}
	
	printf("]\n");
}

