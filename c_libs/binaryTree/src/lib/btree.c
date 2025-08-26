#include <stdlib.h>

#include "btree.h"

void delete_btree(Node *root)
{
	delete_node_r(root);
}

bool has(Node *root, int data)
{
	Node *curr_node = root;
	while (curr_node)
	{
		if (curr_node->data == data)
			return true;
		else if (data < curr_node->data)
			curr_node = curr_node->left; // step down in left subtree
		else
			curr_node = curr_node->right; // step down in right subtree
	}
	return false;
}

Node *find(Node *root, int data)
{
	Node *curr_node = root;
	while (curr_node)
	{
		if (curr_node->data == data)
			return curr_node;
		else if (data < curr_node->data)
			curr_node = curr_node->left; // step down in left subtree
		else
			curr_node = curr_node->right; // step down in right subtree
	}
	return NULL;
}

Node *max_left(Node *root)
{
	Node *curr_node = root->left; // start with left child
	while (curr_node->right != NULL)
		curr_node = curr_node->right; // step down in right subtree
	return curr_node;
}

Node *min_right(Node *root)
{
	Node *curr_node = root->right; // start with right child
	while (curr_node->left != NULL)
		curr_node = curr_node->left; // step down in left subtree
	return curr_node;
}

bool add(Node *root, int data)
{
	if (has(root, data))
		return false;

	Node *newnode = make_node(data);
	while (true)
	{
		if (data <= root->data) // step down in left subtree
		{
			if (root->left == NULL)
			{
				newnode->parent = root;
				root->left = newnode;
				return true;
			}
			root = root->left;
		}
		else if (data > root->data) // step down in right subtree
		{
			if (root->right == NULL)
			{
				newnode->parent = root;
				root->right = newnode;
				return true;
			}
			root = root->right;
		}
	}
}

bool remove_node(Node *node)
{
	if (node == NULL)
		return false;

	if (!node->left && !node->right) // current node is a leaf node
	{
		if (node == node->parent->left)
			node->parent->left = NULL;
		else
			node->parent->right = NULL;
		delete_node(node);
	}
	else if (!node->left && node->right) // current node has only right child
	{
		if (node == node->parent->left)
			node->parent->left = node->right;
		else
			node->parent->right = node->right;
		delete_node(node);
	}
	else if (!node->right && node->left) // current node has only left child
	{
		if (node == node->parent->left)
			node->parent->left = node->left;
		else
			node->parent->right = node->left;
		delete_node(node);
	}
	else // current node has both left and right children
	{
		Node *substnode = min_right(node);
		node->data = substnode->data; // copy data
		remove_node(substnode);		  // getting rid of duplicate data
	}

	return true;
}

bool remove_item(Node *root, int data)
{
	Node *node = find(root, data);
	return remove_node(node);
}

Node *rotate_left(Node *node)
{
	if (node->right == NULL)
		return node;

	Node *tmp = node->right;
	node->right = tmp->left;
	tmp->left = node;

	// reassigning parent links
	if (node == node->parent->left)
		node->parent->left = tmp;
	else
		node->parent->right = tmp;
	tmp->parent = node->parent;
	node->parent = tmp;

	return tmp;
}

Node *rotate_right(Node *node)
{
	if (node->left == NULL)
		return node;

	Node *tmp = node->left;
	node->left = tmp->right;
	tmp->right = node;

	// reassigning parent links
	if (node == node->parent->left)
		node->parent->left = tmp;
	else
		node->parent->right = tmp;
	tmp->parent = node->parent;
	node->parent = tmp;

	return tmp;
}