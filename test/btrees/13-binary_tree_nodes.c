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
 * at_least_one_child - Does a node have at least one child?
 * @tree: pointer to the node we're looking at.
 *
 * Return: True or False if it has at least once child.
*/
static bool at_least_one_child(binary_tree_t *tree)
{
	if ((tree->left || tree->right))
		return (true);

	return (false);
}

/**
 * binary_tree_nodes - Recursive function to count tye leaves of tree
 * @tree: A pointer to the root node of the tree to count the leaves of.
 *
 * Return: The number of nodes in tree.
 */
size_t binary_tree_nodes(binary_tree_t *tree)
{
	return (count(tree, at_least_one_child));
}
