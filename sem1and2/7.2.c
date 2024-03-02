#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <math.h>
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, N,  k = 0, kmax = 0, a;
	scanf("%d", &n);
	N = n;
	if (n < 0) {
		N = 2147483648 + n;
	}
	while (N > 0) {
		a = N % 2;
		if (a == 1) {
			k += 1;
			if (k > kmax)
				kmax = k;
		}
		else
			k = 0;
		N >>= 1;
	}
	if (n < 0)
		kmax++;
	printf("%d", kmax);
	return 0;
}