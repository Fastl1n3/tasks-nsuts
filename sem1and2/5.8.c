#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	char c1, c2;
	int f = 0;
	scanf("%c", &c1);
	while (scanf("%c", &c2) == 1) {
		if (c1 == '/' && c2 == '*') {
			scanf("%c%c", &c1, &c2);
			while (c1 != '*' || c2 != '/') {
				if (c1 == '\n') {
					printf("\n");
				}
				c1 = c2;
				if (scanf("%c", &c2) != 1) {
					f = 1;
					break;
				}
			}
			scanf("%c", &c1);
			if (scanf("%c", &c2) != 1) {
				break;
			}
		}
		if (c1 == '/' && c2 == '/') {
			while (c1 != '\n') {
				scanf("%c", &c1);
			}
			scanf("%c", &c2);
		}
		printf("%c", c1);
		c1 = c2;
	}
	if (c2 != '/' && f == 0)
		printf("%c", c2);
	return 0;
}