#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 2001
#define SIZE 32
int T[N][N] = { 0 };
int main() {
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	int n;
	fscanf(f1, "%d", &n);
	char c;
	int kolvo_polnyh_bytes = n / SIZE;
	int ostatok = n % SIZE;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= kolvo_polnyh_bytes; j++) {
			int u = SIZE - 1;
			for (int g = u; g >= 0; g--) {
				fscanf(f1, "%c", &c);
				if (c == '\n')
					fscanf(f1, "%c", &c);
				T[i][j] += ((c - '0') & 1) << g;
			}
		}
		for (int g = ostatok - 1; g >= 0; g--) {
			fscanf(f1, "%c", &c);
			if (c == '\n')
				fscanf(f1, "%c", &c);
			T[i][kolvo_polnyh_bytes + 1] += ((c - '0') & 1) << g;
		}
	}
	for (int s = 0; s < 2; s++) {
		for (int i = 1; i <= n; i++) {
			int tek_pos = 1;
			for (int j = 1; j <= kolvo_polnyh_bytes; j++) {
				int u = SIZE - 1;
				for (int g = u; g >= 0; g--) {
					if (tek_pos == i)
						T[i][j] = T[i][j] | (1 << g);
					if (T[i][j] & (1 << g)) {
						for (int k = 1; k <= kolvo_polnyh_bytes + 1; k++)
							T[i][k] = T[i][k] | T[tek_pos][k];
					}
					tek_pos++;
				}
			}
			for (int g = ostatok - 1; g >= 0; g--) {
				if (tek_pos == i)
					T[i][kolvo_polnyh_bytes + 1] = T[i][kolvo_polnyh_bytes + 1] | (1 << g);
				if (T[i][kolvo_polnyh_bytes + 1] & (1 << g)) {
					for (int k = 1; k <= kolvo_polnyh_bytes + 1; k++)
						T[i][k] = T[i][k] | T[tek_pos][k];
				}
				tek_pos++;
			}
		}
	}
	
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= kolvo_polnyh_bytes; j++) {
			int u = SIZE - 1;
			for (int g = u; g >= 0; g--) {
				if (T[i][j] & (1 << g))
					fprintf(f2, "%d", 1);
				else
					fprintf(f2, "%d", 0);
			}
		}
		for (int g = ostatok - 1; g >= 0; g--) {
			if (T[i][kolvo_polnyh_bytes + 1] & (1 << g))
				fprintf(f2, "%d", 1);
			else
				fprintf(f2, "%d", 0);
		}
		fprintf(f2, "\n");
	}
	fclose(f1);
	fclose(f2);
	return 0;
}