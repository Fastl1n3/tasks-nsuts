#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define N 100001
int A[N] = { 0 };
int max_count[N] = { 0 };
int split[N] = { 0 };
int Max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}
int main() {
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	int n;
	fscanf(f1, "%d", &n);
	for (int i = 0; i < n; i++) {
		fscanf(f1, "%d", &A[i]);
		max_count[i] = 1;
		for (int j = 0; j < i; j++) {
			if (A[j] < A[i]) {
				max_count[i] = Max(max_count[i], 1 + max_count[j]);
			}
		}
	}
	int max_len = 0, pos;
	for (int i = 0; i < n; i++) {
		if (max_count[i] > max_len) {
			max_len = max_count[i];
			pos = i;
		}
	}
	fprintf(f2, "%d\n", max_len);
	int j = 0;
	for (int i = pos; i >= 0; i--) {
		if (max_count[i] == max_len - j) {
			split[i]++;
			j++;
		}
	}
	for (int i = 0; i < n; i++) {
		if (split[i] != 0)
			fprintf(f2, "A[%d] = %d\n", i + 1, A[i]);
	}
	fclose(f1);
	fclose(f2);
	return 0;
}