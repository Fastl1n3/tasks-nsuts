#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#define N 100000
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	char a, last_a;
	scanf("%c", &a);
	int s = 0;
	while (a != '.') {
		s += a - '0';
		scanf("%c", &a);
		if (a != '.')
			last_a = a;
	}
	if (s % 3 == 0 && (last_a == '5' || last_a == '0'))
		printf("YES");
	else
		printf("NO");
	return 0;
}