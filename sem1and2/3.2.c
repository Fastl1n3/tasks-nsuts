#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#define N 100000
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, d;
	scanf("%d", &n);
	int A[N];
	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < n; i++) {
		int s = 0;
		d = i + 1;
		for (int j = i; j < n; j += d) {
			s += A[j];
		}
		printf("%d\n", s);
	}
	return 0;
}