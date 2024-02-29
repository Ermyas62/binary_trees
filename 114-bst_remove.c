#include "binary_trees.h"
#include <stdlib.h>

bst_t *bst_delete(const bst_t *root, bst_t *node);
bst_t *bst_node_search(const bst_t *root, bst_t *tree, int value);
bst_t *inorder_successor(bst_t *node);
bst_t *bst_remove(bst_t *root, int value);

/**
 * bst_node_search - Searches for a node or a value to be removed
 * from binary search tree.
 * @root: A pointer to the root node
 * @tree:  A pointer to the current node
 * @value: The value to be searched from the BST
 *
 * Return: NULL If the tree is NULL or the value isn't found
 *         else a pointer to the root node after deleting
 */
bst_t *bst_node_search(const bst_t *root, bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (tree->n == value)
		return (bst_delete(root, tree));

	return (tree->n > value
			? bst_node_search(root, tree->left, value) :
			bst_node_search(root, tree->right, value));
}

/**
 * inorder_successor - Returns the smallest value
 * @node: A pointer to the root node
 *
 * Return: The minimum value in the tree
 */
bst_t *inorder_successor(bst_t *node)
{
	while (node->left != NULL)
		node = node->left;
	return (node);
}

/**
 * bst_delete - Deletes a node from the binary search tree.
 * @root: A pointer to the root node
 * @node: A pointer to the node to be deleted
 *
 * Return: A pointer to the new root node after deleting
 */
bst_t *bst_delete(const bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *successor = NULL;

	if (node->left == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->right;
		else if (parent != NULL)
			parent->right = node->right;
		if (node->right != NULL)
			node->right->parent = parent;
		free(node);
		return (parent == NULL ? node->right : (bst_t *)root);
	}

	if (node->right == NULL)
	{
		if (parent != NULL && parent->right == node)
			parent->right = node->left;
		else if (parent != NULL)
			parent->left = node->left;
		if (node->left != NULL)
			node->left->parent = parent;
		free(node);
		return (parent == NULL ? node->left : (bst_t *)root);
	}

	successor = inorder_successor(node->right);
	node->n = successor->n;

	return (bst_delete(root, successor));
}

/**
 * bst_remove - Removes a node from a binary tree
 * @root: A pointer to the root node to remove a node from
 * @value: The value to remove
 *
 * Return: A pointer to the new root node
 *
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_node_search(root, root, value));
}
