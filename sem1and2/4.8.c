#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
long long gcd(long long a, long long b) {
	if (a * b == 0)
		return a + b;
	return gcd(b, a % b);
}
long long lcm(long long a, long long b) { 
	long long nod;
	nod = gcd(a, b);
	return (a * b) / nod;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, a, b;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a, &b);
		printf("%lld\n", lcm(a, b));
	}
	return 0;
}