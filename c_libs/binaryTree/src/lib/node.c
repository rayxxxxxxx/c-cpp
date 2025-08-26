#include <stddef.h>
#include <stdlib.h>

#include "Node.h"

Node *make_node(int data)
{
	Node *node = (Node *)calloc(1, sizeof(Node));
	node->data = data;
	node->parent = NULL;
	node->left = NULL;
	node->right = NULL;
	return node;
}

Node *copy_node(Node *node)
{
	Node *newnode = (Node *)calloc(1, sizeof(Node));
	newnode->data = node->data,
	newnode->parent = node->parent,
	newnode->left = node->left,
	newnode->right = node->right;
	return newnode;
}

void delete_node(Node *node)
{
	free(node);
}

void delete_node_r(Node *node)
{
	if (node == NULL)
		return;

	// recurcively delete nodes
	// remove left and right BEFORE removing current!
	delete_node_r(node->left);
	delete_node_r(node->right);
	free(node);
}