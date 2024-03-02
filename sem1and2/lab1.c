#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#define N 100001
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, b;
	scanf("%d", &b);
	scanf("%d", &n);
	int i = 0;
	int A[N];
	if (n == 0) {
		printf("%d", 0);
		return 0;
	}
	while (n > 0) {
		A[i] = n % b;
		n = n / b;
		i++;
	}
	for (int j = i - 1; j >= 0; j--) {
		if (A[j] < 10)
			printf("%d", A[j]);
		else
			printf("%c", 'a' + A[j] - 10);
	}
	return 0;
}