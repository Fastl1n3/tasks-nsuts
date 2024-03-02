#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#define N 1000001
int A[N][2] = { 0 };
int len(int x) {
	int len = 0;
	while (x > 0) {
		len++;
		x /= 10;
	}
	return len;
}
void write_sym(int len, FILE *f2) {
	fprintf(f2, "+");
	for (int j = 0; j < len + 2; j++)
		fprintf(f2, "-");
}
void write_probel(int l, int max_l,  FILE *f2) {
	for (int j = 0; j < max_l - 1 - l + 2; j++) {
		fprintf(f2, "%c", ' ');
	}
}
	
int main() {
	FILE* f = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	int n, id, t, max_id = 0, sum;
	fscanf(f, "%d", &n);
	int lenmax_t = 0, len_t, lenmax_id = 0, len_id, lenmax_k = 0, len_k;
	for (int i = 0; i < n; i++) {
		fscanf(f, "%d%d", &id, &t);
		if (id > max_id)
			max_id = id;
		A[id][1] += t;
		A[id][0]++;
		len_t = len(A[id][1]);
		if (len_t > lenmax_t)
			lenmax_t = len_t;
		len_id = len(id);
		if (len_id > lenmax_id)
			lenmax_id = len_id;
		len_k = len(A[id][0]);
		if (len_k > lenmax_k)
			lenmax_k = len_k;
	}
	for (int id = 0; id <= max_id; id++) {
		if (A[id][1] != 0) {
			write_sym(lenmax_id, f2);
			write_sym(lenmax_k, f2);
			write_sym(lenmax_t, f2);
			fprintf(f2, "+\n");
			fprintf(f2, "|");
			write_probel(len(id), lenmax_id, f2);
			fprintf(f2, "%d |", id);
			write_probel(len(A[id][0]), lenmax_k, f2);
			fprintf(f2, "%d |", A[id][0]);
			write_probel(len(A[id][1]), lenmax_t, f2);
			fprintf(f2, "%d |\n", A[id][1]);

		}
	}
	write_sym(lenmax_id, f2);
	write_sym(lenmax_k, f2);
	write_sym(lenmax_t, f2);
	fprintf(f2, "+\n");
	return 0;
}