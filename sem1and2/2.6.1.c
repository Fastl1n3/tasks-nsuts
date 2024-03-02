#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define N 41
int main() {
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	int A[N] = { 0 };
	A[0] = 0;
	A[1] = 2;
	A[2] = 3;
	int n;
	fscanf(f1, "%d", &n);
	for (int i = 3; i <= n; i++)
		A[i] = A[i - 1] + A[i - 2];
	fprintf(f2, "%d ", A[n]);
	fclose(f1);
	fclose(f2);
	return 0;
}