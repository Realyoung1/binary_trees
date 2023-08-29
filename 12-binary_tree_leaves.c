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
  * binary_tree_leaves - funcs counting the leaves in a binary treess
  * @tree: roots node of the BT
  * Return: numbers of leaves
  */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaf = 0;

	if (!tree)
		return (0);

	if (!(tree->left) && !(tree->right))
		leaf = 1;

	leaf += binary_tree_leaves(tree->left);
	leaf += binary_tree_leaves(tree->right);

	return (leaf);
}
