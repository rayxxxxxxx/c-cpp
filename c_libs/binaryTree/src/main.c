#include <stdio.h>

#include "btree.h"

void printBTree_preorder(Node *root);
void printBTree_inorder(Node *root);
void printBTree_postorder(Node *root);

int main(int argc, char *args[])
{
	Node *root = make_node(100);
	add(root, 50);
	add(root, 200);
	add(root, 25);
	add(root, 75);
	add(root, 150);
	add(root, 125);
	add(root, 175);
	add(root, 300);
	add(root, 250);
	add(root, 400);

	printBTree_inorder(root);
	printf("\n");

	rotate_left(root->right);
	printBTree_inorder(root);
	printf("\n");

	printf("%d\n", root->right->data);
	printf("%d\n", root->right->left->data);
	printf("%d\n", root->right->right->data);
	printf("%d\n", root->right->parent->data);
	printf("%d\n", root->right->left->parent->data);

	delete_btree(root);

	return 0;
}

void printBTree_preorder(Node *root)
{
	if (root)
	{
		printf("%d ", root->data);
		printBTree_preorder(root->left);
		printBTree_preorder(root->right);
	}
}

void printBTree_inorder(Node *root)
{
	if (root)
	{
		printBTree_inorder(root->left);
		printf("%d ", root->data);
		printBTree_inorder(root->right);
	}
}

void printBTree_postorder(Node *root)
{
	if (root)
	{
		printBTree_postorder(root->left);
		printBTree_postorder(root->right);
		printf("%d ", root->data);
	}
}