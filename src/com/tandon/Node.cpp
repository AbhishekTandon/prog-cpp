#include <iostream>
#include "Node.h"

/* Helper function that allocates a new node with the given data.*/
struct TreeNode* newNode(int data) {
	struct TreeNode* node; //= (struct node*) malloc(sizeof(struct node));
	node->data = data;
	node->lNode = node->rNode = NULL;
	return (node);
}

/* Function to find LCA of n1 and n2. The function assumes that both
 n1 and n2 are present in BST */
struct TreeNode *lca(struct TreeNode* root, int n1, int n2) {
	if (root == NULL)
		return NULL;

	// If both n1 and n2 are smaller than root, then LCA lies in left
	if (root->data > n1 && root->data > n2)
		return lca(root->lNode, n1, n2);

	// If both n1 and n2 are greater than root, then LCA lies in right
	if (root->data < n1 && root->data < n2)
		return lca(root->rNode, n1, n2);

	return root;
}

/**
 * Helper functions for single linked list node
 */

ListNode* newListNode(int data) {
	ListNode* node = new ListNode();

	node->data = data;
	node->next = NULL;
	return node;
} ;

// Adding next node
ListNode* addNode(ListNode* currentNode, ListNode* nextNode) {
	currentNode->next = nextNode;
	return (currentNode->next);
}

