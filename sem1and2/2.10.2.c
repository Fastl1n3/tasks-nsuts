#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 101
int A[N][N] = { 0 };

typedef struct node {
	int v1;
	int v2;
	struct node* next;
} list;
typedef struct queue {
	list* first;
	list* end;
} Queue;
Queue* create() {
	Queue* q = (Queue*)malloc(sizeof(Queue));
	q->first = NULL;
	q->end = NULL;
	return q;
}
void enqueue(Queue* q, int k1, int k2) {
	list* L = (list*)malloc(sizeof(list));
	L->v1 = k1;
	L->v2 = k2;
	L->next = NULL;
	if (empty(q) == 0)
		q->end->next = L;
	q->end = L;
	if (empty(q) == 1)
		q->first = q->end;
}
int* dequeue(Queue* q) {
	int out[2];
	out[0] = q->first->v1;
	out[1] = q->first->v2;
	list* p = q->first;
	q->first = p->next;
	free(p);
	return out;
}
int empty(Queue* q) {
	return(q->first == NULL);
}

int BFS(int A[][N], Queue* Q, int i1, int j1, int i2, int j2) {
	A[i1][j1] = 1;
	enqueue(Q, i1, j1);
	int f = 0;
	while (empty(Q) == 0) {
		int* u = dequeue(Q);
		int i = u[0];
		int j = u[1];
		if (i == i2 && j == j2) {
			f = 1;
			break;
		}
		if (A[i][j + 1] == 1) {
			A[i][j + 1] = A[i][j] + 1;
			enqueue(Q, i, j + 1);
		}
		if (A[i + 1][j] == 1) {
			A[i + 1][j] = A[i][j] + 1;
			enqueue(Q, i + 1, j);
		}
		if (A[i][j - 1] == 1) {
			A[i][j - 1] = A[i][j] + 1;
			enqueue(Q, i, j - 1);
		}
		if (A[i - 1][j] == 1) {
			A[i - 1][j] = A[i][j] + 1;
			enqueue(Q, i - 1, j);
		}		
	}
	if (f == 0)
		return 0;
	else
		return 1;
	
}
int main() {
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	int n, m, i1, j1, i2, j2;
	Queue* Q = create();
	fscanf(f1, "%d%d", &m, &n);
	char c;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			fscanf(f1, "%c", &c);
			if (c == '\n')
				fscanf(f1, "%c", &c);
			if (c == '.')
				A[i][j] = 1;
			if (c == 'F') {
				A[i][j] = 1;
				i2 = i;
				j2 = j;
			}
			if (c == 'X')
				A[i][j] = -1;
			if (c == 'S') {
				A[i][j] = 1;
				i1 = i;
				j1 = j;
			}
		}
	}
	if (BFS(A, Q, i1, j1, i2, j2) == 0)
		fprintf(f2, "-1");
	else
		fprintf(f2, "%d\n", A[i2][j2] - 1);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			fprintf(f2, "%d ", A[i][j]);
		}
		fprintf(f2, "\n");
	}
	fprintf(f2, "\n");
	fclose(f1);
	fclose(f2);
	return 0;
}