#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 100003
typedef struct list {
	int value;
	int color;
	int komp_sv;
	struct list* next;
} Ver;
Ver* A[N] = { 0 };
Ver* At[N] = { 0 };
int time_out[N] = { 0 };
int nums[4*N] = { 0 };
int time = 0;
int Srch(Ver** A, Ver* u, int n) {
	A[u->value]->color = 1;
	time++;
	Ver* v = u->next;
	while (v != NULL) {
		if (A[v->value]->color == 0) {
			Srch(A, A[v->value], n);
		}
		v = v->next;
	}
	A[u->value]->color = 2;
	time_out[u->value] = time++;
}
void DFS(Ver** A, int n) {
	int t = 0;
	for (int j = 1; j <= n; j++) {
		if (A[j]->color == 0)
			Srch(A, A[j], n);
	}
}
int DFSt(Ver** At, int* nums, int n) {
	int nk = 0, max = 0;
	for (int j = 2 * n; j >= 1; j--) {
		if (nums[j] == 0)
			continue;
		if (At[nums[j]]->color == 0) {
			nk++;
			Srcht(At, At[nums[j]], nk, n);
			if (nk > max)
				max = nk;
		}
	}
	return max;
}
int Srcht(Ver** At, Ver* u, int nk, int n) {
	At[u->value]->color = 1;
	At[u->value]->komp_sv = nk;
	Ver* v = u->next;
	while (v != NULL) {
		if (At[v->value]->color == 0) {
			Srcht(At, At[v->value], nk, n);
		}
		v = v->next;
	}
	At[u->value]->color = 2;
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
		Ver* v2 = (Ver*)malloc(sizeof(Ver));
		v2->value = i;
		v2->next = NULL;
		v2->color = 0;
		At[i] = v2;
	}
	int i, j;
	for (int g = 0; g < m; g++) {
		fscanf(f1, "%d%d", &i, &j);
		A[i] = append(A[i], j);
		At[j] = append(At[j], i);
	}
	DFS(A, n);
	for (int i = 1; i <= n; i++) {
		int index = time_out[i];
		nums[index] = i;
	}
	
	fprintf(f2, "%d\n", DFSt(At, nums, n));
	/*for (int i = 1; i <= n; i++) {
		Ver* p = At[i];
		while (p != NULL) {
			fprintf(f2, "%d ", p->value);
			p = p->next;
		}
		fprintf(f2, "\n");
	}
	fprintf(f2, "\n");*/
	for (int i = 1; i <= n; i++) {
		fprintf(f2, "%d ", At[i]->komp_sv);
	}
	fclose(f1);
	fclose(f2);
	return 0;
}