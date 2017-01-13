#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *lchild;
	struct node *rchild;
};

struct node *make_tree();
struct node *copy(struct node *);
void inorder(struct node *);
void preorder(struct node *);
void postorder(struct node *);

void main()
{
	struct node *root = make_tree();
	struct node *C = copy(root);

	printf("inorder: ");
	inorder(C);
	printf("\n");

	printf("preorder: ");
	preorder(C);
	printf("\n");

	printf("postorder: ");
	postorder(C);
	printf("\n");
}

struct node *copy(struct node *original)
{	// original 트리를 복사한 새로운 이진 트리를 반환
	struct node *temp;
	if (original) {
		temp = (struct node *) malloc(sizeof(struct node));
		temp->lchild = copy(original->rchild);
		temp->rchild = copy(original->lchild);
		temp->data = original->data;
		return temp;
	}
	return NULL;
}

struct node *make_tree()
{
	struct node *ptr[7];

	for (int i = 0; i < 7; i++) {
		ptr[i] = (struct node *)malloc(sizeof(struct node));
		ptr[i]->data = i + 1;
		ptr[i]->lchild = ptr[i]->rchild = NULL;
	}

	ptr[0]->lchild = ptr[1];
	ptr[0]->rchild = ptr[2];
	ptr[1]->lchild = ptr[3];
	ptr[1]->rchild = ptr[4];
	ptr[2]->lchild = ptr[5];
	ptr[5]->lchild = ptr[6];

	return ptr[0];
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