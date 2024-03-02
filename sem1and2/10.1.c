#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	FILE* f1 = fopen("input.bin", "rb");
	FILE* f2 = fopen("output.bin", "wb");
	int a = 0;
	long long int s = 0;
	for (int i = 0; i < 2; i++) {
		fread(&a, sizeof(int), 1, f1);
		s += (long long) a;
	}
	if (s % 2 != 0) {
		s /= 2;
		if (s <= 0)
			s--;
	}
	else {
		s /= 2;
	}
	fwrite(&s, sizeof(int), 1, f2);
	fclose(f1);
	fclose(f2);
	return 0;
}