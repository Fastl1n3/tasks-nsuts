#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#define N 5000
int A[N];
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	int s, smax = -100000;
	int l = 0, r = 0;
	for (int i = 0; i < n; i++) {
		s = 0;
		for (int j = i; j < n; j++) {
			s += A[j];
			if (s > smax) {
				l = i;
				smax = s;
				r = j;
			}
		}
	}
	printf("%d %d %d", l, r, smax);
	return 0;
}