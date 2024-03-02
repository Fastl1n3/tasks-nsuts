#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#define N 2001
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, a;
	scanf("%d", &n);
	int A[N] = { 0 };
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		if (a >= 0)
			A[a] += 1;
		else
			A[1000 - a] += 1;
	}
	int k = 0;
	for (int i = 0; i < N; i++) {
		if (A[i] != 0)
			k += 1;
	}
	printf("%d", k);
	return 0;
}