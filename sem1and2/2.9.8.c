#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 100002
typedef struct list {
	int value;
	int color;
	int rebro;
	struct list* next;
} Ver;
Ver* A[N] = { 0 };
int enter[N] = { 0 };
int count = 1;
int low[N] = { 0 };
int split[N] = { 0 };
int dad[N] = { 0 };
int Rebra[N][2] = { 0 };
Ver* append(Ver* x, int val, int r) {
	Ver* tmp = (Ver*)malloc(sizeof(Ver));
	tmp->value = val;
	tmp->rebro = r;
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
int Srch(Ver** A, Ver* v, int n, int k) {
	A[v->value]->color = 1;
	enter[v->value] = count;
	count++;
	low[v->value] = enter[v->value];
	Ver* w = v->next;
	while (w != NULL) {
		if (A[w->value]->color == 0) {
			dad[w->value] = v->value;
			k = Srch(A, A[w->value], n, k);
			if (low[w->value] > enter[v->value]) {
				if (check_kr(w, v) == 1) {
					split[w->rebro] = 1;
					k++;
				}
			}
			low[v->value] = (low[v->value] < low[w->value] ? low[v->value] : low[w->value]);
		}
		else if (w->value != dad[v->value] && enter[w->value] < enter[v->value])
			low[v->value] = (low[v->value] < enter[w->value] ? low[v->value] : enter[w->value]);
		
		w = w->next;
	}
	A[v->value]->color = 2;
	return k;
}
int DFS(Ver** A, int n, int m) {
	int k = 0;
	for (int j = 1; j <= n; j++) {
		if (A[j] != NULL && A[j]->color == 0)
			k = Srch(A, A[j], n, k);
	}
	return k;
}

int check_kr(Ver* w ,Ver* v) {
	Ver* p = A[w->value]->next;
	int k = 0;
	while (p != NULL) {
		if (p->value == v->value)
			k++;
		if (k == 2)
			return 0;
		p = p->next;
	}
	return 1;
}
int main() {
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	int n, m;
	fscanf(f1, "%d%d", &n, &m);
	int i, j;
	for (int g = 1; g <= m; g++) {
		fscanf(f1, "%d%d", &i, &j);
		if (A[i] == NULL) {
			Ver* v = (Ver*)malloc(sizeof(Ver));
			v->value = i;
			v->next = NULL;
			v->rebro = 0;
			v->color = 0;
			A[i] = v;
		}
		if (A[j] == NULL) {
			Ver* v = (Ver*)malloc(sizeof(Ver));
			v->value = j;
			v->next = NULL;
			v->rebro = 0;
			v->color = 0;
			A[j] = v;
		}
		Rebra[g][0] = i;
		Rebra[g][1] = j;
		A[i] = append(A[i], j, g);
		A[j] = append(A[j], i, g);
	}
	int ans = DFS(A, n, m);
	//for (int i = 1; i <= n; i++) {
	//	Ver* p = A[i];
	//	while (p != NULL) {
	//		fprintf(f2, "%d ", p->value);
	//		p = p->next;
	//	}
	//	fprintf(f2, "\n");
	//}
	//fprintf(f2, "\n");
	fprintf(f2, "%d\n", ans);
	for (int i = 1; i <= m; i++) {
		if (split[i] == 1)
			fprintf(f2, "%d ", i);
	}
	fclose(f1);
	fclose(f2);
	return 0;
}