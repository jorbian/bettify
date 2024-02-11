#include "avl_trees.h"

static avl_t *__bst_insert(avl_t *root, avl_t *new);

/**
 * push_to_correct_side - pushes the node to the side it goes on
 * @root: current root node of the tree
 * @new: the new node that we're currently adding
 *
 * Return: the balance factor with new node.
*/
static int push_to_correct_side(avl_t *root, avl_t *new)
{
	if (new->n > root->n)
		root->right = __bst_insert(root->right, new);
	else
		root->left = __bst_insert(root->left, new);

	return (
		(root != NULL) ? (
			(binary_tree_height(root->left) - binary_tree_height(root->right))
		) : 1
	);
}

/**
 * __bst_insert - inserts a node as a BST then balances it
 * @root: pointer to the root node of a tree
 * @new: double pointer to the new node to add
 *
 * Return: Root of the tree
 */
static avl_t *__bst_insert(avl_t *root, avl_t *new)
{
	int balance_factor = 0;

	if (!new)
		return (NULL);
	if (!root)
		return (root = new);

	if (new->n == root->n)
	{
		free(new);
		return (new = root);
	}
	new->parent = root;

	balance_factor = push_to_correct_side(root, new);

	if (balance_factor > 1)
	{
		if (new->n < root->left->n)
			root = binary_tree_rotate_right(root);
		else
		{
			root->left = binary_tree_rotate_left(root->left);
			root = binary_tree_rotate_right(root);
		}
	}
	if (balance_factor < -1)
	{
		if (new->n > root->right->n)
			root = binary_tree_rotate_left(root);
		else
		{
			root->right = binary_tree_rotate_right(root->right);
			root =  binary_tree_rotate_left(root);
		}
	}
	return (root);
}

/**
* avl_insert - adds a new node to an AVL tree
* @tree: pointer to the root of a tree
* @value:value to be stored in the node
* Return: the new node
*/
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new, *root;

	new = binary_tree_node(NULL, value);
	if (new == NULL)
		return (NULL);

	if (*tree == NULL)
		return (*tree = new);

	root = __bst_insert(*tree, new);
	*tree = root;

	return (new);
}
