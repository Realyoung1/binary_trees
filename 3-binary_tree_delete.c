#include "binary_trees.h"

/**
  * binary_tree_delete - funcs Deleting the entires Binary treess
  * @tree: root nodess
  * Return: Nothings
  */

void binary_tree_delete(binary_tree_t *tree)
{
	if (!tree)
		return;

	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);
	free(tree);
}
