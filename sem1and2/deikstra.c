#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 2002
int A[N][N] = { 0 };
int D[N] = { 0 };
int dad[N] = { 0 };
int split[N] = { 0 };
int deiksta(int A[][N], FILE* f1, FILE* f2) {
	int n, m;
	int start = 0, end;
	fscanf(f1, "%d%d%d", &end, &n, &m);
	
	//fscanf(f1, "%d%d", &start, &end);
	for (int g = 0; g < m; g++) {
		int i, j, r;
		fscanf(f1, "%d%d%d", &i, &j, &r);
		if (i == j)
			continue;
		A[i][j] = r;
		A[j][i] = r;
	}
	int len = 0;
	for (int i = 0; i < n; i++) {
		D[i] = INT_MAX / 2;
	}
	D[start] = 0;
	int minindex = 0;
	while (len != n) {
		int min = INT_MAX /2;
		int minindex = INT_MAX /2;
		for (int i = 0; i < n; i++) {
			if (D[i] < min && split[i] == 0) {
				min = D[i];
				minindex = i;
			}
		}
		len++;
		if (minindex != INT_MAX / 2) {
			for (int i = 0; i < n; i++) {
				if (A[minindex][i] > 0) {
					int tmp = min + A[minindex][i];
					if (tmp < D[i]) {
						D[i] = tmp;
						dad[i] = minindex;
					}
				}
			}
			split[minindex] = 1;
		}
	}
	fprintf(f2, "%d\n", D[end]);

	int i = end, k = 1, g = 0;
	int reverse[N] = { 0 };
	reverse[g] = end;
	g++;
	while (i != start) {
		int predok = dad[i];
		k++;
		reverse[g] = predok;
		g++;
		i = predok;
	}
	fprintf(f2, "%d\n", k);
	for (int i = g - 1; i >= 0; i--) {
		fprintf(f2, "%d ", reverse[i]);
	}
	fprintf(f2, "\n");
	return 1;
}

int main() {
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	deiksta(A, f1, f2);
	fclose(f1);
	fclose(f2);
	return 0;
}