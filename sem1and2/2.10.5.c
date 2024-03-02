#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define N 501
int A[N][N] = { 0 };
char B[1000001] = { 0 };
typedef struct node {
	int v1;
	int v2;
	int cond;
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
void enqueue(Queue* q, int k1, int k2, int cond) {
	list* L = (list*)malloc(sizeof(list));
	L->v1 = k1;
	L->v2 = k2;
	L->cond = cond;
	L->next = NULL;
	if (empty(q) == 0)
		q->end->next = L;
	q->end = L;
	if (empty(q) == 1)
		q->first = q->end;
}
int* dequeue(Queue* q) {
	int out[3];
	out[0] = q->first->v1;
	out[1] = q->first->v2;
	out[2] = q->first->cond;
	list* p = q->first;
	q->first = p->next;
	free(p);
	return out;
}
int empty(Queue* q) {
	return(q->first == NULL);
}
int check_condition(int condition, int place) {
	if (condition - place == 0) 
		return 0;
	if (abs(condition - place) == 1 || abs(condition - place) == 3)
		return 1;
	if (abs(condition - place) == 2)
		return 2;
}
int BFS(int A[][N], Queue* Q, int i1, int j1, int i2, int j2) {
	A[i1][j1] = 1;
	int condition = 1;
	enqueue(Q, i1, j1, condition);
	int f = 0;
	while (empty(Q) == 0) {
		int* u = dequeue(Q);
		int i = u[0];
		int j = u[1];
		condition = u[2];
		int kolvo_pov;
		if (i == i2 && j == j2) {
			f = 1;
			break;
		}
		kolvo_pov = check_condition(condition, 1);
		if (A[i - 1][j] != 0 && (A[i][j] + 1 + kolvo_pov < A[i-1][j] || A[i - 1][j] == 1) ) {
			A[i - 1][j] = A[i][j] + 1 + kolvo_pov;
			enqueue(Q, i - 1, j, 1);
		}
		kolvo_pov = check_condition(condition, 2);
		if (A[i][j + 1] != 0 && (A[i][j] + 1 + kolvo_pov < A[i][j + 1] || A[i][j + 1] == 1) ) {
			
			A[i][j + 1] = A[i][j] + 1 + kolvo_pov;
			enqueue(Q, i, j + 1, 2);
		}
		kolvo_pov = check_condition(condition, 3);
		if (A[i + 1][j] != 0 && (A[i][j] + 1 + kolvo_pov < A[i + 1][j] || A[i + 1][j] == 1)) {
			
			A[i + 1][j] = A[i][j] + 1 + kolvo_pov;
			enqueue(Q, i + 1, j, 3);
		}
		kolvo_pov = check_condition(condition, 4);
		if (A[i][j - 1] != 0 && (A[i][j] + 1 + kolvo_pov < A[i][j - 1] || A[i][j - 1] == 1)) {
			
			A[i][j - 1] = A[i][j] + 1 + kolvo_pov;
			enqueue(Q, i, j - 1, 4);
		}
		
	}
	if (f == 0)
		return 0;
	else
		return condition;

}
void reverse(int A[][N], FILE* f, int i1, int j1, int i2, int j2, int condition) {
	int i = i2, j = j2, g = 0, c = 0;;
	while (i != i1 || j != j1) {
		if (condition == 1) {
			B[g] = 'F';
			g++;
			if (A[i + 1][j] == -2) {
				break;
			}
			if (A[i][j] - A[i + 1][j] == 1)
				i = i + 1;
			else if (A[i][j] - A[i + 1][j] == 2) {
				
				if (A[i + 1][j] - A[i + 1][j + 1] == 1) {
					B[g] = 'R';
					g++;
					condition = 4;
				}
				else {
					condition = 2;
					B[g] = 'L';
					g++;
				}
				i = i + 1;
			}
			else if (A[i][j] - A[i][j + 1] == 2 || A[i][j] - A[i][j + 1] == 1) {
				condition = 4;
				B[g] = 'R';
				g++;
				j = j + 1;
			}
			else if (A[i][j] - A[i][j - 1] == 2 || A[i][j] - A[i][j - 1] == 1) {
				B[g] = 'L';
				g++;
				condition = 2;
				j = j - 1;
			}
		}
		if (condition == 2) {
			B[g] = 'F';
			g++;
			if (A[i][j - 1] == -2) {
				B[g] = 'R';
				g++;
				break;
			}
			if (A[i][j] - A[i][j - 1] == 1)
				j = j - 1;	
			else if (A[i][j] - A[i][j - 1] == 2) {
				
				if (A[i][j - 1] - A[i - 1][j - 1] == 1) {
					B[g] = 'L';
					g++;
					condition = 3;
				}
				else {
					B[g] = 'R';
					g++;
					condition = 1;
				}
				j = j - 1;
			}
			else if (A[i][j] - A[i + 1][j] == 2 || A[i][j] - A[i + 1][j] == 1) {
				condition = 1;
				B[g] = 'R';
				g++;
				i = i + 1;
			}
			else if (A[i][j] - A[i - 1][j] == 2 || A[i][j] - A[i - 1][j] == 1) {
				condition = 3;
				B[g] = 'L';
				g++;
				i = i - 1;
			}
		}
		if (condition == 3) {
			B[g] = 'F';
			g++;
			if (A[i - 1][j] == -2) {
				B[g] = 'R';
				g++;
				B[g] = 'R';
				g++;
				break;
			}
			if (A[i][j] - A[i - 1][j] == 1)
				i = i - 1;
			else if (A[i][j] - A[i - 1][j] == 2) {
				if (A[i - 1][j] - A[i - 1][j - 1] == 1) {
					B[g] = 'R';
					g++;
					condition = 2;
				}
				else {
					condition = 4;
					B[g] = 'L';
					g++;
				}
				i = i - 1;
			}
			else if (A[i][j] - A[i][j + 1] == 2 || A[i][j] - A[i][j + 1] == 1) {
				condition = 4;
				B[g] = 'L';
				g++;
				j = j + 1;
			}
			else if (A[i][j] - A[i][j - 1] == 2 || A[i][j] - A[i][j - 1] == 1) {
				B[g] = 'R';
				g++;
				condition = 2;
				j = j - 1;
			}
		}
		if (condition == 4) {
			B[g] = 'F';
			g++;
			if (A[i][j + 1] == -2) {
				B[g] = 'L';
				g++;
				break;
			}
			if (A[i][j] - A[i][j + 1] == 1)
				j = j + 1;
			else if (A[i][j] - A[i][j + 1] == 2) {
				if (A[i][j + 1] - A[i - 1][j + 1] == 1) {
					B[g] = 'R';
					g++;
					condition = 3;
				}
				else {
					condition = 1;
					B[g] = 'L';
					g++;
				}
				j = j + 1;
			}
			else if (A[i][j] - A[i + 1][j] == 2 || A[i][j] - A[i + 1][j] == 1) {
				condition = 1;
				B[g] = 'L';
				g++;
				i = i + 1;
			}
			else if (A[i][j] - A[i - 1][j] == 2 || A[i][j] - A[i - 1][j] == 1) {
				condition = 3;
				B[g] = 'R';
				g++;
				i = i - 1;
			}
		}
		c++;
		if (c == 50)
			break;
	}

}
int main() {
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	int n, m, i1, j1, i2, j2;
	Queue* Q = create();
	fscanf(f1, "%d%d", &m, &n);
	char c;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			fscanf(f1, "%c", &c);
			if (c == '\n')
				fscanf(f1, "%c", &c);
			if (c == '.')
				A[i][j] = 1;
			if (c == 'T') {
				A[i][j] = 1;
				i2 = i;
				j2 = j;
			}
			if (c == '#')
				A[i][j] = 0;
			if (c == 'S') {
				A[i][j] = 1;
				i1 = i;
				j1 = j;
			}
		}
	}
	
	int last_condition = BFS(A, Q, i1, j1, i2, j2);
	if (last_condition == 0) {
		fprintf(f2, "-1\n");
		return 0;
	}
	else
		fprintf(f2, "%d\n", A[i2][j2] - 1);
	A[i1][j1] = -2;
	printf("%d %d ", i1, j1);
	reverse(A, f2, i1, j1, i2, j2, last_condition);
	for (int i = A[i2][j2] - 2; i >= 0; i--) {
		fprintf(f2, "%c", B[i]);
	}
	fprintf(f2, "\n");
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