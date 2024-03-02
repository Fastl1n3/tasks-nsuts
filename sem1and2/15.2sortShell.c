#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 1000001
int A[N];
void ins_sort(int* arr, int n, int b, int h) {
	int i = b + h;
	for (i; i < n; i += h) {
		int x = arr[i];
		int j = i - h;
		while (j >= b && arr[j] > x) {
			arr[j + h] = arr[j];
			j -= h;
		}
		arr[j + h] = x;
    }
}
int main() {
    FILE* f1 = fopen("input.txt", "r");
    FILE* f2 = fopen("output.txt", "w");
    int n;
    fscanf(f1, "%d", &n);
    for (int i = 0; i < n; i++) {
        fscanf(f1, "%d", &A[i]);
    }
    int h = 1;
    while (h < n / 6)
        h = 3 * h + 1;
    while (h >= 1) {
        for (int i = 0; i < h; i++)
            ins_sort(A, n, i, h);
        h = (h - 1) / 3;
    }
    for (int i = 0; i < n; i++) {
        fprintf(f2, "%d ", A[i]);
    }
    fclose(f1);
    fclose(f2);
    return 0;
}