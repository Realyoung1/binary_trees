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
 * bst_insert - inserteds a value in a Binary earch Treess
 * @tree: double pointerss to the root node of the BST to insert the valuees
 * @value: value to store in the node to be insertess
 * Return: Always 0 (Success)
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *aux = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	aux = *tree;
	if (value < aux->n)
	{
		if (aux->left == NULL)
		{
			aux->left = binary_tree_node(aux, value);
			return (aux->left);
		}
		return (bst_insert(&(aux->left), value));
	}
	if (value > aux->n)
	{
		if (aux->right == NULL)
		{
			aux->right = binary_tree_node(aux, value);
			return (aux->right);
		}
		return (bst_insert(&(aux->right), value));
	}
	return (NULL);
}
