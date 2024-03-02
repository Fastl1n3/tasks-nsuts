#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#define N 100
char A[N][N] = { 0 };
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m, m0, step = 0, step_loop = 0;
	scanf("%d%d%d", &n, &m, &m0);
	for (int i = 0; i < n; i++) {
		scanf("%s", A[i]);
	}
	int i = 0, j = m0 - 1, count = 0;
	char place;
	int X[N][N] = { 0 };
	while (i >= 0 && i < n && j >= 0 && j < m) {
		place = A[i][j];
		if (X[i][j] == 1) 
			step_loop++;
		if (X[i][j] == 2)
			break;
		X[i][j]++;
		if (place == 'N')
			i--;
		if (place == 'S')
			i++;
		if (place == 'W')
			j--;
		if (place == 'E')
			j++;
		step++;
	}
	if (step_loop == 0)
		printf("%d step(s) to exit", step);
	else
		printf("%d step(s) before a loop of %d step(s)", step - 2 * step_loop, step_loop);
	return 0;
}