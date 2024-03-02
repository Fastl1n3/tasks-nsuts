#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 100001
typedef union dbl {
	double a;
	int b[2];
} Dbl;
typedef union msk {
	long long a;
	int b[2];
}Msk;
int main() {
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	int n;
	int p, q;
	Dbl x;
	Msk mask;
	fscanf(f1, "%d", &n);
	for (int i = 0; i < n; i++) {
		fscanf(f1, "%d/%d xor %llx", &p, &q, &mask);
		//printf("%d %d =", p, q);
		x.a = (double)p / q;
		x.b[0] ^= mask.b[0];
		x.b[1] ^= mask.b[1];
		fprintf(f2, "%0.15g\n", x.a);
	}	
	fclose(f1);
	fclose(f2);
	return 0;
}