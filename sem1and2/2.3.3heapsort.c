#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define N 500001
int A[N] = { 0 };
int left(i) {
	return 2 * i + 1;
}
int right(i) {
	return 2 * i + 2;
}
int parent(i) {
	return  (i + 1) / 2 - 1;
}
void swap(int i1, int i2) {
	int m = A[i1];
	A[i1] = A[i2];
	A[i2] = m;
}
int build_max_heap(int n) {
	int size = n;
	for (int i = n / 2 - 1; i >= 0; i--) {
		sift_down(i, size);
	}
	return size;
}
int heap_insert(int x, int size) {
	int i = size;
	size += 1;
	A[i] = x;
	sift_up(i);
	return size;
}
int sift_up(int i) {
	if (i == 0)
		return;
	if (A[i] < A[parent(i)]) {
		swap(i, parent(i));
		sift_up(parent(i));
	}
}
int sift_down(int i, int size) {
	int l, r, min;
	l = left(i);
	r = right(i);
	if (l < size && A[l] < A[i])
		min = l;
	else
		min = i;
	if (r < size && A[r] < A[min])
		min = r;
	if (min != i) {
		swap(i, min);
		sift_down(min, size);
	}
}
int pop(int size) {
	int a;
	a = A[0];
	A[0] = A[size - 1];
	sift_down(0, size);
	return a;
}
int main() {
	FILE* f1 = fopen("input.bin", "rb");
	FILE* f2 = fopen("output.bin", "wb");
	int n, x, heap_size;
	fread(&n, sizeof(n), 1, f1);
	for (int i = 0; i < n; i++) {
		fread(&A[i], sizeof(int), 1, f1);
	}
	heap_size = build_max_heap(n);
	for (int i = 0; i < n; i++) {
		x = pop(heap_size);
		heap_size--;
		fwrite(&x, sizeof(x), 1, f2);
	}
	fclose(f1);
	fclose(f2);
	return 0;
}