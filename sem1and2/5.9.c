#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <math.h>
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	long long k = 0, n;
	long long a = 1, kolvo_c, b;
	scanf("%lld", &n);
	long long cbrt_n = cbrt(n);
	long long sqrt_n = sqrt(n);
	for (a; a <= cbrt_n; a++) {
		b = a;
		for (b; b <= sqrt_n; b++) {
			kolvo_c = n / (a * b);
			if (kolvo_c - b + 1 > 0)
				k += kolvo_c - b + 1;
		}			
	}
	printf("%lld", k);
	return 0;
}