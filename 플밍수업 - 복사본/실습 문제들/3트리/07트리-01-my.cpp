#include <stdio.h>
#include <stdlib.h>
void inorder(struct node*);
void insert_node(struct node**, int);
int tree_depth(struct node *);
struct node {
	int data;
	struct node* lchild;
	struct node* rchild;
};

void main() {
	struct node* root= NULL;
	
	for (int i = 0; i < 20; i++) {
		insert_node(&root,(rand() % 1000 + 1));
	}

	inorder(root);
	printf("\n%d",tree_depth(root));
}
int tree_depth(struct node *root) {
	int l = 0, r = 0;
	if (root) {
		l=tree_depth(root->lchild);
		r=tree_depth(root->rchild);
		if (l > r) return l+1;
		else return r+1;
	}
	else return 0;
}

struct node* modified_search(struct node* root, int key) {
	struct node* parent, *child = NULL;
	if (root == NULL || root->data == key) return NULL;
	parent = root;
	
	child = (root->data < key) ? root->rchild : root->lchild;
	
	while (child != NULL) {
		if (key == child->data) return NULL;
		parent = child;
		if (key > child->data)child = child->rchild;
		else child = child->lchild;
	}
	return parent;
}

void insert_node(struct node **root, int num) {// node: root, num: 추가할키값. 
	struct node *ptr,*parent = modified_search(*root, num);
	if (parent || !(*root)) {// num이tree에존재하지않음. 
		ptr = (struct node *)malloc(sizeof(struct node));
		ptr->data = num;// num을키값으로하는노드생성 
		ptr->lchild = NULL;
		ptr->rchild = NULL;
		if (*root) {  // parent의child node로삽입 
			if (num < parent->data) { parent->lchild = ptr; }
			else
				parent->rchild = ptr;
		}
		else *root = ptr;// 트리가empty일경우, root로등록
	}

}
void inorder(struct node *ptr)
{
	if (ptr) {
		inorder(ptr->lchild);
		printf("%d ", ptr->data);
		inorder(ptr->rchild);
	}
}

/*
void insert_node(struct node**root, int data) {
	struct node* parent;
	if (*root == NULL) {
		struct node* temp = (struct node*)malloc(sizeof(struct node));
		temp->lchild = temp->rchild = NULL;
		temp->data = data;
		*root = temp;

	}
	else {
		parent = modified_search(*root, data);
		if (parent != NULL) {
			struct node* temp = (struct node*)malloc(sizeof(struct node));
			temp->lchild = temp->rchild = NULL;
			temp->data = data;
			((parent->data < data) ? parent->rchild : parent->lchild) = temp;
			
		}
	}
	
}*/