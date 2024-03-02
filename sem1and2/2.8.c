#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <math.h>
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, it = 1;
	scanf("%d", &n);
	double a, a2;
	float d, dmin = 1;
	for (int i = 1; i <= n; i++) {
		scanf("%lf", &a);
		a = fabs(a);
		a2 = (int) a;
		if (a - a2 >= 0.5)
			d = a2 + 1 - a;
		else
			d = a - a2;
		if (d < dmin) {
			dmin = d;
			it = i;
		}
	}
	//printf("%lf\n", dmin);
	printf("%d", it);
	return 0;
}