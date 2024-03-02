#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#define N 1000002
char A[N][101] = { 0 };
int main() {
	unsigned int a, i = 0;
	FILE* f = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	char* p = A[N];
	while (fgets(A[i], sizeof(A[i]), f) != NULL) {
		i++;
	}
	fclose(f);
	for (int j = i - 1; j >= 0; j--) {
		fprintf(f2, "%s", A[j]);
	}
	fclose(f2);
	return 0;
}