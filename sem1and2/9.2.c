#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#define N 10000000
int A[N] = { 0 };
int main() {
	unsigned char s[1001];
	FILE* f = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	int l = 0;
	while (fscanf(f, "%s", s) == 1) {
		int len = strlen(s);
		A[len]++;
	}
	fclose(f);
	for (int i = 1; i < N; i++) {
		if (A[i] != 0)
			fprintf(f2, "%d - %d\n", i, A[i]);
	}
	fclose(f2);
	return 0;
}