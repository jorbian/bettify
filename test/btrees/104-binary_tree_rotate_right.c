#include "binary_trees.h"

#define NEW 0
#define OLD 1

/**
 * binary_tree_rotate_right - Rotates a binary search tree clockwise
 * @tree: The binary search tree to rotate
 *
 * Return: The newly rotated binary search tree
*/
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *roots[2];
	binary_tree_t *dangling_node;

	if (!tree || !tree->left)
		return (tree);

	roots[OLD] = tree;
	roots[NEW] = roots[OLD]->left;

	dangling_node = roots[NEW]->right;

	roots[NEW]->parent = roots[OLD]->parent;
	roots[NEW]->right = roots[OLD];

	roots[OLD]->parent = roots[NEW];
	roots[OLD]->left = dangling_node;

	if (dangling_node != NULL)
		dangling_node->parent = roots[OLD];

	return (roots[NEW]);
}
