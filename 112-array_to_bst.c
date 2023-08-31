#include <stdbool.h>
#include <sys/stat.h>
#include <limits.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * array_to_bst - buildings a Binary Search Tree from an array.
 * @array: pointed the first element of the array to be converted.
 * @size: number of element in the array.
 * Return: pointer to the root node of the created BST, or NULL on failure.
 */

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree;
	size_t index;

	if (array == NULL)
		return (NULL);
	tree = NULL;
	for (index = 0; index < size; index++)
	{
		bst_insert(&tree, array[index]);
	}
	return (tree);
}
