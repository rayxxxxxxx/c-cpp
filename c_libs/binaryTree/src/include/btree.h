#ifndef CBTREE_H
#define CBTREE_H

#include <stdbool.h>

#include "Node.h"

void delete_btree(Node *root);

bool has(Node *root, int data);
Node *find(Node *root, int data);

Node *max_left(Node *root);	 // node with BIGGEST value in LEFT subtree of given node
Node *min_right(Node *root); // node with SMALLEST value in RIGHT subtree of given node

bool add(Node *root, int data);
bool remove_item(Node *root, int data); // find and remove specific value
bool remove_node(Node *root);			// remove node itself

Node *rotate_left(Node *node);	// left rotation operation
Node *rotate_right(Node *node); // right rotation operation

#endif