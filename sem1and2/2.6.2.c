#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define N 100001
#define K 101
int A[N][K] = { 0 };
int main() {
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	int n, k, a, ost;
	fscanf(f1, "%d%d", &n, &k);
	fscanf(f1, "%d", &a);
	if (a >= 0)
		ost = a % k;
	else
		ost = (k + (a % k)) % k;
	A[0][ost] = 1;
	for (int i = 1; i < n; i++) {
		fscanf(f1, "%d", &a);
		if (a >= 0)
			ost = a % k;
		else
			ost = (k + (a % k)) % k;
		for (int j = 0; j < k; j++) {
			if (A[i - 1][j] == 1) {
				A[i][(j + ost) % k] = 1;
				if (j - ost < 0)
					A[i][k + (j - ost) % k] = 1;
				else
					A[i][(j - ost) % k] = 1;
			}		
		}	
	}
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			fprintf(f2, "%d ", A[i][j]);
		}
		fprintf(f2, "\n");
	}*/
	if (A[n - 1][0] == 1)
		fprintf(f2, "Divisible");
	else
		fprintf(f2, "Not divisible");
	fclose(f1);
	fclose(f2);
	return 0;
}