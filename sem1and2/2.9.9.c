#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 100002
typedef struct list {
	int value;
	int color;
	int dad;
	struct list* next;
} Ver;
Ver* A[N] = { 0 };
int dfnum[N] = { 0 };
int count = 1;
int low[N] = { 0 };
int split[N] = { 0 };
int Srch(Ver** A, Ver* v, int n, int k) {
	A[v->value]->color = 1;
	dfnum[v->value] = count;
	count++;
	low[v->value] = dfnum[v->value];
	Ver* w = v->next;
	while (w != NULL) {
		if (A[w->value]->color == 0) {
			A[w->value]->dad = v->value;
			k = Srch(A, A[w->value], n, k);
			if (low[w->value] >= dfnum[v->value] && split[v->value] == 0) {
				split[v->value] = 1;
				k++;
				printf("%d %d\n", v->value, w->value);
			}
			low[v->value] = (low[v->value] < low[w->value] ? low[v->value] : low[w->value]);
		}
		else {
			if (w->value != A[v->value]->dad && dfnum[w->value] < dfnum[v->value]) {
				low[v->value] = (low[v->value] < dfnum[w->value] ? low[v->value] : dfnum[w->value]);
			}
		}
		w = w->next;
	}
	A[v->value]->color = 2;
	return k;
}
int DFS(Ver** A, int n, int k) {

	for (int j = 1; j <= n; j++) {
		if (A[j]->color == 0)
			k = Srch(A, A[j], n, k);
	}
	return k;
}
Ver* append(Ver* x, int val) {
	Ver* tmp = (Ver*)malloc(sizeof(Ver));
	tmp->value = val;
	tmp->next = NULL;
	if (x->next == NULL) {
		x->next = tmp;
	}
	else {
		Ver* p = x->next;
		tmp->next = p;
		x->next = tmp;
	}
	return x;
}
int main() {
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	int n, m;
	fscanf(f1, "%d%d", &n, &m);
	for (int i = 0; i <= n; i++) {
		Ver* v = (Ver*)malloc(sizeof(Ver));
		v->value = i;
		v->next = NULL;
		v->color = 0;
		v->dad = 0;
		A[i] = v;
	}
	int i, j;
	for (int g = 0; g < m; g++) {
		fscanf(f1, "%d%d", &i, &j);
		A[i] = append(A[i], j);
		A[j] = append(A[j], i);
	}
	int ans = DFS(A, n, 0);
	//for (int i = 1; i <= n; i++) {
	//	Ver* p = A[i];
	//	while (p != NULL) {
	//		fprintf(f2, "%d ", p->value);
	//		p = p->next;
	//	}
	//	fprintf(f2, "\n");
	//}
	//fprintf(f2, "\n");

	for (int i = 1; i <= n; i++) {
		int k = -1;
		if (A[i]->dad == 0) {
			k = 0;
			for (int j = i; j <= n; j++) {
				if (A[j]->dad == i)
					k++;
			}
		}
		if (k != -1 && k <= 1 && ans != 0 && split[i] == 1) {
			split[i] = 0;
			ans--;
		}
	}
	fprintf(f2, "%d\n", ans);
	for (int i = 1; i <= n; i++) {
		if (split[i] == 1)
			fprintf(f2, "%d ", i);
	}
	fclose(f1);
	fclose(f2);
	return 0;
}