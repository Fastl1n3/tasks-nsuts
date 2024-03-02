#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#define N 1000000
int A[N];
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, x;
	scanf("%d%d", &n, &x);
	for (int i = 0; i < n; i++) {
		scanf("%f", &A[i]);
	}
	int a = -2, center, center_i, first_i, last_i;
	first_i = 0;
	last_i = n - 1;
	while (a == -2) {
		n = last_i - first_i + 1;
		if ((first_i + last_i) % 2 == 0)
			center_i = (first_i + last_i) / 2;
		else
			center_i = (first_i + last_i) / 2 + 1;
		center = A[center_i];
		if (center == x) {
			a = center_i;
			break;
		}
		if (first_i == last_i)
			a = -1;
		if (x > center)
			if (n % 2 != 0)
				first_i = center_i + 1;
			else
				first_i = center_i;
		else
			last_i = center_i - 1;
	}
	printf("%d", a);
	return 0;
}