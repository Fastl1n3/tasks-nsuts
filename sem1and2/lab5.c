#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#define N 1000001
char n[N];
int A[N];
int in_10(int p, char *n) {
	int new_v = 0, stepen = 1;
	int len = strlen(n);
	for (int i = len - 1; i >= 0; i--) {
		if (n[i] - '0' < 10)
			new_v += (n[i] - '0') * stepen;
		else
			new_v += (n[i] - 'a' + 10) * stepen;
		stepen *= p;
	}
	return new_v;
}
void in_q(int q, int n) {
	int i = 0;
	while (n > 0) {
		A[i] = n % q;
		n = n / q;
		i++;
	}
	for (int j = i - 1; j >= 0; j--) {
		if (A[j] < 10)
			printf("%d", A[j]);
		else
			printf("%c", 'a' + A[j] - 10);
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int p, q, value;
	scanf("%d%d", &p, &q);
	scanf("%s", n);
	value = in_10(p, n);
	in_q(q, value);
	return 0;
}