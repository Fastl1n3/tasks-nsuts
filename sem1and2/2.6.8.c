#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define N 100001
int A[N] = { 0 };
long long min_value[N] = { 0 };
int split[N] = { 0 };
int index[N] = { 0 }; // индекс последнего элемента в подпосл-ти длины i
int pred[N] = { 0 }; //индекс предыдущего элемента для А[i]
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
	min_value[0] = LLONG_MIN;
	index[0] = -1;
	for (int i = 1; i <= n; i++) {
		min_value[i] = LLONG_MAX;
	}
	int left, right, middle, max_len = 0;;
	for (int i = 0; i < n; i++) {
		fscanf(f1, "%d", &A[i]);
		left = 0;
		right = n;
		while (right - left > 1) {
			middle = (left + right) / 2;
			if (min_value[middle] >= A[i])
				right = middle;
			else
				left = middle;
		}
		min_value[right] = A[i];
		index[right] = i;
		pred[i] = index[right - 1];
		max_len = Max(max_len, right);
	}
	int pos = index[max_len];
	while (pos != -1) {
		split[pos]++;
		pos = pred[pos];
	}
	for (int i = 0; i < n; i++) {
		fprintf(f2, "%d ", min_value[i]);
	}
	fprintf(f2, "\n%d\n", max_len);
	for (int i = 0; i < n; i++) {
		fprintf(f2, "%d ", index[i]);
	}
	fprintf(f2, "\n%d\n", max_len);
	for (int i = 0; i < n; i++) {
		fprintf(f2, "%d ", pred[i]);
	}
	fprintf(f2, "\n%d\n", max_len);
	for (int i = 0; i < n; i++) {
		if (split[i] != 0)
			fprintf(f2, "A[%d] = %d\n", i + 1, A[i]);
	}
	fclose(f1);
	fclose(f2);
	return 0;
}