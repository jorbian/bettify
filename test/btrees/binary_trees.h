#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

#define MAX(x, y)  (x - ((x - y) & -(x < y)))
#define BALANCE_F(l, r) (abs(l - r))
#define LR_BALANCE(l, r) (BALANCE_F(l, r) > 1)
#define LEFT 0
#define RIGHT 1

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
} binary_tree_t;

typedef struct binary_tree_s bst_t;

typedef struct binary_tree_s btree_t;

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
void binary_tree_delete(binary_tree_t *tree);
int binary_tree_is_leaf(const binary_tree_t *node);
int binary_tree_is_root(const binary_tree_t *node);
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_print(const binary_tree_t *tree);
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
int binary_tree_height(const binary_tree_t *tree);
size_t binary_tree_depth(const binary_tree_t *tree);
size_t binary_tree_size(const binary_tree_t *tree);
size_t binary_tree_leaves(binary_tree_t *tree);
size_t binary_tree_nodes(binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);
bool binary_tree_is_full(const binary_tree_t *tree);
int binary_tree_is_perfect(const binary_tree_t *tree);
binary_tree_t *binary_tree_sibling(binary_tree_t *node);
binary_tree_t *binary_tree_uncle(binary_tree_t *node);
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);
bool binary_tree_is_avl(const binary_tree_t *tree);
int binary_tree_is_bst(binary_tree_t *tree);
binary_tree_t *bst_insert(binary_tree_t **tree, int value);
int binary_tree_is_complete(const binary_tree_t *tree);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second);

#endif
