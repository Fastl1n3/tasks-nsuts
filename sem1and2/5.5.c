#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	char s1, s2;
	int k = 0;
	scanf("%c", &s1);
	scanf("%c", &s2);
	while (s1 != '\n') {
		if (s1 != '.' && (s2 == '.' || s2 == '\n'))
			k++;
		s1 = s2;
		scanf("%c", &s2);
	}
	printf("%d", k);
	return 0;
}
