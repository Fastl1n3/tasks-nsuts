#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d\n", &n);
	int s = 0;
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		if (a % 2 == 0)
			s += a;
	}
	printf("%d\n", s);
	return 0;
}

