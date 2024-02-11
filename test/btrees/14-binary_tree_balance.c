#include "binary_trees.h"

#define NODE_EXISTS(n) ((n != NULL) ? binary_tree_height(n) : 0)

/**
 * measure_branches - measure the subbranches of the tree
 * @tree: node of the root or sub-root of the tree
 * @counters: pointer to counter array
*/
static void measure_branches(const binary_tree_t *tree, int *counters)
{
	counters[LEFT] = NODE_EXISTS(tree->left) + 1;
	counters[RIGHT] = NODE_EXISTS(tree->right) + 1;
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: node the tree is being measured from
 *
 * Return: Whatever the height is supposed to be.
*/
int binary_tree_height(const binary_tree_t *tree)
{
	int counters[2];

	if (tree == NULL)
		return (0);

	measure_branches(tree, counters);

	return (
		MAX(counters[LEFT], counters[RIGHT])
	);
}

/**
 * binary_tree_balance - Measure balance factor of binary tree.
 * @tree: A pointer to the root node of the tree to measure the balance factor.
 *
 * Return: If tree is NULL, returns 0, else returns balance factor.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (
		binary_tree_height(tree->left) - binary_tree_height(tree->right)
	);
}
