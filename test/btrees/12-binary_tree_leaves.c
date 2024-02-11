#include <stdbool.h>

#include "binary_trees.h"

/**
 * count - recursively count something about the nodes up and down the tree
 * @tree: pointer to the node we start counting at
 * @thing: boolean search value for what we're counting
 *
 * Return: However many nodes matched the boolean search in thing.
*/
static size_t count(binary_tree_t *tree, bool (*thing)(binary_tree_t *))
{
	if (tree == NULL)
		return (0);

	return ((
		thing(tree) +
		count(tree->left, thing) +
		count(tree->right, thing)
	));
}

/**
 * both_children_empty - are BOTH of the child nodes empty
 * @tree: pointer to the node we're checking
 *
 * Return: True or false -- is it empty? --
*/
static bool both_children_empty(binary_tree_t *tree)
{
	if ((tree->left || tree->right))
		return (false);

	return (true);
}

/**
 * binary_tree_leaves - Recursive function to count tye leaves of tree
 * @tree: A pointer to the root node of the tree to count the leaves of.
 *
 * Return: The number of nodes in tree.
 */
size_t binary_tree_leaves(binary_tree_t *tree)
{
	return (count(tree, both_children_empty));
}
