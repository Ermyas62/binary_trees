#include "binary_trees.h"

/**
 * array_to_bst - Builds a binary search tree from
 * the given  array
 * @array: A pointer to the first element of the array
 * to be converted to the binary search
 * @size: The number of elements of an array
 *
 * Return: A pointer to the root node of the created BST, else NULL if failure.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	unsigned int i;

	if (array == NULL)
		return (NULL);

	root = binary_tree_node(NULL, array[0]);
	for (i = 1; i < size; i++)
		bst_insert(&root, array[i]);

	return (root);
}
