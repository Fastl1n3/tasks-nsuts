#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#define N 100000
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, a;
	scanf("%d", &n);
	int A[N] = { 0 };
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		A[a] += 1;
	}
	for (int i = 0; i < N; i++) {
		if (A[i] != 0)
			printf("%d: %d\n", i, A[i]);
	}
	return 0;
}