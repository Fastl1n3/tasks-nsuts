#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#define N 100
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	int A[N];
	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < n; i++) {
		int k = 0;
		for (int j = i + 1; j < n; j++) {
			if (A[i] > A[j])
				k += 1;
		}
		printf("%d ", k);
	}
	return 0;
}