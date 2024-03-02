#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	char c1, c2;
	while (scanf("%c", &c1) == 1) {
		scanf("%c", &c2);
		if (c1 == "*" && c2 == "/") {
			scanf("%c", &c1);
			scanf("%c", &c2);
			printf("%c%c", c1, c2);
		}
		else
			printf("%c%c", c1, c2);
	}
	return 0;
}