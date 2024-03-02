#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <math.h>
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int k;
	float D, n;
	scanf("%d\n", &k);
	// n^2 + n - 2*(k-1) = 0, если n - целые, то на k стоит 1 
	D = 1 + 4 * 2 * (k - 1);
	n = (-1 + sqrt(D)) / 2;
	if (n == (int)n) printf("%d\n", 1);
	else printf("%d\n", 0);
	return 0;
}