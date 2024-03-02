#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#define N 10000000
int A[N] = { 0 };
int main() {
	unsigned char c;
	FILE* f = fopen("input.txt", "r");
	while (fscanf(f, "%c", &c) == 1) {
		A[c]++;
	}
	fclose(f);
	FILE* f2 = fopen("output.txt", "w");
	for (int i = 13; i < N; i++) {
		if (A[i] != 0)
			fprintf(f2, "%d : %c - %d\n", i, i, A[i]);
	}
	fclose(f2);
	return 0;
}