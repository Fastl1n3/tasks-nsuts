#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define N 200001
int A[N] = { 0 };
int heapR[N] = { 0 };
int heapL[N] = { 0 };
int left(i) {
	return 2 * i + 1;
}
int right(i) {
	return 2 * i + 2;
}
int parent(i) {
	return  (i + 1) / 2 - 1;
}
void swap(int i1, int i2, int arr[]) {
	int m = arr[i1];
	arr[i1] = arr[i2];
	arr[i2] = m;
}
int build_max_heap(int n, int arr[]) {
	int size = n;
	for (int i = n / 2 - 1; i >= 0; i--) {
		sift_down(i, size, arr);
	}
	return size;
}
int heap_insert(int x, int size, int arr[]) {
	int i = size;
	size += 1;
	arr[i] = x;
	sift_up(i, arr);
	return size;
}
int sift_up(int i, int arr[]) {
	if (i == 0)
		return;
	if (arr[i] > arr[parent(i)]) {
		swap(i, parent(i), arr);
		sift_up(parent(i), arr);
	}
}
int sift_down(int i, int size, int arr[]) {
	int l, r, max;
	l = left(i);
	r = right(i);
	if (l < size && arr[l] > arr[i])
		max = l;
	else
		max = i;
	if (r < size && arr[r] > arr[max])
		max = r;
	if (max != i) {
		swap(i, max, arr);
		sift_down(max, size, arr);
	}
}
int pop(int size, int arr[]) {
	int a;
	a = arr[0];
	arr[0] = arr[size - 1];
	sift_down(0, size, arr);
	return a;
}
int main() {
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	int n, x, heap_sizeR = 0, heap_sizeL = 0, l = 0, r = 0, max;
	fscanf(f1, "%d", &n);
	for (int i = 0; i < n; i++) {
		fscanf(f1, "%d", &A[i]);
	}
	char c;
	for (int i = 0; i < 2 * n - 1; i++) {
		fscanf(f1, "%c", &c);
		if (c == '\n' || c == ' ')
			fscanf(f1, "%c", &c);
		if (c == 'R') {
			heap_sizeR = heap_insert(A[r], heap_sizeR, heapR);
			r++;
		}
		else {
			heap_sizeL = heap_insert(A[l], heap_sizeL, heapL);
			l++;
			while (heapL[0] == heapR[0] && heap_sizeL > 0) {
				pop(heap_sizeL, heapL);
				heap_sizeL--;
				pop(heap_sizeR, heapR);
				heap_sizeR--;
			}
		}
		max = heapR[0];
		fprintf(f2, "%d\n", max);
	}
	fprintf(f2, "\n");
	fclose(f1);
	fclose(f2);
	return 0;
}