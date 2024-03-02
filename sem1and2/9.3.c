#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
int main() {
	unsigned char c;
	FILE* f = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	int k = 0;
	while (fscanf(f, "%c", &c) == 1) {
		if (c == '\n')
			k++;
	}
	fclose(f);
	fprintf(f2, "%d", k);
	fclose(f2);
	return 0;
}