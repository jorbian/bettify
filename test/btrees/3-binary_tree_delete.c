#include "binary_trees.h"

/**
 * binary_tree_delete - uses postorder traversal to delete binary tree
 * @tree: root of the tree that needs to be deleted.
*/
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;

	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);

	free(tree);
}
