#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 100001
typedef struct LongNum_s {
	int len;
	int arr[500];
} LongNum;
int sum(int* a1, int* a2, int len) {
	int d = 0,i = 0;
	int a[500] = { 0 };
	a1[len] = 0;
	for (i = 0; i < len; i++) {
		a[i] = a1[i] + a2[i];
		a[i] += d;
		d = a[i] / 10;
		a[i] %= 10;
		a1[i] = a2[i];
		a2[i] = a[i];
	}
	if (d != 0) {
		a2[i] = d;
		return i + 1;
	}	
	return i;
}
int main() {
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	int n;
	LongNum a, a1, a2;
	a1.arr[0] = 1;
	a1.len = 1;
	a2.arr[0] = 1;
	a2.len = 1;
	fscanf(f1, "%d", &n);
	for (int i = 3; i <= n; i++) {
		a2.len = sum(a1.arr, a2.arr, a2.len);
	}
	for (int i = a2.len - 1; i >= 0; i--) {
		fprintf(f2, "%d", a2.arr[i]);
	}
	fclose(f1);
	fclose(f2);
	return 0;
}