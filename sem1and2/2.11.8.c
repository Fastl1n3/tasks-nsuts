#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 200002
typedef struct list {
	int value;
	int rebro;
	int num;
	struct list* next;
} Ver;
Ver* A[N] = { 0 };

Ver* append(Ver* x, int val, int r, int num) {
	Ver* tmp = (Ver*)malloc(sizeof(Ver));
	tmp->value = val;
	tmp->rebro = r;
	tmp->num = num;
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
int left(i) {
	return 2 * i + 1;
}
int right(i) {
	return 2 * i + 2;
}
int parent(i) {
	return  (i + 1) / 2 - 1;
}
void swap(int cost[][3], int i1, int i2) {
	int m0 = cost[i1][0];
	int m1 = cost[i1][1];
	int m2 = cost[i1][2];
	cost[i1][0] = cost[i2][0];
	cost[i1][1] = cost[i2][1];
	cost[i1][2] = cost[i2][2];
	cost[i2][0] = m0;
	cost[i2][1] = m1;
	cost[i2][2] = m2;
}
int heap_insert(int cost[][3], int l, int v, int w, int size) {
	int i = size;
	size += 1;
	cost[i][0] = l;
	cost[i][1] = v;
	cost[i][2] = w;
	sift_up(cost, i);
	return size;
}
int sift_up(int cost[][3], int i) {
	if (i == 0)
		return;
	if (cost[i][0] < cost[parent(i)][0]) {
		swap(cost, i, parent(i));
		sift_up(cost, parent(i));
	}
}
void sift_down(int cost[][3], int i, int size) {
	int l, r, min;
	l = left(i);
	r = right(i);
	if (l < size && cost[l][0] < cost[i][0])
		min = l;
	else
		min = i;
	if (r < size && cost[r][0] < cost[min][0])
		min = r;
	if (min != i) {
		swap(cost, i, min);
		sift_down(cost, min, size);
	}
}
int pop(int cost[][3], int size) {
	int a = cost[0][2];
	cost[0][0] = cost[size - 1][0];
	cost[0][1] = cost[size - 1][1];
	cost[0][2] = cost[size - 1][2];
	sift_down(cost, 0, size);
	return a;
}

int cost[N][3] = { 0 };

int deikstra(Ver** A, int v0, int s2, int n, FILE* f, int* dad, int* S, long long *D) {
	if (A[v0] == NULL)
		return 0;
	for (int i = 1; i <= n; i++) {
		D[i] = INT_MAX;
	}
	S[v0] = 1;
	int heap_size = heap_insert(cost, 0, v0, v0, 0);
	int len = 0;
	Ver* p = A[v0]->next;
	D[v0] = 0;
	while (p != NULL) {
		heap_size = heap_insert(cost, p->rebro, v0, p->value, heap_size);
		dad[p->value] = v0;
		if (p->rebro < D[p->value] || D[p->value] == 0)
			D[p->value] = p->rebro;
		p = p->next;
	}
	while (len != n) {
		int v = pop(cost, heap_size);
		heap_size--;
		S[v] = 1;
		if (A[v] != NULL) {
			Ver* p = A[v]->next;
			while (p != NULL) {
				if (S[p->value] == 0) {
					if (D[p->value] == INT_MAX) {
						heap_size = heap_insert(cost, D[v] + p->rebro, v0, p->value, heap_size);
						D[p->value] = D[v] + p->rebro;
						dad[p->value] = v;
					}
					else {
						if (D[p->value] > D[v] + p->rebro) {
							D[p->value] = D[v] + p->rebro;
							dad[p->value] = v;
							for (int i = 0; i < heap_size; i++) {
								if (cost[i][2] == p->value) {
									cost[i][0] = D[p->value];
									sift_up(cost, i);
									break;
								}
							}
						}

					}
				}
				p = p->next;
			}
		}
		if (heap_size <= 0)
			break;
	}
	if (D[s2] == 0 || D[s2] == INT_MAX) {
		return 0;
	}
	fprintf(f, "quarantine %lld ", D[s2]);
	int i = s2, k = 0, g = 0;
	int reverse[N] = { 0 };
	while (i != v0) {
		int predok = dad[i];
		k++;
		Ver* p = A[predok]->next;
		int min = INT_MAX;
		while (p != NULL) {
			if (p->value == i && p->rebro < min) {
				min = p->rebro;
				reverse[g] = p->num;
			}
			p = p->next;
		}
		g++;
		i = predok;
	}
	fprintf(f, "%d ", k);
	for (int i = g - 1; i >= 0; i--) {
		fprintf(f, "%d ", reverse[i]);
	}
	fprintf(f, "\n");
	return 1;
}

int main() {
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	int n, m, k;
	int t1 = time(NULL);
	fscanf(f1, "%d%d%d", &n, &m, &k);
	int requests[21][2] = { 0 };
	for (int i = 0; i < k; i++) {
		fscanf(f1, "%d%d", &requests[i][0], &requests[i][1]);
	}
	int i, j, r;
	for (int g = 1; g <= m; g++) {
		fscanf(f1, "%d%d%d", &i, &j, &r);
		if (i == j)
			continue;
		if (A[i] == NULL) {
			Ver* v = (Ver*)malloc(sizeof(Ver));
			v->value = i;
			v->rebro = 0;
			v->next = NULL;
			A[i] = v;
		}
		A[i] = append(A[i], j, r, g);
	}
	for (int i = 0; i < k; i++) {
		int* dad = (int*)calloc(n + 1, sizeof(int));
		int* S = (int*)calloc(n + 1, sizeof(int));
		long long* D = (long*)calloc(n + 1, sizeof(long long));
		int ans = deikstra(A, requests[i][0], requests[i][1], n, f2, dad, S, D);
		free(dad);
		free(S);
		free(D);
		if (ans == 0)
			fprintf(f2, "DOOMED\n");
	}
	printf("%d ", time(NULL) - t1);
	fclose(f1);
	fclose(f2);
	return 0;
}