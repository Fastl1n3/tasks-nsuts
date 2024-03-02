#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#define N 301
int X[N] = { 0 };
int Y[N] = { 0 };
int function(int x) {
	if (X[x] == 0)
		X[x]++;
	else
		return 0;
	return 1;
}
int opred_fun(int n) {
	for (int i = 1; i <= n; i++) {
		if (X[i] == 0)
			return 0;
	}
	return 1;
}
int injection(int y) {
	if (Y[y] == 0)
		Y[y]++;
	else
		return 0;
	return 1;
}
int surjection(int n) {
	for (int i = 1; i <= n; i++) {
		if (Y[i] == 0)
			return 0;
	}
	return 1;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m, x, y, f, k_inj = 0;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &x, &y);
		f = function(x);
		if (f == 0)
			break;
		k_inj += injection(y);
	}
	printf("%d ", f);
	if (opred_fun(n) == 1)
		printf("%d ", 2);
	if (k_inj == m)
		printf("%d ", 3);
	int sur = surjection(n);
	if (sur == 1) {
		printf("%d ", 4);
		if (k_inj == m)
			printf("%d ", 5);
	}
	return 0;
}