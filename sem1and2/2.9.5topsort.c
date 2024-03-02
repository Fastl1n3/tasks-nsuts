#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 10001
int flag = 0;
int sort[N] = { 0 };
int new_por[N] = { 0 };
int g = 1;
typedef struct list {
	int value;
	int color;
	struct list* next;
} Ver;
Ver* A[N] = { 0 };
int Srch(Ver* u, int n) {
	A[u->value]->color = 1;
	Ver* v = u->next;
	while (v != NULL) {
		if (A[v->value]->color == 1) {
			flag = 1;
			break;
		}
		if (A[v->value]->color == 0) {
			Srch(A[v->value], n);
		}
		v = v->next;
	}
	A[u->value]->color = 2;
	sort[g] = u->value;
	g++;
}
void DFS(Ver** A, int n) {
	for (int j = 1; j <= n; j++) {
		if (A[j]->color == 0) {
			Srch(A[j], n);
		}
		
	}
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
	for (int i = 1; i <= n; i++) {
		Ver* v = (Ver*)malloc(sizeof(Ver));
		v->value = i;
		v->next = NULL;
		v->color = 0;
		A[i] = v;
	}
	int i, j;
	for (int g = 0; g < m; g++) {
		fscanf(f1, "%d%d", &i, &j);
		A[i] = append(A[i], j);
	}
	for (int i = 1; i <= n; i++) {
		Ver* p = A[i];
		while (p != NULL) {
			fprintf(f2, "%d ", p->value);
			p = p->next;
		}
		fprintf(f2, "\n");
	}
	fprintf(f2, "\n");
	DFS(A, n);
	if (flag == 0) {
		for (int i = n; i >= 1; i--) {
			new_por[sort[i]] = n - i + 1;
		}
		for (int i = 1; i <= n; i++) {
			fprintf(f2, "%d ", new_por[i]);
		}
	}
	else
		fprintf(f2, "-1");
	fprintf(f2, "\n");
	fclose(f1);
	fclose(f2);
	return 0;
}