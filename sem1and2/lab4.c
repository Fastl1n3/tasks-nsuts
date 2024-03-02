#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 51
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int len;
	double new_v = 0, b, stepen;
	scanf("%lf", &b);
	stepen = 1 / b;
	char n[N];
	scanf("%s", n);
	len = strlen(n);
	for (int i = 2; i < len; i++) {
		if (n[i] - '0' < 10)
			new_v += (n[i] - '0') * stepen;
		else
			new_v += (n[i] - 'a' + 10) * stepen;
		stepen /= b;
	}
	printf("%0.5lf", new_v);
	return 0;
}