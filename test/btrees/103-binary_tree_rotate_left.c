#include "binary_trees.h"

#define NEW 0
#define OLD 1

/**
 * binary_tree_rotate_left - Rotates a binary search tree clockwise
 * @tree: The binary search tree to rotate
 *
 * Return: The newly rotated binary search tree
*/
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *roots[2];
	binary_tree_t *dangling_node;

	if (!tree || !tree->right)
		return (tree);

	roots[OLD] = tree;
	roots[NEW] = roots[OLD]->right;

	dangling_node = roots[NEW]->left;

	roots[NEW]->parent = roots[OLD]->parent;
	roots[NEW]->left = roots[OLD];

	roots[OLD]->parent = roots[NEW];
	roots[OLD]->right = dangling_node;

	if (dangling_node != NULL)
		dangling_node->parent = roots[OLD];

	return (roots[NEW]);
}
