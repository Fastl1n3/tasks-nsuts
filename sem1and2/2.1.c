#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, s;
	scanf("%d", &n);
	s = 0;
	for (int i = 1; i <= n; i++) 
	{
		s += i;
	}
	printf("%d\n", s);
	return 0;
}

