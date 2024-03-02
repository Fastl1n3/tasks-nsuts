#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <math.h>
#define N 1000000
double A[N];
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	double x;
	scanf("%d %lf", &n, &x);
	for (int i = 0; i < n; i++) {
		scanf("%lf", &A[i]);
	}
	int a = -2, center_i, first_i, last_i, min_i;
	double center, d, dmin = 100000000000000;
	first_i = 0;
	last_i = n - 1;
	while (first_i <= last_i) {
		if ((first_i + last_i) % 2 == 0)
			center_i = (first_i + last_i) / 2;
		else
			center_i = (first_i + last_i) / 2 + 1;
		center = A[center_i];
		d = fabs(x - center);
		if (d <= dmin) {
			if (d < dmin) {
				dmin = d;
				min_i = center_i;
			}
			else if (center_i < min_i) {
				dmin = d;
				min_i = center_i;
			}
		}
		if (x > center) {
			first_i = center_i + 1;
		}
		else
			last_i = center_i - 1;
	}
	printf("%d", min_i);
	return 0;
}