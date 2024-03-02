#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#define N 100000
int binsearch(int A[], int l, int r, int x) {
	int center, center_i, index = -1;
	while (l <= r) {
		if ((l + r) % 2 == 0)
			center_i = (l + r) / 2;
		else
			center_i = (l + r) / 2 + 1;
		center = A[center_i];
		if (center == x && center_i > index)
			index = center_i;
		if (x >= center)
			l = center_i + 1;
		else
			r = center_i - 1;
	}
	return index;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int A[N];
	int n, q, x, l, r, answer = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		scanf("%d", &x);
		x += answer;
		l = 0;
		r = n - 1;
		answer = binsearch(A, l, r, x);
		printf("%d\n", answer);
	}
	return 0;
}