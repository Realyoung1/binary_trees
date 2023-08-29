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
  * binary_tree_is_leaf - funcs Checking if the bnode is a leafss
  * @node: nodess of the BT
  * Return: 1 if a node is a leaf otherwise 0
  */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node)
		return (0);

	if (!(node->left) && !(node->right))
		return (1);

	return (0);
}
