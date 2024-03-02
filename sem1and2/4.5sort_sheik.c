#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#define N 100001
void shake_sort(int A[], int n) {
	int left = 0, right = n - 1, f = 1, i, c;
	while (f == 1) {
		f = 0;
		i = left;
		while (i < right) {
			if (A[i] > A[i + 1]) {
				c = A[i];
				A[i] = A[i + 1];
				A[i + 1] = c;
				f = 1;
			}
			i++;
		}
		right--;
		if (f == 1) {
			f == 0;
			i = right;
			while (i > left) {
				if (A[i] < A[i - 1]) {
					c = A[i];
					A[i] = A[i - 1];
					A[i - 1] = c;
					f = 1;
				}
				i--;
			}
		}
		left++;
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
	shake_sort(A, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", A[i]);
	}
	return 0;
}