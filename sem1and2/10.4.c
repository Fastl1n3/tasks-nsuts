#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 1000001
int A[N] = { 0 };
int B[N] = { 0 };
int res[2000002] = { 0 };
int merge(const int* a, int ak, const int* b, int bk, int* res) {
	int i = 0, j = 0, g = 0;
	while (i < ak && j < bk) {
		if (a[i] < b[j]) {
			res[g] = a[i];
			i++;
		}
		else {
			res[g] = b[j];
			j++;
		}
		g++;
	}
	while (i < ak) {
		res[g] = a[i];
		i++;
		g++;
	}
	while (j < bk) {
		res[g] = b[j];
		j++;
		g++;
	}
	return g;
}
int main() {
	FILE* f1 = fopen("input.bin", "rb");
	FILE* f2 = fopen("output.bin", "wb");
	int n, m;
	fread(&n, sizeof(n), 1, f1);
	fread(&m, sizeof(m), 1, f1);
	//printf("%d %d\n", n, m);
	for (int i = 0; i < n; i++) {
		fread(&A[i], sizeof(int), 1, f1);
		//printf("%d ", A[i]);
	}
	//printf("\n");
	for (int i = 0; i < m; i++) {
		fread(&B[i], sizeof(int), 1, f1);
		//printf("%d ", B[i]);
	}
	int l = merge(A, n, B, m, res);
	for (int i = 0; i < l; i++)
		fwrite(&res[i], sizeof(int), 1, f2);
	fclose(f1);
	fclose(f2);
	return 0;
}