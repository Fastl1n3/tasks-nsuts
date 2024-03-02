#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define N 1001
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
int main() {
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	Queue* q = create();
	int n, b_size, m, a, tek_size = 0;
	fscanf(f1, "%d%d", &b_size, &m);
	int i = 0;
	while (i < m) {
		fscanf(f1, "%d", &n);
		if (n > 0) {
			for (int g = 0; g < n; g++) {
				fscanf(f1, "%d", &a);
				if (tek_size < b_size) {
					enqueue(q, a);
					tek_size++;
				}
				else if (g == n - 1)
					fprintf(f2, "Memory overflow\n");
				i++;
			}
		}
		else {
			int sum = 0, j = 0;
			n = -n;
			for (j; j < n; j++) {
				if (empty(q) == 0) {
					sum += dequeue(q);
					tek_size--;
				}
				else {
					break;
				}
			}
			if (j != 0)
				fprintf(f2, "%d\n", sum / j);
			if (j < n)
				fprintf(f2, "Empty queue\n");
		}
		i++;
	}
	fclose(f1);
	fclose(f2);
	return 0;
}

