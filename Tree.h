#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
#include "Common.h"

// ===================
//   DATA ATTRIBUTE
// ===================
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


// ===================
//       MODUL
// ===================

/* Make new tree */
// PIC : Aini
Root* make_root_node();

/* Allocate new node */
// PIC : Helsa
addressTree make_tree_node();

/* Determine addition of children */
// PIC : Mey
addressTree make_child(addressTree pare_node, Data datum, int isChar);

/* Add node as right children */
// PIC : Helsa
void make_left_child(addressTree pare_node, Data datum, int isChar);

/* Add node as right children */
// PIC : Aini
void make_right_child(addressTree pare_node, Data datum, int isChar);

/* Print a node */
// PIC : Helsa
void print_data(Data datum, int isChar);

/* Choose mode of traversal */
// PIC : Mey
void traversal(Root *root, int mode);

/* Print with preorder traversal */
// PIC : Aini
void preorder_traversal(addressTree tNode);

/* Print with inorder traversal */
// PIC : Helsa
void inorder_traversal(addressTree tNode);

/* Print with postorder traversal */
// PIC : Mey
void postorder_traversal(addressTree tNode);

/* Remove a node */
// PIC : Aini
void remove_all_tree_nodes(Root* root);

/* Remove a tree */
// PIC : Mey
void remove_tree_node(addressTree tNode);

#endif // TREE_H_INCLUDED
