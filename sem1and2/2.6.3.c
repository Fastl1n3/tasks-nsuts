#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define N 201
#define W 50001
int split[N] = { 0 };
int arr[N][2] = { 0 };
int T[N][W] = { 0 };
void Print_item(int i, int j, int n) {
	if (T[i][j] == 0)
		return;    
	else if (T[i][j] == T[i - 1][j])
		Print_item(i - 1, j, n); 
	else {
		Print_item(i - 1, j - arr[i][0], n);
		split[i] = 1;
		split[0]++;
	}
}
int Max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}
int main() {
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	int n, wmax;
	fscanf(f1, "%d%d", &n, &wmax);
	for (int i = 1; i <= n; i++) 
		fscanf(f1, "%d%d", &arr[i][0], &arr[i][1]);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= wmax; j++) {
			if (arr[i][0] > j)
				T[i][j] = T[i - 1][j];
			else
				T[i][j] = Max(T[i - 1][j], T[i - 1][j - arr[i][0]] + arr[i][1]);
		}
	}
	Print_item(n, wmax, n);
	fprintf(f2, "%d ", split[0]);
	int w = 0;
	for (int i = 1; i <= n; i++) {
		if (split[i] == 1) {
			w += arr[i][0];
		}
	}
	fprintf(f2, "%d ", w);
	fprintf(f2, "%d\n", T[n][wmax]);
	for (int i = 1; i <= n; i++) {
		if (split[i] == 1) {
			fprintf(f2, "%d ", i);
		}
	}
	/*	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= wmax; j++) {
			fprintf(f2, "%d ", T[i][j]);
		}
		fprintf(f2, "\n");
	}*/
	fclose(f1);
	fclose(f2);
	return 0;
}