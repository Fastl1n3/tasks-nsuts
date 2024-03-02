#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <math.h>
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, a;
	a = 0;
	scanf("%d", &n);
	while (n > 0) {
		a *= 10;
		a += n % 10;
		n = n / 10;
	}
	printf("%d", a);
	return 0;
}