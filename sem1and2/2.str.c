#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define N 600002
char s_in[N];
char s_out[N];
int main() {
	FILE* f1 = fopen("S.txt", "r");
	FILE* f2 = fopen("input.txt", "w");
	char c;
	int i = 0;
	while (fscanf(f1, "%c", &c) == 1) {
		if (c != ' ') {
			s_in[i] = c;
			i++;
		}
	}
	printf("%d", i);
	for (int i = 0; i < 175; i++) {
		fprintf(f2, "%s", s_in);
	}

	fclose(f1);
	fclose(f2);
	return 0;
}
