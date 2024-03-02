#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	char color[26], s[26], a = 'a', c1, c2;
	int lens;
	scanf("%s", &color);
	scanf("%s", &s);
	lens = strlen(s);
	if (color[0] == 'p') {
		c1 = 'B';
		c2 = 'R';
	}
	else if (color[0] == 'g') {
		c1 = 'B';
		c2 = 'Y';
	}
	else {
		c1 = 'R';
		c2 = 'Y';
	}
	for (int i = 0; i < lens; i++) {
		if (s[i] == c1 || s[i] == c2)
			printf("%d ", i + 1);
	}
	return 0;
}