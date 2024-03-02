#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#define N 100001
void select_sort(int A[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int index, c;
		index = i;
		for (int j = i + 1; j < n; j++) {
			if (A[j] < A[index])
				index = j;
		}
		if (i != index) {
			c = A[i];
			A[i] = A[index];
			A[index] = c;
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, A[N];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	select_sort(A, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", A[i]);
	}
	return 0;
}
