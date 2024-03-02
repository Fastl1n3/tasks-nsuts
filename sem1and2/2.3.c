#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <math.h>
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	int f = 0;
	if (n > 2) {
		for (int i = 2; i < sqrt(n) + 1; i++) {
			if (n % i == 0) {
				f = 1;
				break;
			}
		}
	}
	if (f == 0 && n != 1)
		printf("YES");
	else
		printf("NO");
	return 0;
}
	