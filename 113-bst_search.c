#include "binary_trees.h"

/**
 * bst_search - Searches a value from binary search tree
 * @tree: A pointer to the root node
 * @value: The value to be searched in the BST
 *
 * Return: NULL If the tree is NULL or the value not found
 *         ELSE, a pointer to the node
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (tree->n == value)
		return ((bst_t *)tree);

	return (tree->n > value
			? bst_search(tree->left, value) : bst_search(tree->right, value));
}
