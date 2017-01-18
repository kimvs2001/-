#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *lchild;
	struct node *rchild;
};

struct node *make_tree();
int count_zero(struct node *);
int count_one(struct node *);
int count_two(struct node *);
struct node *max_node(struct node *);
struct node *max_two(struct node *, struct node *);

void inorder(struct node *);
void preorder(struct node *);
void postorder(struct node *);

void main()
{
	struct node *root = make_tree();

	printf("차수가 0인 노드의 수 = %d\n", count_zero(root));
	printf("차수가 1인 노드의 수 = %d\n", count_one(root));
	printf("차수가 2인 노드의 수 = %d\n", count_two(root));

	struct node *max = max_node(root);
	if (max != NULL)
		printf("트리에서 최대값 = %d\n", max->data);
	else
		printf("트리에 노드가 없습니다.\n");
}

int count_zero(struct node *ptr)
{
	if (ptr == NULL)
		return 0;

	if (ptr->lchild == NULL && ptr->rchild == NULL)
		return 1;

	return count_zero(ptr->lchild) + count_zero(ptr->rchild);
}

int count_one(struct node *ptr)
{
	if (ptr == NULL)
		return 0;

	int num_lchild = count_one(ptr->lchild);
	int num_rchild = count_one(ptr->rchild);

	if (ptr->lchild != NULL && ptr->rchild == NULL ||
		ptr->lchild == NULL && ptr->rchild != NULL)
		return num_lchild + num_rchild + 1;

	else
		return num_lchild + num_rchild;
}

int count_two(struct node *ptr)
{
	if (ptr == NULL)
		return 0;

	int num_lchild = count_two(ptr->lchild);
	int num_rchild = count_two(ptr->rchild);

	if (ptr->lchild != NULL && ptr->rchild != NULL)
		return num_lchild + num_rchild + 1;

	else
		return num_lchild + num_rchild;
}

struct node *max_node(struct node *ptr)
{
	if (ptr == NULL)
		return NULL;

	if (ptr->lchild == NULL && ptr->rchild == NULL)
		return ptr;

	struct node *lmax = max_node(ptr->lchild);
	struct node *rmax = max_node(ptr->rchild);

	if (lmax == NULL)
		return max_two(ptr, rmax);
	else if (rmax == NULL)
		return max_two(ptr, lmax);
	else
		return max_two(ptr, max_two(lmax, rmax));
}

struct node *max_two(struct node *a, struct node *b)
{
	return (a->data > b->data) ? a : b;
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