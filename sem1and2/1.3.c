#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int a, b, c, d;
	scanf("%d%d%d", &a, &b, &c);
	if (a < b) {
		if (a < c) d = a;
		else d = c;
	}
	else {
		if (b < c) d = b;
		else d = c;
	}
	printf("%d", d);
	return 0;
}