#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#define N 100001
void ins_sort(int A[], int n) {
	for (int i = 1; i < n; i++) {
		int x = A[i];
		int j = i - 1;
		while (j >= 0 && A[j] > x) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = x;
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
	ins_sort(A, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", A[i]);
	}
	return 0;
}