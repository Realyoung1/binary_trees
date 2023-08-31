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
 * array_to_avl -  tree from an array.
 * @array: A pointer to the first the array to be converted.
 * @size: The number of elements in @array.
 *
 * Return: A pointer to the root nodthe created AVL, or NULL upon failure.
 */

avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t q, w;

	if (array == NULL)
		return (NULL);

	for (q = 0; q < size; q++)
	{
		for (w = 0; w < q; w++)
		{
			if (array[w] == array[q])
				break;
		}
		if (w == q)
		{
			if (avl_insert(&tree, array[q]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
