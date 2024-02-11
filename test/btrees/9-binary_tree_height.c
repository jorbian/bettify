#include "binary_trees.h"

#define NODE_EXISTS(n) ((n) ? 1 + binary_tree_height(n) : 0)

/**
 * measure_branches - measure the subbranches of the tree
 * @tree: node of the root or sub-root of the tree
 * @counters: pointer to counter array
*/
static void measure_branches(const binary_tree_t *tree, int *counters)
{
	counters[LEFT] = NODE_EXISTS(tree->left);
	counters[RIGHT] = NODE_EXISTS(tree->right);
}

/**
 * binary_tree_height - Measures the height of binary tree.
 * @tree: Pointer to root node to measure the height.
 *
 * Return: Tree is NULL, function returns 0, else returns the height.
 */
int binary_tree_height(const binary_tree_t *tree)
{
	int counters[2];

	if (tree == NULL)
		return (0);

	measure_branches(tree, (int *)&counters);

	return (
		MAX(counters[LEFT], counters[RIGHT])
	);
}
