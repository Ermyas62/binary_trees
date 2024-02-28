#include "binary_tress.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * binary_tree_preorder - goes through a binary tree using pre-order
 * @tree: pointer to the node
 * @func: a pointer to a function
 *
 * Return: nothing
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree != NULL && func != NULL)
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
