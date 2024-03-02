#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	int n, fact;
	fscanf(f1, "%d", &n);
	double x, sin, y;
	for (int i = 0; i < n; i++) {
		fscanf(f1, "%lf", &x);
		sin = x;
		y = x;
		fact = 1;
		for (int j = 3; j <= 200; j += 2) {
			y = -y * x * x / (j * (j - 1));
			sin += y;
		}
		fprintf(f2, "%0.15lf\n", sin);
	}
	fclose(f1);
	fclose(f2);
	return 0;
}