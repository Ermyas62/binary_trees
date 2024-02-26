#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * binary_tree_is_root - check if a node is a root
 * @node: pointer to node to check
 *
 * Return: 1 if node is a root, otherwise 0
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node != NULL)
		{
			if (node->parent == NULL)
				return (1);
		}
	return (0);
}
