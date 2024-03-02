#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 51
int A[N][N] = { 0 };
int color[N] = { 0 };
int dad[N] = { 0 };
void DFS(int A[][N], int n) {
	int j = 1;
	while (A[0][j] == 0)
		j++;
	search(A, j, n);
}
int search(int A[][N], int u, int n) {
	color[u] = 1;
	int j = 1;
	for (int j = 1; j <= n; j++) {
		if (A[u][j] == 0)
			continue;
		if (color[j] == 0) {
			dad[j] = u;
			search(A, j, n);
		}
	}
	color[u] = 2;
}
int main() {
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	int n, m;
	fscanf(f1, "%d%d", &n, &m);
	for (int g = 0; g < m; g++) {
		int i, j;
		fscanf(f1, "%d %d", &i, &j);
		A[i][j] = 1;
		A[j][i] = 1;
	}
	int s;
	fscanf(f1, "%d", &s);
	for (int g = 0; g < s; g++) {
		int j;
		fscanf(f1, "%d", &j);
		A[0][j] = 1;
	}
	//for (int i = 0; i <= n; i++) {
	//	for (int j = 1; j <= n; j++) {
	//		fprintf(f2, "%d ", A[i][j]);
	//	}
	//	fprintf(f2, "\n");
	//}
	//fprintf(f2, "\n\n");
	DFS(A, n);
	int flag = 0;
	for (int j = 1; j <= n; j++) {
		if (A[0][j] == 1) {
			if (color[j] != 2) {
				flag = 1;
				break;
			}
		}
	}
	if (flag == 0)
		fprintf(f2, "YES");
	else
		fprintf(f2, "NO");
	fclose(f1);
	fclose(f2);
	return 0;
}