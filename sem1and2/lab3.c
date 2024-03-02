#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 100001
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int k, a, b;
	double n, p;
	scanf("%d%d", &b, &k);
	scanf("%lf", &n);
	printf("0.");
	for (int i = 0; i < k; i++) {
		p = n * b;
		if (p < 10) {
			a = p;
			n = p - a;
			printf("%d", a);
		}
		else {
			a = p + 'a' - 10;
			printf("%c", a);
			n = p - (int)p;
		}
		if (n == 0 && b != 16)
			break;
	}
	return 0;
}