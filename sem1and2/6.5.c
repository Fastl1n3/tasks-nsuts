#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#define N 1000
void reverse(char *start, int len) {
	int b;
	for (int i = 0; i < len / 2; i++) {
		b = start[i];
		start[i] = start[len - i - 1];
		start[len - i - 1] = b;
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	char s[N];
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", s);
		reverse(s, strlen(s));
		printf("%s\n", s);
	}
	return 0;
}