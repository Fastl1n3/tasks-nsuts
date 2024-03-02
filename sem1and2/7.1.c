#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <math.h>
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, a_int, s = 0, j = 0;
	scanf("%d\n", &n);
	char a;
	for (int i = 0; i < n; i++) {
		scanf("%c", &a);
		a_int = a - '0';
		s += a_int * pow(2, j);
		j++;
		if ((i + 1) % 8 == 0 || i == n - 1) {
			printf("%d ", s);
			s = 0;
			j = 0;
		}
	}
	return 0;
}
