#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	char s[26], a = 'a';
	int len, player = 1, f;
	while (scanf("%s", &s) == 1) {
		len = strlen(s);
		for (int i = 0; i < len; i++) {
			if (s[i] == a) {
				a += 1;
				f = 0;
				break;
			}
			else
				f = 1;
		}
		if (f == 1) {
			if (player % 2 == 1)
				printf("PLAYER 2");
			else
				printf("PLAYER 1");
			break;
		}
		player++;
	}
	if (f == 0)
		printf("NO WINNER");
	return 0;
}