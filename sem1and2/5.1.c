#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	char a1, a2;
	scanf("%c", &a1);
	scanf("%c", &a2);
	if (a1 == 'M')
		printf("%d", 1);
	if (a1 == 'T') {
		if (a2 == 'u')
			printf("%d", 2);
		else
			printf("%d", 4);
	}
	if (a1 == 'W')
		printf("%d", 3);
	if (a1 == 'F')
		printf("%d", 5);
	if (a1 == 'S') {
		if (a2 == 'a')
			printf("%d", 6);
		else
			printf("%d", 7);
	}
	return 0;
}