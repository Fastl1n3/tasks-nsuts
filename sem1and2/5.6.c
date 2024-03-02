#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#define N 27
void next_permut(char A[], int n) {
	int m, c, index = -1;
	for (int i = n - 1; i >= 0; i--) {
		if (A[i + 1] >= A[n - 1] && A[i + 1] > A[i]) {
			m = A[i];
			index = i;
			break;
		}
	}
	if (index == -1) {
		for (int i = 0; i < n / 2; i++) {
			c = A[i];
			A[i] = A[n - i - 1];
			A[n - i - 1] = c;
		}
		return 1;
	}
	for (int j = n - 1; j >= index + 1; j--) {
		if (A[j] > A[index]) {
			c = A[index];
			A[index] = A[j];
			A[j] = c;
			break;
		}
	}
	int g = 0;
	for (int j = index + 1; j < (n + index + 1) / 2; j++) {
		c = A[j];
		A[j] = A[n - g - 1];
		A[n - g - 1] = c;
		g++;
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, j = 0;
	char A[N], s;
	scanf("%d", &n);
	scanf("%c", &s);
	for (int i = 0; i < n * 2; i++) {
		scanf("%c", &s);
		if (s != ' ' && s != '\n') {
			A[j] = s;
			j++;
		}
	}
	next_permut(A, n);
	for (int i = 0; i < n; i++) {
		printf("%c ", A[i]);
	}
	return 0;
}