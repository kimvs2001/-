#include <stdio.h>
#include <stdlib.h>
void SWAP(struct node*, struct node*);
void addHeap(struct node* , int  );
void extractMin();
struct node* output();
void initiallize(int, int);
FILE* fileOpen();
struct node {
	int v1,v2;
	int cost;
}**cost;
int **adMat,**heap;
bool *visited;
int usedSize = 0;
int usedPos = 0;
void main() {
	struct node*temp;
	temp = (struct node*)malloc(sizeof(struct node));
	int here = 0;
	FILE *fp=fileOpen();
	int n,edge,x,y,data;
	fscanf(fp, "%d%d", &n,&edge);
	initiallize(n,edge);
	for(int i=0;i<edge;i++){
		fscanf(fp, "%d%d%d", &x, &y, &data);
		if (x == -1)break;
		adMat[x][y] = data;
		adMat[y][x] = data;
		cost[i]->v1 = x;
		cost[i]->v2 = y;
		cost[i]->cost = data;
	//	addHeap(cost[i],edge);
	}
	
//	printf("%d ", output()->cost);
//	extractMin();
	for (int k = 0; k < n - 1;k++) {
		for (int i = 0; i < n; i++) {
			if( adMat[here][i]> 0 && visited[i]==false)
			{
				addHeap(cost[i], edge+5);
			}
		}
		temp = cost[0];
		printf("%d -> %d : %d \n", temp->v1, temp->v2, adMat[temp->v1][temp->v2]);
		extractMin();
		here = temp->v1;
		
	}

}
void SWAP(struct node*a, struct node*b) {
	struct node* temp = a;
	a = b; b = temp;
}
void addHeap(struct node*add,int capcity) {
	struct node*temp;
	temp = (struct node*)malloc(sizeof(struct node));
	int usedPos = usedSize;	//처음엔 usedSize= 0
	int parentPos = (int)((usedPos - 1) / 2);
	if (usedSize == capcity) { printf("힙이가득참"); return; }
	cost[usedSize] = add;
	
	while (usedPos > 0 && cost[usedPos]->cost < cost[parentPos]->cost) {
		temp = cost[usedPos]; cost[usedPos] = cost[parentPos]; cost[parentPos] = temp;
		usedPos = parentPos;
		parentPos = (int)((usedPos - 1) / 2);
	}
	usedSize++;
}

void extractMin() {
	struct node*temp;
	temp = (struct node*)malloc(sizeof(struct node));
	if (usedSize == 0)return;
	int parentPos = 0, leftPos = 1, rightPos = 2;
	cost[0] = NULL;
	usedSize--;
	temp = cost[0]; cost[0] = cost[usedSize]; cost[usedSize] = temp;
	while (1) {
		int selectChild = 0;
		if (leftPos >= usedSize)break;
		if (rightPos >= usedSize)selectChild = leftPos;
		else {
			if (cost[leftPos]->cost > cost[rightPos]->cost)selectChild = rightPos;
			else selectChild = leftPos;
		}
		if (cost[selectChild]->cost < cost[parentPos]->cost) {
			temp = cost[parentPos]; cost[parentPos] = cost[selectChild]; cost[selectChild] = temp;
			parentPos = selectChild;
		}
		else break;
		leftPos = 2 * parentPos + 1;
		rightPos = leftPos + 1;
		
	}
}
struct node* output() {
	//for (int i = 0; i < usedSize; i++) {
	//	printf(" %d ",cost[i]->cost);	
	//}
	return cost[0];
}
void initiallize(int n,int edge) {
	heap = (int**)malloc(sizeof(int)*edge);
	cost = (struct node**)malloc(sizeof(struct node)*edge);
	for (int i = 0; i < edge; i++) cost[i] = (struct node*)malloc(sizeof(struct node));
	visited = (bool*)malloc(sizeof(bool)*n);
	adMat = (int**)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) {
		adMat[i] = (int*)malloc(sizeof(int)*n);
		visited[i] = false;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j<n; j++)
			adMat[i][j] = 0;
		visited[i] = 0;
	}
}
FILE* fileOpen() {
	FILE *fp;
	char filename[80] = "data.txt";
	//printf("파일이름을 입력하시오:");
	//gets_s(filename);
	if ((fp = fopen(filename, "rt")) == NULL) {
		printf("파일 오픈 에러");
		return NULL;
	}
	return fp;
}
