#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#define N 101
int A[N][N] = { 0 };
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &A[i][j]);
		}
	}
	int k_b;
	for (int i = 0; i < n; i++) {
		k_b = 0;
		for (int j = 0; j < m; j++) {
			if (A[i][j] == 1)
				k_b++;
			else {
				if (k_b != 0)
					printf("%d ", k_b);
				k_b = 0;
			}
			if (j == m - 1 && k_b != 0)
				printf("%d", k_b);
		} 
		printf("\n");
	}
	for (int i = 0; i < m; i++) {
		k_b = 0;
		for (int j = 0; j < n; j++) {
			if (A[j][i] == 1)
				k_b++;
			else {
				if (k_b != 0)
					printf("%d ", k_b);
				k_b = 0;
			}
			if (j == n - 1 && k_b != 0)
				printf("%d", k_b);
		}
		printf("\n");
	}
	return 0;
}