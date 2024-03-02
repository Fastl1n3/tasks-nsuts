#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
uint64_t A, B, M, R, S;
uint32_t hashFunc(uint32_t x) {
	return (((A * x + B) % M) % R) / S;
}
int main() {
	uint32_t arr[32][32] = { 0 };
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	uint32_t x, hash;
	uint32_t ost_hash, ost_hashnew;
	uint32_t hash_new, x_new, hash_old;
	fscanf(f1, "%llu%llu%llu%llu%llu", &A, &B, &M, &R, &S);
	uint32_t g = 0;
	x = 4294967295;
	for (g; g <260000; g++) {
		x -= g * 7;
		hash = hashFunc(x);
		for (int i = 0; i < 32; i++) {
			x_new = x ^ (1 << i);
			hash_new = hashFunc(x_new, A, B, M, R, S);
			hash_old = hash;
			for (int j = 0; j < 32; j++) {
				ost_hash = hash_old % 2;
				ost_hashnew = hash_new % 2;
				if (ost_hash != ost_hashnew) {
					arr[i][j]++;
				}
				hash_old >>= 1;
				hash_new >>= 1;
			}
		}
	}
	for (int i = 0; i < 32; i++) {
		for (int j = 0; j < 32; j++) {
			fprintf(f2, "%u ", arr[i][j]* 100 / g);
		}
		fprintf(f2, "\n");
	}
	fclose(f1);
	fclose(f2);
	return 0;
}