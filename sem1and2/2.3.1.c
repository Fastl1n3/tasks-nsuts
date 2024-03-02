#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define N 1000001
int A[N] = {0};
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
void sift_down(int i, int size) {
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
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	int n, x, heap_size = 0;
	char s[6] = { 0 };
	fscanf(f1, "%d", &n);
	for (int i = 0; i < n; i++) {
		fscanf(f1, "%s %d", s, &x);
		if (s[1] == 'u') {
			heap_size = heap_insert(x, heap_size);
		}
		else  if (heap_size != 0) {
			fprintf(f2, "%d\n", pop(heap_size));
			heap_size--;
		}
		else
			fprintf(f2, "Heap is empty\n");
		printf("%d\n", heap_size);
	}
	fprintf(f2, "\n");
	fclose(f1);
	fclose(f2);
	return 0;
}