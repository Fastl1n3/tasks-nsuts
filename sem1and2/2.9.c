#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	double y, x, e, el, c;
	scanf("%lf %lf", &x, &e);
	el = x;
	c = x;
	y = x;
	int i = 1;
	while (c >= e || -c >= e) {
		el = -el * x * x;
		c = el / (2 * i + 1);
		y += c;
		i++;
	}
	printf("%0.5lf", y);
	return 0;
}