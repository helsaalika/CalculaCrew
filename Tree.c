#include "Tree.h"

/* Make new tree */
// PIC : Aini
Root* make_root_node()
{
	Root* tmp = (Root*)calloc(sizeof(Root), 1);
	if(!tmp) {
		puts("memory is full-using.");
		exit(1);
	}
	return tmp;
}

/* Allocate new node */
// PIC : Helsa
addressTree make_tree_node()
{
	addressTree tmp = (addressTree)calloc(sizeof(TreeNode), 1);
	if(!tmp){
		puts("memory is full-using.");
		exit(1);
	}
	return tmp;
}

/* Determine addition of children */
// PIC : Mey
/** \brief
 *
 * \param pare_node : parent node
 * \param datum : input data1
 * \param isChar : input data2
 * \return self node or new child node
 *
 */
addressTree make_child(addressTree pare_node, Data datum, int isChar)
{
	if(!pare_node)
	{
		pare_node = make_tree_node();
		pare_node->data = datum;
		pare_node->isChar = isChar;
		return pare_node;
	}
	if(pare_node->left && pare_node->right)
	{
		pare_node = pare_node->parent;
		if(!pare_node)	return NULL;
		return make_child(pare_node, datum, isChar);
	}

	if(!isChar) // number, from right. return self node pointer.
	{
		if(pare_node->right)
		{
			make_left_child(pare_node, datum, isChar);
		}
		else
		{
			make_right_child(pare_node, datum, isChar);
		}
		return pare_node;
	}
	else // operator, from left. return its child node pointer.
	{

		if(pare_node->right)
		{
			make_left_child(pare_node, datum, isChar);
			return pare_node->left;
		}
		else
		{
			make_right_child(pare_node, datum, isChar);
			return pare_node->right;
		}
	}
}

/* Add node as right children */
// PIC : Helsa
void make_left_child(addressTree pare_node, Data datum, int isChar)
{
	addressTree tmp = make_tree_node();
	if(!tmp)	return;
	tmp->data = datum;
	tmp->isChar = isChar;
	pare_node->left = tmp;
	tmp->parent = pare_node;
}

/* Add node as right children */
// PIC : Aini
void make_right_child(addressTree pare_node, Data datum, int isChar)
{
	addressTree tmp = make_tree_node();
	if(!tmp)	return;
	tmp->data = datum;
	tmp->isChar = isChar;
	pare_node->right = tmp;
	tmp->parent = pare_node;
}

/* Print a node */
// PIC : Helsa
void print_data(Data datum, int isChar)
{
	if(isChar) {
		printf("%c", datum.opr);
	}
	else {
		printf("%g", datum.num);
	}
}

/* Choose mode of traversal */
// PIC : Mey
void traversal(Root *root, int mode)
{
	addressTree tmp = root->root;
	switch(mode)
	{
		case PREORDER:
			preorder_traversal(tmp);
			break;
		case INORDER:
			inorder_traversal(tmp);
			break;
		case POSTORDER:
			postorder_traversal(tmp);
			break;
	}
}

/* Print with preorder traversal */
// PIC : Aini
void preorder_traversal(addressTree tNode)
{
	if(!tNode)	return;
	print_data(tNode->data, tNode->isChar);
	preorder_traversal(tNode->left);
	preorder_traversal(tNode->right);
}

/* Print with inorder traversal */
// PIC : Helsa
void inorder_traversal(addressTree tNode)
{
	if(!tNode)	return;
	inorder_traversal(tNode->left);
	print_data(tNode->data, tNode->isChar);
	inorder_traversal(tNode->right);
}

/* Print with postorder traversal */
// PIC : Mey
void postorder_traversal(addressTree tNode)
{
	if(!tNode)	return;
	postorder_traversal(tNode->left);
	postorder_traversal(tNode->right);
	print_data(tNode->data, tNode->isChar);
}

/* Remove a node */
// PIC : Aini
void remove_tree_node(addressTree tNode)
{
	if(!tNode)	return;
	remove_tree_node(tNode->left);
	remove_tree_node(tNode->right);
	free(tNode);
}

/* Remove a tree */
// PIC : Mey
void remove_all_tree_nodes(Root* root)
{
	remove_tree_node(root->root);
}
