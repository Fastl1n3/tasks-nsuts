#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 200002
typedef struct list {
	int value;
	int color;
	int dad;
	int d;
	struct list* next;
} Ver;
Ver* A[N] = { 0 };
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

typedef struct node {
	int value;
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
void enqueue(Queue* q, int k) {
	list* L = (list*)malloc(sizeof(list));
	L->value = k;
	L->next = NULL;
	if (empty(q) == 0)
		q->end->next = L;
	q->end = L;
	if (empty(q) == 1)
		q->first = q->end;
}
int dequeue(Queue* q) {
	int out = q->first->value;
	list* p = q->first;
	q->first = p->next;
	free(p);
	return(out);
}
int first(Queue* q) {
	return q->first->value;
}
int empty(Queue* q) {
	return(q->first == NULL);
}

void BFS(Ver** A, Queue* Q) {
	A[1]->d = 0;
	enqueue(Q, 1);
	while (empty(Q) == 0) {
		int u = first(Q);
		Ver* v = A[u]->next;
		while (v != NULL) {
			if (A[v->value]->color == 0) {
				A[v->value]->color = 1;
				A[v->value]->dad = u;
				A[v->value]->d = A[u]->d + 1;
				enqueue(Q, v->value);
			}
			v = v->next;
		}
		dequeue(Q);
		A[u]->color = 2;
		//printf("%d ", u);
	}
}
int main() {
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	int n, m;
	Queue* Q = create();
	
	fscanf(f1, "%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		Ver* v = (Ver*)malloc(sizeof(Ver));
		v->value = i;
		v->next = NULL;
		v->dad = 0;
		v->color = 0;
		v->d = INT_MAX;
		A[i] = v;
	}
	int i, j;
	for (int g = 0; g < m; g++) {
		fscanf(f1, "%d%d", &i, &j);
		if (i == j)
			continue;
		A[i] = append(A[i], j);
	}
	//for (int i = 1; i <= n; i++) {
	//	Ver* p = A[i];
	//	while (p != NULL) {
	//		fprintf(f2, "%d ", p->value);
	//		p = p->next;
	//	}
	//	fprintf(f2, "\n");
	//}
	//fprintf(f2, "\n");
	BFS(A, Q);
	for (int i = 1; i <= n; i++) {
		if (A[i]->d == INT_MAX)
			fprintf(f2, "-1\n");
		else
			fprintf(f2, "%d\n", A[i]->d);
	}
	fclose(f1);
	fclose(f2);
	return 0;
}