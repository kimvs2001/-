#include <stdio.h>
int count = 0;
int bin(int n, int k) {
	count++;
	printf("%d번째 계산\n", count);
	if (k==0 ||k==n	) {
		return 1;
	}
	
		
		return bin(n-1, k-1)+bin(n-1,k);
	

}
void main() {
	int n, k;
	while (1) {
		printf("n,k 를 입력하시오 : ");
		scanf("%d%d", &n, &k);
		if (n == -1) return;
		printf("  bin(n,k)의 값 : %d\n", bin(n, k));
		//printf("호출횟수: %d\n", count);
	}
}