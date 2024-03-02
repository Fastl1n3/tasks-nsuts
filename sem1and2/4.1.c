#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
int gcd(int a, int b) {
	if (a * b == 0)
		return a + b;
	return gcd(b, a % b);
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int a, b;
	scanf("%d%d", &a, &b);
	int d = gcd(a, b);
	printf("%d", d);
	return 0;
}