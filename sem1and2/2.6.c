#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <math.h>
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	int kpol = 0, kotr = 0, k0 = 0;
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		if (a >= 0) {
			if (a == 0)
				k0 += 1;
			else
				kpol += 1;
		}
		else
			kotr += 1;
	}
	double potr = (double) kotr / n;
	double p0 = (double) k0 / n;
	double ppol = (double) kpol / n;
	printf("%0.5lf %0.5lf %0.5lf", potr, p0, ppol);
	return 0;
}