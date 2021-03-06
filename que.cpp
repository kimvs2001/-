#include <stdio.h>
#include <stdlib.h>
#define MAX 10
//큐가 꽉차면 계속 겹친다
	typedef struct{
		int x, y;
	}QUEUE[MAX],cell;
	
	QUEUE queue;
	
	int front = -1, rear = -1;
	cell que_empty() {
		cell temp;
		printf("큐가 비었습니다.");
		temp.x = NULL; temp.y = NULL;
		return temp;
	}
	cell que_full() {
		cell temp;
		printf("큐가 꽉 찼습니다.");
		temp.x = NULL; temp.y = NULL;
		return temp;
	}
	void addq(int x, int y) {
		rear = (rear + 1) % MAX;
		if (rear== front) {
			que_full(); return;
		}
		
		queue[rear].x = x;
		queue[rear].y = y;
	}

	cell deleteq() {
		cell temp;
		if (front == rear)
			return que_empty();
		front = (front + 1) % MAX;
		temp.x = queue[front].x;
		temp.y = queue[front].y;
		return temp;
	}
	
	
	void main() {
		cell tmp;
		int mod,check =1;
		int x, y;
		while (check) {
			printf("1 : addq, 2 : deleteq, 0 : quit \n");
			scanf("%d", &mod);
			check = mod;
			
			switch (mod) {
			
			case 1:
				printf("x,y 입력 :");
				scanf("%d %d", &x, &y);
				addq(x,y);
				break;
			case 2:
				tmp = deleteq();
				printf("x = %d \n",tmp.x);
				printf("y = %d \n",tmp.y);
				break;
			}

			for (int i = 0; i < MAX; i++)
				printf("%d ", queue[i].x); 
			printf("\n");
			for (int i = 0; i < MAX; i++)
				printf("%d ", queue[i].y);
			printf("\n");
		}
		
}