#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 10001
void name(FILE *f1, FILE *f2) {
	unsigned char c = 0;
	fread(&c, 1, 1, f1);
	fprintf(f2, "    \"");
	while (c != 0) {
		fprintf(f2, "%c", c);
		fread(&c, 1, 1, f1);
	}
	fprintf(f2, "\": ");
}
int main() {
	FILE* f1 = fopen("input.bin", "rb");
	FILE* f2 = fopen("output.txt", "w");
	double dbl;
	int n, int32;
	char t, bl;
	long long int int64;
	fread(&n, sizeof(n), 1, f1);
	fprintf(f2, "{\n");
	//printf("%d ", n);
	while (ftell(f1) < n - 1) {
		fread(&t, 1, 1, f1);
		//printf("(%d) ", t);
		name(f1, f2);
		if (t == 1) {
			fread(&dbl, sizeof(double), 1, f1);
			fprintf(f2, "%0.15g", dbl);
		}
		if (t == 2) {
			char c;
			unsigned char str[N] = { 0 };
			int len;
			fread(&len, sizeof(len), 1, f1);
			fread(str, sizeof(char), len - 1, f1);
			fprintf(f2, "\"%s\"", str);
			fread(&c, 1, 1, f1);
		}
		if (t == 8) {
			fread(&bl, 1, 1, f1);
			if (bl == 1)
				fprintf(f2, "true");
			else
				fprintf(f2, "false");
		}
		if (t == 10) {
			fprintf(f2, "null");
		}
		if (t == 16) {
			fread(&int32, sizeof(int32), 1, f1);
			fprintf(f2, "%d", int32);
		}
		if (t == 18) {
			fread(&int64, sizeof(int64), 1, f1);
			fprintf(f2, "%lld", int64);
		}
		if (ftell(f1) == n - 1)
			fprintf(f2, "\n}");
		else
			fprintf(f2, ",\n");
	}
	fclose(f1);
	fclose(f2);
	return 0;
}