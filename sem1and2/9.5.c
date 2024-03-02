#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#define N 100001
int A[N] = { 0 };
void ins_sort(int A[], int n) {
	for (int i = 1; i < n; i++) {
		int x = A[i];
		int j = i - 1;
		while (j >= 0 && A[j] > x) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = x;
	}
}
int main() {
	unsigned int a, i = 0;
	FILE* f = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	while (fscanf(f, "%d", &a) == 1) {
		A[i] = a;
		i++;
	}
	fclose(f);
	int len = i, d;
	ins_sort(A, len);
	d = A[1] - A[0];
	for (int i = 0; i < len - 1; i++) {
		if (A[i + 1] - A[i] != d) {
			fprintf(f2, "NO");
			fclose(f2);
			return 0;
		}
	}
	fprintf(f2, "%d", d);
	fclose(f2);
	return 0;
}