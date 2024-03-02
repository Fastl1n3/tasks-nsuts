#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <math.h>
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d\n", &n);
	int min = 10000, max = -10000, a, imax, imin;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a);
		if (a > max) {
			max = a;
			imax = i;
		}
		if (a < min) {
			min = a;
			imin = i;
		}
	}
	printf("%d %d %d %d", min, imin, max, imax);
	return 0;
}

