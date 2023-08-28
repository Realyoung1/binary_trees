#include "binary_trees.h"

/**
  * binary_tree_insert_left - funcs Inserting a node on left of Binary treess
  * @parent: node parentsss
  * @value: keys to inserts in the new nodess
  * Return: the addresss of the new nodess
  */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *newleft_node = NULL;

	if (!parent)
		return (NULL);

	newleft_node = binary_tree_node(parent, value);
	if (!newleft_node)
		return (NULL);

	if (parent->left)
	{
		parent->left->parent = newleft_node;
		newleft_node->left = parent->left;
	}
	parent->left = newleft_node;

	return (newleft_node);
}
