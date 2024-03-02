#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#define N 1001
double A[N][N] = {0};
void Koef(int n) {
	double c;
	for (int i = 0; i < n; i++) {
		if (i == 0)
			c = 1;
		else
			c = c * (n - i + 1) / i;
		A[n][i] = c;
	}
	A[n][n] = 1;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int q, n = -1, k, nn;
	double c;
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		nn = n;
		scanf("%d%d", &n, &k);
		if (nn != n)
			Koef(n);
		printf("%0.10g\n", A[n][k]);
	}
	return 0;
}
	