#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 1002
int L[N][N] = { 0 };
int DFS(int L[][N], int n) {
	int nk = 0, max = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (L[i][j] == 0)
				continue;
			if (L[i][j] == 1) {
				nk++;
				search(L, i, j, nk);
				if (nk > max)
					max = nk;
			}
		}
	}
	return max;
}
int search(int L[][N], int i, int j, int nk) {
	L[i][j] = 2;
	if (L[i][j + 1] == 1)
		search(L, i, j + 1, nk);
	if (L[i + 1][j] == 1)
		search(L, i + 1, j, nk);
	if (L[i][j - 1] == 1)
		search(L, i, j - 1, nk);
	if (L[i - 1][j] == 1)
		search(L, i - 1, j, nk);
	L[i][j] = 3;
}
int main() {
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	int n;
	char c;
	fscanf(f1, "%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			fscanf(f1, "%c", &c);
			if (c == '\n')
				fscanf(f1, "%c", &c);
			if (c != '*')
				L[i][j] = 1;
		}
	}
	//for (int i = 1; i <= n; i++) {
	//	for (int j = 1; j <= n; j++) {
	//		fprintf(f2, "%d ", L[i][j]);
	//	}
	//	fprintf(f2, "\n");
	//}
	//fprintf(f2, "\n");
	fprintf(f2, "%d\n", DFS(L, n) - 1);
	//for (int i = 1; i <= n; i++) {
	//	for (int j = 1; j <= n; j++) {
	//		fprintf(f2, "%d ", L[i][j]);
	//	}
	//	fprintf(f2, "\n");
	//}
	//fprintf(f2, "\n");
	fclose(f1);
	fclose(f2);
	return 0;
}