#ifndef NODE_H // header guards
#define NODE_H

struct TreeNode {
	int data;
	struct TreeNode* lNode;
	struct TreeNode* rNode;
};

struct TreeNode* newNode(int data);

struct TreeNode *lca(struct TreeNode* root, int n1, int n2);

class ListNode {
public:
	ListNode* next;
	int data;
};

ListNode* newListNode(int data);

// Adding next node
ListNode* addNode(ListNode* currentNode, ListNode* nextNode);

#endif
