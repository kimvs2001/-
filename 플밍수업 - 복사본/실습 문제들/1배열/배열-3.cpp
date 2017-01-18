#include <stdio.h>
#include <stdlib.h>
struct pairs {
	int num;
	int counter;
};

#define SWAP(x, y, t)	((t) = (x), (x) = (y), (y) = (t))

void sort_dsc(struct pairs[], int);
void sort_asc(int[], int);

void main(void) {
	int A[100][200];
	struct pairs B[100] = { { 0,0 } };
	int i, j;

	for (i = 0; i < 100; i++) {
		for (j = 0; j < 200; j++) {
			A[i][j] = rand() % 100 + 1;
			B[A[i][j] - 1].num = A[i][j];
			B[A[i][j] - 1].counter++;
		}
	}
	/*
	sort_dsc(B, 101);
	for (i = 0; i < 10; i++) {
	printf("%d번째: 숫자 = %d, 빈도수 = %d\n", i + 1, B[i].num, B[i].counter);
	}
	*/
	sort_asc(&A[0][0], 100 * 200);
	for (i = 0; i < 2; i++)
		for (j = 0; j < 200; j++)
			printf("A[%d][%d] = %d\n", i, j, A[i][j]);

}

void sort_dsc(struct pairs list[], int n)
{
	int i, j, max;
	struct pairs temp;
	for (i = 0; i< n - 1; i++) {
		max = i;
		for (j = i + 1; j < n; j++)
			if (list[j].counter > list[max].counter)
				max = j;
		SWAP(list[i], list[max], temp);
	}
}

void sort_asc(int list[], int n)
{
	int i, j, min, temp;
	for (i = 0; i<n - 1; i++) {
		min = i;
		for (j = i + 1; j<n; j++)
			if (list[j]<list[min])
				min = j;
		SWAP(list[i], list[min], temp);
	}
}