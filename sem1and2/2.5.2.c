#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define N 1000001
int arr[21][2] = { 0 };
int split[21] = { 0 };
int opts[21] = { 0 };
int Try(int i, int n, int wmax, int w_tek, int c_tek, int max_c) {
	if (arr[i][0] + w_tek <= wmax) {
		w_tek += arr[i][0];
		c_tek += arr[i][1];
		split[i] = 1;
		if (i < n - 1) {
			Try(i + 1, n, wmax, w_tek, c_tek, max_c);
		}
		else {
			if (c_tek > max_c) {
				max_c = c_tek;
				for (int j = 0; j < n; j++)
					opts[j] = split[j];
			}
		}
		w_tek -= arr[i][0];
		c_tek -= arr[i][1];
		split[i] = 0;
	}
	if (c_tek > max_c + arr[i][1]) {
		if (i < n - 1)
			Try(i + 1, n, wmax, w_tek, c_tek, max_c);
		else {
			if (c_tek > max_c) {
				max_c = c_tek;
				for (int j = 0; j < n; j++)
					opts[j] = split[j];
			}
		}
	}
}
	
int main() {
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");

	int n;
	int wmax, w_tek, c_tek;
	fscanf(f1, "%d%d", &n, &wmax);
	for (int i = 0; i < n; i++) {
		fscanf(f1, "%d%d", &arr[i][0], &arr[i][1]);
	}
	Try(0, n, wmax, 0, 0, 0, 0);
	
	for (int i = 0; i < n; i++) {
		if (opts[i] != 0)
			fprintf(f2, "%d %d\n", i, arr[i][1]);
	}
	fclose(f1);
	fclose(f2);
	return 0;
}