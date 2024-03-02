#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 5001
int A[N][N] = { 0 };
int S[N] = { 0 };
int main() {
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	int m, n;
	fscanf(f1, "%d%d", &n, &m);
	for (int g = 0; g < m; g++) {
		int i, j;
		fscanf(f1, "%d %d", &i, &j);
		if (A[i][j] == 0) {
			A[i][j] = 1;
			A[0][j]++;
		}
	}
	//for (int i = 0; i <= n; i++) {
	//	for (int j = 1; j <= n; j++) {
	//		fprintf(f2, "%d ", A[i][j]);
	//	}
	//	fprintf(f2, "\n");
	//}
	//fprintf(f2, "\n");
	int f, len = 0, flag;
	while (len != n) {
		flag = n;
		for (int j = 1; j <= n; j++) {
			flag--;
			if (A[j][0] == 1)
				continue;
			if (A[0][j] == 0) {
				flag++;
				for (int g = 1; g <= n; g++) {
					if (A[j][g] == 1)
						A[0][g]--;
					A[j][g] = 0;
				}
				A[j][0] = 1;
				S[len] = j;
				len++;
				break;
			}
		}
		if (flag == 0) {
			fprintf(f2, "bad course");
			break;
		}
	}
	if (flag != 0) {
		for (int i = 0; i < n; i++)
			fprintf(f2, "%d ", S[i]);
	}
	fclose(f1);
	fclose(f2);
	return 0;
}