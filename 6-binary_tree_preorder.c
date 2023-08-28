#include "binary_trees.h"

/**
  * binary_tree_preorder - funcs that Goes through a binary treess using pre-order traversalss
  * @tree: rootss node of the BT
  * @func: functionss to print the traverses
  * Return: Nothings
  */

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{

	if (!tree || !func)
		return;

	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
