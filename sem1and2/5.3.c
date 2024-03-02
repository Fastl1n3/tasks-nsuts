#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#define N 100000
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	char A[N];
	int n = 0;
	scanf("%c", &A[n]);
	while (A[n] != '.') {
		n++;
		scanf("%c", &A[n]);
	}
	if (A[n - 1] == 'e') {
		A[n] = 'r';
		n++;
	}
	else if (A[n - 2] == 'e' && A[n - 1] == 'r') {
		A[n - 1] = 's';
		A[n] = 't';
		n++;
	}
	else {
		A[n] = 'e';
		A[n + 1] = 'r';
		n += 2;
	}
	for (int i = 0; i < n; i++) {
		printf("%c", A[i]);
	}
	return 0;
}
	