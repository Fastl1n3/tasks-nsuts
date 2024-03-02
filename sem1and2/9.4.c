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
	for (int i = 32; i < 127; i++) {
		if (A[i] != 0) {
			fprintf(f2, "%c ", i);
			for (int j = 0; j < A[i]; j++) {
				fprintf(f2, "#");
			}
			fprintf(f2, "\n");
		}
	}
	fclose(f2);
	return 0;
}