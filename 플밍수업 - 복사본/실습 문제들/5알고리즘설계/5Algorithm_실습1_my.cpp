#include <stdio.h>
int count = 0;
int bin(int n, int k) {
	count++;
	printf("%d��° ���\n", count);
	if (k==0 ||k==n	) {
		return 1;
	}
	
		
		return bin(n-1, k-1)+bin(n-1,k);
	

}
void main() {
	int n, k;
	while (1) {
		printf("n,k �� �Է��Ͻÿ� : ");
		scanf("%d%d", &n, &k);
		if (n == -1) return;
		printf("  bin(n,k)�� �� : %d\n", bin(n, k));
		//printf("ȣ��Ƚ��: %d\n", count);
	}
}