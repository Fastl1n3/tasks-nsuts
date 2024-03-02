#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define N 5002
//typedef struct list {
//	int value;
//	int rebro;
//	struct list* next;
//} Ver;
//Ver* A[N] = { 0 };
//
//Ver* append(Ver* x, int val, int r) {
//	Ver* tmp = (Ver*)malloc(sizeof(Ver));
//	tmp->value = val;
//	tmp->rebro = r;
//	tmp->next = NULL;
//	if (x->next == NULL) {
//		x->next = tmp;
//	}
//	else {
//		Ver* p = x->next;
//		tmp->next = p;
//		x->next = tmp;
//	}
//	return x;
//}
int A[10 * N][3] = { 0 };
int D[10 * N] = { 0 };
int dad[10 * N] = { 0 };
int reverse[50002] = { 0 };
int Belman(int v0, int v1, int n, int m, FILE* f) {
	for (int i = 1; i <= n; i++) {
		D[i] = INT_MAX / 3;
	}
	int t1 = time(NULL);
	
	D[v0] = 0;
	int flag;
	for (int j = 1; j <= n - 1; j++) {
		flag = 0;
		for (int i = 0; i < m; i++) {
			if (D[A[i][2]] > D[A[i][1]] + A[i][0]) {
				D[A[i][2]] = D[A[i][1]] + A[i][0];
				dad[A[i][2]] = A[i][1];
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
	fprintf(f, "%d ", D[v1]);
	int i = v1, k = 1, g = 0;
	reverse[g] = v1;
	g++;
	while (i != v0) {
		int predok = dad[i];
		k++;
		reverse[g] = predok;
		g++;
		i = predok;
	}
	fprintf(f, "%d ", k);
	for (int i = g - 1; i >= 0; i--) {
		fprintf(f, "%d ", reverse[i]);
	}
	fprintf(f, "\n");
	return D[v1];
}
int main() {
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	int n, m, k;
	fscanf(f1, "%d%d%d", &n, &m, &k);
	int i, j, r;
	int friends[51] = { 0 };
	for (int i = 0; i < k; i++) {
		fscanf(f1, "%d", &friends[i]);
	}
	for (int g = 0; g < m; g++) {
		fscanf(f1, "%d%d%d", &i, &j, &r);
		if (i == j)
			continue;
		A[g][0] = r;
		A[g][1] = i;
		A[g][2] = j;
	}
	for (int i = 0; i < k; i++) {
		int ans = Belman(1, friends[i], n, m, f2);
	}
	fclose(f1);
	fclose(f2);
	return 0;
}