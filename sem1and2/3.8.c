#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#define N 100001
int A[N];
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d %d\n", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	while (k >= n) {
		k -= n;
	}
	int b;
	for (int i = 0; i < n / 2; i++) {
		b = A[i];
		A[i] = A[n - i - 1];
		A[n - i - 1] = b;
	}
	for (int i = 0; i < k / 2; i++) {
		b = A[i];
		A[i] = A[k - i - 1];
		A[k - i - 1] = b;
	}
	int j = 0;
	for (int i = k; i < (n + k) / 2; i++) {
		b = A[i];
		A[i] = A[n - j - 1];
		A[n - j - 1] = b;
		j++;
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", A[i]);
	}
	return 0;
}