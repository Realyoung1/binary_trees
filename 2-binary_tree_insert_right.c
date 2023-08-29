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
  * binary_tree_insert_right - funcs Inserting a node on right of Binary treess
  * @parent: nodes parentss
  * @value: keys to insert in the new nodess
  * Return: the address of thes new nodess
  */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *newright_node = NULL;

	if (!parent)
		return (NULL);

	newright_node = binary_tree_node(parent, value);
	if (!newright_node)
		return (NULL);

	if (parent->right)
	{
		parent->right->parent = newright_node;
		newright_node->right = parent->right;
	}
	parent->right = newright_node;

	return (newright_node);
}
