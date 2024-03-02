#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 100001
int main() {
	FILE* f1 = fopen("input.bin", "rb");
	FILE* f2 = fopen("output.bin", "wb");
	char n;
	for (int i = 0; i < 4; i++) {
		fread(&n, sizeof(n), 1, f1);
		printf("%d ", n);
	}
	return 0;
}