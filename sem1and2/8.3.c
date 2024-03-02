#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#define N 201
double A[N][N] = { 0 };
double X[N] = { 0 };
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= n; j++) {
			scanf("%lf", &A[i][j]);
		}
	}
	double koef;
	double c;
	for (int g = 0; g < n; g++) {
		if (A[g][g] == 0) {
			int i = g;
			while (A[i][g] == 0)
				i++;
			for (int x = 0; x <= n; x++) {
				c = A[g][x];
				A[g][x] = A[i][x];
				A[i][x] = c;
			}
		}
		for (int i = g; i <= n; i++) {
			if (A[g][g] != 0) {
				koef = -(A[i + 1][g] / A[g][g]);
				for (int j = 0; j <= n; j++) {
					A[i + 1][j] += A[g][j] * koef;
				}
			}
		}
	}
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j <= n; j++) {
			printf("%lf ", A[i][j]);
		}
		printf("\n");
	}*/
	int x = 0;
	for (int j = n; j > 0; j--) {
		
		X[x] = A[j - 1][j] / A[j - 1][j - 1];
		
		for (int i = n - 2; i >= 0; i--) {
			A[i][j - 1] = -(A[i][j - 1] * X[x] - A[i][j]);
		}
		x++;
	}
	for (int i = x - 1; i >= 0; i--) {
		printf("%lf\n", X[i]);
	}
	return 0;
}