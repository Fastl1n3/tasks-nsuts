#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	char c, c2;
	int s = 0, sm = 0;
	scanf("%c", &c);
	c2 = 'a';
	while (c != '.' && c2 != '.') {
		while (c >= '0' && c <= '9') {
			s += c - '0';
			scanf("%c", &c2);
			if (c2 >= '0' && c2 <= '9')
				s = s * 10;
			c = c2;
		}
		scanf("%c", &c);
		sm += s;
		s = 0;
	}
	printf("%d", sm);
	return 0;
}