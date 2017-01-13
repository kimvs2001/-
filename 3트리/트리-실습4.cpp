#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *lchild;
	struct node *rchild;
};

struct node *make_tree();
struct node *search(struct node *, int);
struct node *modified_search(struct node *, int);

void inorder(struct node *);
void preorder(struct node *);
void postorder(struct node *);

void main()
{
	struct node *root = make_tree();
	int input_data;

	printf("검색할 수? ");
	scanf("%d", &input_data);
	struct node *ptr = search(root, input_data);

	if (ptr != NULL)
		printf("%d의 검색 결과 = %d\n", input_data, ptr->data);
	else
		printf("%d: 트리에 없습니다.\n", input_data);

	printf("추가할 수? ");
	scanf("%d", &input_data);
	ptr = modified_search(root, input_data);

	if (root == NULL)
		printf("루트에 추가하면 됩니다.\n");
	else if (ptr == NULL)
		printf("중복된 수가 트리에 있으므로, 추가할 수 없습니다\n");
	else
		printf("%d의 자식 노드에 추가하면 됩니다\n", ptr->data);
}


struct node *make_tree()
{
	struct node *ptr[7];

	for (int i = 0; i < 7; i++) {
		ptr[i] = (struct node *)malloc(sizeof(struct node));
		ptr[i]->lchild = ptr[i]->rchild = NULL;
	}

	ptr[0]->data = 8;
	ptr[1]->data = 4;
	ptr[2]->data = 15;
	ptr[3]->data = 2;
	ptr[4]->data = 5;
	ptr[5]->data = 13;
	ptr[6]->data = 11;

	ptr[0]->lchild = ptr[1];
	ptr[0]->rchild = ptr[2];
	ptr[1]->lchild = ptr[3];
	ptr[1]->rchild = ptr[4];
	ptr[2]->lchild = ptr[5];
	ptr[5]->lchild = ptr[6];

	return ptr[0];
}

struct node *search(struct node *tree, int key)
{
	while (tree) {
		if (key == tree->data) 
			return tree;
		if (key < tree->data)
			tree = tree->lchild;
		else
			tree = tree->rchild;
	}
	return NULL;
}

struct node *modified_search(struct node *root, int key)
{
	struct node *parent, *child;

	if (root == NULL || root->data == key)
		return NULL;
	
	parent = root;
	child = (root->data < key) ? root->rchild : root->lchild;
	while (child != NULL) {
		if (key == child->data)
			return NULL;
		parent = child;
		if (key < child->data)
			child = child->lchild;
		else
			child = child->rchild;
	}
	return parent;
}

void inorder(struct node *ptr)
{
	if (ptr) {
		inorder(ptr->lchild);
		printf("%d ", ptr->data);
		inorder(ptr->rchild);
	}
}

void preorder(struct node *ptr)
{
	if (ptr) {
		printf("%d ", ptr->data);
		preorder(ptr->lchild);
		preorder(ptr->rchild);
	}
}

void postorder(struct node *ptr)
{
	if (ptr) {
		postorder(ptr->lchild);
		postorder(ptr->rchild);
		printf("%d ", ptr->data);
	}
}