#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#define N 1001
void permut_to_invtab(int A[], int B[], int n) {
	int index;
	for (int i = 0; i < n; i++) {
		index = A[i] - 1;
		int k = 0;
		for (int j = 0; j < i; j++) {
			if (A[i] < A[j])
				k += 1;
		}
		B[index] = k;
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, A[N], B[N];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	permut_to_invtab(A, B, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", B[i]);
	}
	return 0;
}
