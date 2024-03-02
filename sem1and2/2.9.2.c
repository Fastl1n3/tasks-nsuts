#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 101
int A[N][N] = { 0 };
int color[N] = { 0 };
int dad[N] = { 0 };
int C[N] = { 0 };
int DFS(int A[][N], int n) {
	int nk = 0, max = 0;
	for (int j = 1; j <= n; j++) {
		if (color[j] == 0) {
			nk++;
			search(A, j, nk, n);
			if (nk > max)
				max = nk;
		}	
	}
	return max;
}
int search(int A[][N], int u, int nk, int n) {
	color[u] = 1;
	C[u] = nk;
	for (int j = 1; j <= n; j++) {
		if (A[u][j] == 0)
			continue;
		if (color[j] == 0) {
			search(A, j, nk, n);
		}
	}
	color[u] = 2;
}
int main() {
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	int n;
	fscanf(f1, "%d", &n);
	int i, j;
	while (fscanf(f1, "%d%d", &i, &j) == 2) {
		A[i][j] = 1;
		A[j][i] = 1;
	}
	//for (int i = 1; i <= n; i++) {
	//	for (int j = 1; j <= n; j++) {
	//		fprintf(f2, "%d ", A[i][j]);
	//	}
	//	fprintf(f2, "\n");
	//}
	//fprintf(f2, "\n");
	fprintf(f2, "%d\n", DFS(A, n) + 1);
	//for (int i = 1; i <= n; i++) {
	//	fprintf(f2, "%d ", C[i]);
	//}
	fclose(f1);
	fclose(f2);
	return 0;
}