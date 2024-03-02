#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#define N 1000000
int A[N];
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		A[i] = i;
	}
	int k = 2, g = 2;
	while (k * k <= n) {
		for (int j = k * k; j <= n; j += k) {
			if (A[j] % k == 0)
				A[j] = 0;
		}
		while (n != 0) {
			if (A[g + 1] != 0) {
				k = A[g + 1];
				g++;
				break;
			}
			else
				g++;
		}
	}
	for (int i = 2; i <= n; i++) {
		if (A[i] != 0)
			printf("%d ", A[i]);
	}
	return 0;
}
