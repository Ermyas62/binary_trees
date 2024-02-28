#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _binary_tree_sibling - finds sibling of a node
 * @node: pointer to the node whose sibling you are looking for
 *
 * Return: pointer to sibling or NULL if not found
 */
binary_tree_t *_binary_tree_sibling(binary_tree_t *node)
{
	if (node && node->parent && node->parent->left && node->parent->right)
	{
		if (node->parent->left == node)
			return (node->parent->right);
		return (node->parent->left);
	}
	return (NULL);
}

/**
 * binary_tree_uncle - Where node is a pointer to node to find the uncle
 * @node: pointer to the node to find the uncle
 *
 * Return: pointer to the uncle node
 * NULL, If node is NULL or If node has no uncle.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node)
		return (NULL);

	if (_binary_tree_sibling(node->parent))
		return (_binary_tree_sibling(node->parent));
	return (NULL);

}
