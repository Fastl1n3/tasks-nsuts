#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define N 1001
typedef struct list {
	int time;
	int cost;
	int width;
} List;
List A[101] = { 0 };
int H[30002][102] = { 0 };
void qs(List* arr, int first, int last) {
	if (first < last) {
		int left = first,
			right = last,
			middle = arr[(left + right) / 2].time;
		do {
			while (arr[left].time < middle) left++; 
			while (arr[right].time > middle) right--; 
			if (left <= right) {
				List tmp = arr[left];
				arr[left] = arr[right];
				arr[right] = tmp;
				left++;
				right--;
			}
		} while (left <= right);
		qs(arr, first, right);
		qs(arr, left, last);
		
	}
}
int Max(int a, int b, int c) {
	return a > b ? a > c ? a : c : c > b ? c : b;
}
int Max2(int a, int b) {
	return a > b ? a : b;
}
int main() {
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	int n, K, T;
	fscanf(f1, "%d%d%d", &n, &K, &T);
	for (int i = 0; i < n; i++) {
		fscanf(f1, "%d ", &A[i].time);
		
	}
	for (int i = 0; i < n; i++) {
		fscanf(f1, "%d ", &A[i].cost);
	}
	for (int i = 0; i < n; i++) {
		fscanf(f1, "%d ", &A[i].width);
		if (A[i].width > A[i].time) {
			A[i].cost = 0;
		}
	}
	qs(A, 0, n - 1);
	/*for (int i = 0; i < n; i++) {
		fprintf(f2, "%d ", A[i].time);
	}
	fprintf(f2, "\n");
	for (int i = 0; i < n; i++) {
		fprintf(f2, "%d ", A[i].cost);
	}
	fprintf(f2, "\n");
	for (int i = 0; i < n; i++) {
		fprintf(f2, "%d ", A[i].width);
	}
	fprintf(f2, "\n"); */
	//shell_sort(n);
	int f = 0, g = 0, flag = 0;
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (flag == 0 && A[i].time != 0) {
			g = i;
			flag = 1;
		}
		if (A[i].time > T) {
			n = i + 1;
			break;
		}
	}
	for (int i = 1; i <= A[n - 1].time; i++) {
		flag = 0;
		if (A[g].time == i) {
			flag = 1;
		}
		for (int j = 0; j <= K; j++) {
			if (flag == 1 && j == A[g].width) {
				f = A[g].cost;
			}
			else
				f = 0;
			if (H[i][j] == 0)
				H[i][j] = Max(H[i - 1][j - 1], H[i - 1][j], H[i - 1][j + 1]) + f;
			else
				H[i][j] += f;
			if (H[i][j] > max)
				max = H[i][j];
		}
		if (flag == 1) {
			if (A[g + 1].time == i)
				i -= 1;
			g++;
		}
	}
	fprintf(f2, "%d\n", max);
	fclose(f1);
	fclose(f2);
	return 0;
}