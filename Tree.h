#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
#include "Common.h"

typedef struct TreeNode *addressTree;

typedef struct TreeNode
{
	int isChar;
	Data data;
	addressTree parent;
	addressTree left;
	addressTree right;
} TreeNode;

typedef struct Root
{
	addressTree root;
} Root;

Root* make_root_node();
addressTree make_tree_node();
addressTree make_child(addressTree pare_node, Data datum, int isChar);
void make_left_child(addressTree pare_node, Data datum, int isChar);
void make_right_child(addressTree pare_node, Data datum, int isChar);
void print_data(Data datum, int isChar);
void traversal(Root *root, int mode);
void preorder_traversal(addressTree tNode);
void inorder_traversal(addressTree tNode);
void postorder_traversal(addressTree tNode);
void remove_all_tree_nodes(Root* root);
void remove_tree_node(addressTree tNode);
#endif // TREE_H_INCLUDED
