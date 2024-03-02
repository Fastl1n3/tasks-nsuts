#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#define N 1000001
char n[N];
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int b, new_v = 0, stepen = 1;
	scanf("%d", &b);
	scanf("%s", n);
	int len = strlen(n);
	for (int i = len - 1; i >= 0; i--) {
		if (n[i] - '0' < 10)
			new_v += (n[i] - '0') * stepen;
		else
			new_v += (n[i] - 'a' + 10) * stepen;
		stepen *= b;
	}
	printf("%d", new_v);
	return 0;
}