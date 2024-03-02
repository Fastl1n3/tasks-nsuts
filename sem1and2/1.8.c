#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <math.h>
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int a, b, c;
	double D, x1, x2;
	scanf("%d%d%d", &a, &b, &c);
	if (a != 0) {
		D = b * b - 4 * a * c;
		//printf("%0.5lf\n", D);
		if (D < 0) printf("NO");
		if (D == 0) {
			printf("%d\n", 1);
			if (b == 0) printf("%0.5lf", 0);
			else printf("%0.5lf", -(double)b / (2 * a));
		}
		if (D > 0) {
			printf("%d\n", 2);
			x1 = (-b - sqrt(D)) / (2 * a);
			x2 = (-b + sqrt(D)) / (2 * a);
			if (x2 > x1) printf("%0.5lf %0.5lf", x1, x2);
			else printf("%0.5lf %0.5lf", x2, x1);
		}
	}
	else {
		if (b != 0) {
			printf("%d\n", 1);
			printf("%0.5lf", - (double) c / b);
		}
		else {
			if (c == 0) printf("MANY");
			else printf("ERROR");
		}
		
	}
	return 0;
}