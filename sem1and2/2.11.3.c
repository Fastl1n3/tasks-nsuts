#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 2001
int T[N][N] = { 0 };
void Floyd(int n) {
	for (int k = 1; k <= n; k++) {
		int f = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (T[i][k] == 1 && T[k][j] == 1) {
					T[i][j] = 1;
					f = 1;
				}
			}
		}
		if (f == 0)
			break;
	}
}
int main() {
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	int n;
	fscanf(f1, "%d", &n);
	char c;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			fscanf(f1, "%c", &c);
			if (c == '\n')
				fscanf(f1, "%c", &c);
			T[i][j] = c - '0';
			if (i == j)
				T[i][j] = 1;
		}
	}
	Floyd(n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			fprintf(f2, "%d", T[i][j]);
		}
		fprintf(f2, "\n");
	}
	fclose(f1);
	fclose(f2);
	return 0;
}