/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct node {
	int data;
	struct node * lchild;
	struct node * rchild;
};

void inorder(struct node *);
void inorder_descending(struct node*);
int tree_depth(struct node *);
struct node * insert_node(struct node **, int);
struct node * modified_search(struct node *, int);

void main() {
	srand((unsigned int)time(NULL));
	struct node * root = NULL;
	for (int i = 0; i < 20; i++)
		root = insert_node(&root, rand() % 1000 + 1);

	printf("Tree 오름차순 : ");
	inorder(root);
	printf("\n");


	printf("Tree 내림차순 : ");
	inorder_descending(root);
	printf("\n");

	printf("Tree 높이 : %d\n", tree_depth(root));
}

void inorder(struct node *ptr)
{
	if (ptr) {
		inorder(ptr->lchild);
		printf("%d ", ptr->data);
		inorder(ptr->rchild);
	}
}

void inorder_descending(struct node *ptr)
{
	if (ptr) {
		inorder_descending(ptr->rchild);
		printf("%d ", ptr->data);
		inorder_descending(ptr->lchild);
	}
}


int tree_depth(struct node * ptr) {
	if (ptr == NULL)
		return 0;
	int ldepth = tree_depth(ptr->lchild);
	int rdepth = tree_depth(ptr->rchild);

	return 1 + (ldepth > rdepth ? ldepth : rdepth);
}
struct node * insert_node(struct node ** root, int num) {
	struct node * ptr, *parent = modified_search(*root, num);
	if (parent || !(*root)) {
		ptr = (struct node *)malloc(sizeof(struct node));
		ptr->data = num;
		ptr->lchild = ptr->rchild = NULL;
		if (*root)
			if (num < parent->data)
				parent->lchild = ptr;
			else
				parent->rchild = ptr;
		else
			*root = ptr;
	}
	return *root;
}

struct node * modified_search(struct node * root, int key) {
	struct node * parent, *child;

	if (root == NULL || root->data == key)
		return NULL;
	parent = root;
	child = (parent->data > key) ? parent->lchild : parent->rchild;
	while (child != NULL) {
		if (key == child->data)
			return NULL;
		parent = child;
		if (key > child->data)
			child = child->rchild;
		else
			child = child->lchild;
	}
	return parent;
}
*/