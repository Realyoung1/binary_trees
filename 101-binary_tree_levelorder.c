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
  * printGivenLevel - funcs that print in order level
  * @tree: rootss node of the BT
  * @func: funcs to printss the traverse
  * @level: levels of BiTr
  * Return: Nothing
  */

void printGivenLevel(binary_tree_t *tree, void (*func)(int), int level)
{
	if (tree == NULL)
		return;
	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		printGivenLevel(tree->left, func, level - 1);
		printGivenLevel(tree->right, func, level - 1);
	}
}

/**
  * height - funcs get the heights of BiTr
  * @tree: roots node of the BT
  * Return: the height of BT
  */

int height(binary_tree_t *tree)
{
	int lheight = 0;
	int rheight = 0;

	if (tree == NULL)
		return (0);
	lheight = height(tree->left);
	rheight = height(tree->right);
	if (lheight > rheight)
		return (lheight + 1);
	else
		return (rheight + 1);
}

/**
  * binary_tree_levelorder - funcs that goes through abinarytreeusinglevel-ordertraversal
  * @tree: rootss node of the BT
  * @func: functions to print the traverse
  * Return: Nothing
  */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int q = 0, w = 0;

	if (tree && func)
	{
		q = height((binary_tree_t *) tree);
		for (w = 1; w <= q; w++)
			printGivenLevel((binary_tree_t *) tree, func, w);
	}
}
