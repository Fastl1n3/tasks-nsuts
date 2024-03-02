#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <math.h>
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		int f = 0;
		if (i > 2) {
			for (int j = 2; j < sqrt(i) + 1; j++) {
				if (i % j == 0) {
					f = 1;
					break;
				}
			}
		}
		if (f == 0)
			printf("%d ", i);
	}
	return 0;
}