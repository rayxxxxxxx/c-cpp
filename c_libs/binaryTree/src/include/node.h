#ifndef NODE_H
#define NODE_H

typedef struct Node
{
	int data;
	struct Node *parent;
	struct Node *left;
	struct Node *right;
} Node;

Node *make_node(int data);
Node *copy_node(Node *node);
void delete_node(Node *node);
void delete_node_r(Node *node);

#endif