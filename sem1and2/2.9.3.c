#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 20002
typedef struct list {
	int value;
	int num;
	struct list* next;
} Ver;
Ver* A[N] = { 0 };
int color[N] = { 0 };
int DFS(Ver** A, int n) {
	int nk = 0, max = 0;
	for (int j = 1; j <= n; j++) {
		if (color[j] == 0) {
			nk++;
			search(A[j], nk, n);
			if (nk > max)
				max = nk;
		}	
	}
	return max;
}
int search(Ver* u, int nk, int n) {
	color[u->value] = 1;
	A[u->value]->num = nk;
	Ver* v = u->next;
	while (v != NULL) {
		if (color[v->value] == 0) {
			
			search(A[v->value], nk, n);
		}
		v = v->next;
	}
	color[u->value] = 2;
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
		A[i] = v;
	}
	int i, j;
	for (int g = 0; g < m; g++) {
		fscanf(f1, "%d%d", &i, &j);
		A[i] = append(A[i], j);
		A[j] = append(A[j], i);
	}
	/*for (int i = 1; i <= n; i++) {
		Ver* p = A[i];
		while (p != NULL) {
			fprintf(f2, "%d ", p->value);
			p = p->next;
		}
		fprintf(f2, "\n");
	}
	fprintf(f2, "\n");*/
	fprintf(f2, "%d\n", DFS(A, n));
	for (int i = 1; i <= n; i++) {
		fprintf(f2, "%d ", A[i]->num);
	}
	fclose(f1);
	fclose(f2);
	return 0;
}