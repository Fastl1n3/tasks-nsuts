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
int cost[N][3] = { 0 };
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
int left(i) {
	return 2 * i;
}
int right(i) {
	return 2 * i + 1;
}
int parent(i) {
	return  i / 2;
}
void swap(int i1, int i2) {
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
int heap_insert(int l, int v, int w, int size) {
	int i = size;
	size += 1;
	cost[i][0] = l;
	cost[i][1] = v;
	cost[i][2] = w;
	sift_up(i);
	return size;
}
int sift_up(int i) {
	if (i == 0)
		return;
	if (cost[i][0] < cost[parent(i)][0]) {
		swap(i, parent(i));
		sift_up(parent(i));
	}
}
void sift_down(int i, int size) {
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
		swap(i, min);
		sift_down(min, size);
	}
}
int* pop(int size) {
	int a[3];
	a[0] = cost[0][0];
	a[1] = cost[0][1];
	a[2] = cost[0][2];
	cost[0][0] = cost[size - 1][0];
	cost[0][1] = cost[size - 1][1];
	cost[0][2] = cost[size - 1][2];
	sift_down(0, size);
	return a;
}
int S[N] = { 0 };
int deikstra(Ver** A, int v0, int s2, int n) {
	S[v0] = 1;
	int way = 0;
	int heap_size = heap_insert(0, v0, v0, 0);
	int len = 0;
	for (int i = 1; i <= n; i++) {
		if (i != v0)
			heap_size = heap_insert(INT_MAX, v0, i, heap_size);
		else {
			Ver* p = A[i]->next;
			while (p != NULL) {
				heap_size = heap_insert(p->rebro, v0, p->value, heap_size);
				p = p->next;
			}
		}
	}
	while (len != n) {
		int* w = pop(heap_size);
		heap_size--;
		S[w[2]] = 1;
		len++;
		Ver* p = A[w[2]]->next;
		while (p != NULL) {
			if (S[p->value] == 0) {
				for (int i = 1; i <= heap_size; i++) {
					if (cost[i][2] == p->value) {
						cost[i][0] = (cost[i][0] < w[0] + p->rebro) ? cost[i][0] : w[0] + p->rebro;
						if (p->value == s2)
							way = cost[i][0];
						sift_up(i);
						break;
					}
				}
			}
			p = p->next;
		}
	}
	return way;
}

int main() {
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	int n;
	fscanf(f1, "%d", &n);
	int s1, s2;
	fscanf(f1, "%d%d", &s1, &s2);
	if (s1 == s2) {
		fprintf(f2, "0");
		return 0;
	}
	for (int i = 0; i <= n; i++) {
		Ver* v = (Ver*)malloc(sizeof(Ver));
		v->value = i;
		v->next = NULL;
		v->color = 0;
		A[i] = v;
	}
	int i, j, r;
	while (fscanf(f1, "%d%d%d", &i, &j, &r) == 3) {
		A[i] = append(A[i], j, r);
		A[j] = append(A[j], i, r);
	}
	int ans = deikstra(A, s1, s2, n);
	if (ans != 0)
		fprintf(f2, "%d\n", ans);
	else
		fprintf(f2, "no\n");
	//for (int i = 1; i <= n; i++) {
	//	Ver* p = A[i];
	//	while (p != NULL) {
	//		fprintf(f2, "%d ", p->value);
	//		p = p->next;
	//	}
	//	fprintf(f2, "\n");
	//}
	//fprintf(f2, "\n");
	fclose(f1);
	fclose(f2);
	return 0;
}