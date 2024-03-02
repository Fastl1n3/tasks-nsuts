#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define N 10002
long long A[N][3] = { 0 };
long long D[N] = { 0 };
int split[N] = { 0 };
int Belman(int v0, int n, int m, FILE* f) {
	for (int i = 1; i <= n; i++) {
		D[i] = LLONG_MAX;
	}
	D[v0] = 0;
	int flag;
	for (int j = 1; j <= n - 1; j++) {
		flag = 0;
		for (int i = 0; i < m; i++) {
			if (D[A[i][1]] != LLONG_MAX && D[A[i][2]] > D[A[i][1]] + A[i][0]) {
				D[A[i][2]] = D[A[i][1]] + A[i][0];
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
	for (int j = 0; j < 10; j++) {
		for (int i = 0; i < m; i++) {
			if (D[A[i][1]] != LLONG_MAX && D[A[i][2]] > D[A[i][1]] + A[i][0]) {
				D[A[i][2]] = -10000000000000010;
				split[A[i][2]] = 1;
			}
		}
	}
	return 1;
}
int main() {
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	int n, m, s0;
	fscanf(f1, "%d%d%d", &n, &m, &s0);
	int i, j;
	long long r;
	for (int g = 0; g < m; g++) {
		fscanf(f1, "%d%d%lld", &i, &j, &r);
		if (i == j)
			continue;
		A[g][0] = r;
		A[g][1] = i;
		A[g][2] = j;
	}
	int ans = Belman(s0, n, m, f2);
	for (int i = 1; i <= n; i++) {
		/*if (i == s0) {
			fprintf(f2, "0\n");
			continue;
		}*/
		if (split[i] == 1)
			fprintf(f2, "-\n");
		else if (D[i] == LLONG_MAX)
			fprintf(f2, "*\n");	
		else
			fprintf(f2, "%lld\n", D[i]);
	}
	/*for (int i = 1; i <= n; i++) {
		fprintf(f2, "%d ", split[i]);
	}*/
	fclose(f1);
	fclose(f2);
	return 0;
}