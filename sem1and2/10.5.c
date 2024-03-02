#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 1000001
int A[N] = { 0 };
int partition(int* a, int n, int pivot, int k_pivot) {
	int j = 0, k = 0;
	if (a[0] < pivot)
		k++;
	for (int i = 1; i < n; i++) {
		if (a[i] < pivot)
			k++;
		int x = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > x) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
		
	}
	return k + k_pivot / 2;
}
int main() {
	FILE* f1 = fopen("input.bin", "rb");
	FILE* f2 = fopen("output.bin", "wb");
	int n, p, k_p = 0;
	fread(&n, sizeof(n), 1, f1);
	fread(&p, sizeof(p), 1, f1);
//	printf("%d %d\n", n, p);
	for (int i = 0; i < n; i++) {
		fread(&A[i], sizeof(int), 1, f1);
		//printf("%d ", A[i]);
		if (A[i] == p)
			k_p++;
	}
	printf("\n");
	int k = partition(A, n, p, k_p);
	//printf("\n%d\n", k);
	fwrite(&k, sizeof(k), 1, f2);
	for (int i = 0; i < n; i++) {
		fwrite(&A[i], sizeof(int), 1, f2);
		//printf("%d ", A[i]);
	}
	return 0;
}