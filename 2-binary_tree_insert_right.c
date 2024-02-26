#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts node as the right child
 * @parent - binary_tree_t node
 * @value: int variable
 *
 * Return: new node
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new, *temp;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);
	
	if (parent->right == NULL)
	{
		parent->right = new;
		return (new);
	}
	temp = parent->right;
	parent->right = new;
	new->right = temp;
	temp->parent  = new;

	return (new);
}
