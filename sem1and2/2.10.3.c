#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define N 1000
int K[N][2] = { 0 };
int T[N][2] = { 0 };
double Q[1000001][3] = { 0 };
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
	double m0 = Q[i1][0];
	int m1 = Q[i1][1];
	int m2 = Q[i1][2];
	Q[i1][0] = Q[i2][0];
	Q[i1][1] = Q[i2][1];
	Q[i1][2] = Q[i2][2];
	Q[i2][0] = m0;
	Q[i2][1] = m1;
	Q[i2][2] = m2;
}
int heap_insert(double l, int v, int w, int size) {
	int i = size;
	size += 1;
	Q[i][0] = l;
	Q[i][1] = v;
	Q[i][2] = w;
	sift_up(i);
	return size;
}
int sift_up(int i) {
	if (i == 0)
		return;
	if (Q[i][0] < Q[parent(i)][0]) {
		swap(i, parent(i));
		sift_up(parent(i));
	}
}
void sift_down(int i, int size) {
	int l, r, min;
	l = left(i);
	r = right(i);
	if (l < size && Q[l][0] < Q[i][0])
		min = l;
	else
		min = i;
	if (r < size && Q[r][0] < Q[min][0])
		min = r;
	if (min != i) {
		swap(i, min);
		sift_down(min, size);
	}
}
int* pop(int size) {
	int a[3];
	a[0] = Q[0][0];
	a[1] = Q[0][1];
	a[2] = Q[0][2];
	Q[0][0] = Q[size - 1][0];
	Q[0][1] = Q[size - 1][1];
	Q[0][2] = Q[size - 1][2];
	sift_down(0, size);
	return a;
}
int p[N] = { 0 };
void makeset(int x) {
	p[x] = x;

}
int check_cs(int n) {
	for (int i = 1; i < n; i++) {
		if (p[i] != p[i + 1])
			return 1;
	}
	return 0;
}
int main() {
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	int n, m;
	int heap_size = 0;
	fscanf(f1, "%d", &n);
	for (int i = 1; i <= n; i++) {
		fscanf(f1, "%d %d", &K[i][0], &K[i][1]);
		makeset(i);
	}
	fscanf(f1, "%d", &m);
	for (int g = 1; g <= m; g++) {
		int i, j;
		fscanf(f1, "%d%d", &i, &j);
		int cs = p[i];
		for (int i = 1; i <= n; i++) {
			if (p[i] == cs) {
				p[i] = p[j];
			}
		}
	}	
	//for (int i = 1; i <= n; i++) {
	//	printf("%d ", p[i]);
	//}
	//printf("\n");
	for (int i = 1; i <= n; i++) {
		int x1 = K[i][0];
		int y1 = K[i][1];
		for (int j = i + 1; j <= n; j++) {
			int x2 = K[j][0];
			int y2 = K[j][1];
			double len = sqrt((x2 - x1)* (x2 - x1) + (y2 - y1)*(y2 - y1));
			heap_size = heap_insert(len, i, j, heap_size);
		}
	}
	int g = 0;
	while (check_cs(n)) {
		int* q = pop(heap_size);
		heap_size--;
		int v = q[1];
		int w = q[2];
		if (p[v] != p[w]) {
			int cs = p[w];
			for (int i = 1; i <= n; i++) {
				if (p[i] == cs) {
					p[i] = p[v];
				}
			}
			T[g][0] = v;
			T[g][1] = w;
			g++;
		}
	}
	//for (int i = 1; i <= n; i++) {
	//	printf("%d ", p[i]);
	//}
	//printf("\n");
	for (int i = 0; i < g; i++) {
		fprintf(f2, "%d %d\n", T[i][0], T[i][1]);
	}
	fclose(f1);
	fclose(f2);
	return 0;
}