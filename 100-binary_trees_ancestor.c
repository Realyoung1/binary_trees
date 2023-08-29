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
  * node_depth - funcs that count the levels of the Binary treess
  * @tree: roots node of the BT
  * Return: Nothings
  */

size_t node_depth(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + node_depth(tree->parent));
}

/**
  * binary_tree_depth - funcs that measures the depths of a nodes
  * @tree: rootss node of the BT
  * Return: Nothings
  */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (node_depth(tree) - 1);
}

/**
  * binary_trees_ancestor -  funcs that finds the ancestor of given node
  * @first: first nodess
  * @second: second nodess
  * Return: ancestor nodess
  */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									const binary_tree_t *second)
{
	size_t first_depth = 0, second_depth = 0;

	if (first == NULL || second == NULL)
		return (NULL);

	first_depth = binary_tree_depth(first);
	second_depth = binary_tree_depth(second);
	while (first && second)
	{
		if (first_depth > second_depth)
		{
			first_depth -= 1;
			first = first->parent;
		}
		else if (second_depth > first_depth)
		{
			second_depth -= 1;
			second = second->parent;
		}
		else
		{
			if (first == second)
				return ((binary_tree_t *) first);
			first = first->parent;
			second = second->parent;
		}

	}
	return (NULL);
}
