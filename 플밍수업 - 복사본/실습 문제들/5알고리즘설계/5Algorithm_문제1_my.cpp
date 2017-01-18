#include<stdio.h>
#include<stdlib.h>
int howManyArr = 0;
bool* inverter(int num, bool* res) {
	int i;
	for (i = 0; num > 0; i++) {
		res[i] = num % 2;
		num = num / 2;
	}

	howManyArr = i;
	return res;
}
int pow(int a, int b)
{
	if (b == 0)
		return 1;
	else
		return a * pow(a, b - 1);
}

void main() {
	int n, *arr;
	int **A;
	bool*ptr;
	bool*res;
	scanf("%d", &n);
	n++;
	res = (bool*)malloc(sizeof(bool)*n);

	arr = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) {
		arr[i] = i;
	}

	A = (int**)malloc(sizeof(int*)*(pow(2, n)));
	for (int i = 0; i < ((pow(2, n))); i++) {
		A[i] = (int*)malloc(sizeof(int)*(pow(2, n)));
	}
	for (int i = 0; i <((pow(2, n))); i++) {
		for (int j = 0; j <(pow(2, n)); j++) {
			A[i][j] = -1;
		}	
	}
	//초기화 끝
	
	for (int i = 0; i < ((pow(2, n))); i++) {
		howManyArr = 0;
		
		ptr = inverter(i, res);
		for (int j = 0; j < howManyArr; j++) {
			if (ptr[j] == 1) {
				A[i][j] = arr[j];
				//printf("%d ", arr[j]);
			}
				
		}
		//printf("\n");
	}
	//printf("\n\n\n\n\n");
	
	for (int i = 0; i < ((pow(2, n))); i++) {
		for (int j = 0; j < ((pow(2, n))); j++) {
			if (A[i][j] != -1)
				printf("%d ",A[i][j]);
		}printf("\n");
	}
}