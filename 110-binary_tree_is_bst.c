#include "binary_trees.h"
#include "limits.h"

/**
 * is_bst_helper - Checks if a binary tree is a valid binary search tree or not
 * @tree: A pointer to the root node
 * @min: The value of the smallest node
 * @max: The value of the largest node
 *
 * Return: 1 If the tree is a valid BST, 0 otherwise
 */
int is_bst_helper(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (is_bst_helper(tree->left, min, tree->n - 1) &&
		is_bst_helper(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid binary search tre or not
 * @tree: A pointer to the root node
 *
 * Return: 1 if tree is a valid BST, else return 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		return (is_bst_helper(tree, INT_MIN, INT_MAX));
	}
	return (0);
}
