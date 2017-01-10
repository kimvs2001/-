#include <stdio.h>
#include <stdlib.h>


void main() {
	

	int** array;
	int n, m, numCells,x,y,timeStep;
	int count = 1;
	printf("m,n,number of initial cells ");
	scanf("%d %d %d", &m, &n,&numCells);
	//
	m = m + 2;
	n = n + 2;
	array = (int**)malloc(sizeof(int*)*m);
	for (int i = 0; i < m; i++)
		array[i] = (int*)malloc(sizeof(array)*n);
	//array[m][n] 선언
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 || j == 0 || i == (m - 1) || j == (n - 1))
				array[i][j] = -1;	//테두리
			else array[i][j] = 0;	//배열 초기화
		}
	}

	for (int i = 0; i < numCells; i++) {
		printf("Enter the coorinates x,y (%d)", i+1);
		scanf("%d %d",&x,&y);
		array[x+1][y+1] = 1;	//선택된 셀 활성화
	}

	printf("\nnumber of time step : ");
	scanf("%d", &timeStep);

	for (int k = 0; k < timeStep; k++) {
		
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				
				//if (array[i][j] == count) {
					if (array[i + 1][j] == count) array[i + 1][j] = count + 1;
					if (array[i - 1][j] != -1 )array[i - 1][j] = count + 1;
					if(array[i + 1][j + 1] !=-1 ) array[i + 1][j + 1]= count + 1;
					if(array[i + 1][j - 1] != -1)array[i + 1][j - 1]= count + 1;

				}
				
			}
		}
		count++;

	}



	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			printf("%d ", array[i][j]);	//testing
		}printf("\n");
	}
	

}
