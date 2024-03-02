#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, a, st;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		st = 1;
		while (a % 2 == 0) {
			a >>= 1;
			st <<= 1;
		}
		printf("%d\n", st);
	}
	return 0;
}