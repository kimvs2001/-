#include <stdio.h>
#include <stdlib.h>

void main(void) {
	int A[100][200];
	int B[101] = { 0 };
	int i, j;

	for (i = 0; i < 100; i++) {
		for (j = 0; j < 200; j++) {
			A[i][j] = rand() % 100 + 1;
			B[A[i][j]]++;
		}
	}
	for (i = 1; i < 101; i++) {
		printf("B[%d] = %d\n", i, B[i]);
	}
}