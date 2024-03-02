#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#define N 1000001
unsigned int A[N];
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m, new_v, idx, n1;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &new_v, &idx);
		n1 = idx / 32;
		int sdvig = 31 - idx % 32;
		if (new_v == 1) {
			if ((A[n1] & (1 << sdvig)) == 0)
				A[n1] += (new_v << sdvig);
		}
		else if ((A[n1] & (1 << sdvig)) != 0)
			A[n1] -= (1 << sdvig);
	}
	for (int i = 0; i < n; i++)
		printf("%d ", A[i]);
	return 0;
}
