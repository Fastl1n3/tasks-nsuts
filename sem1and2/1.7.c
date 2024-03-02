#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <math.h>
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int h, m, s, k;
	scanf("%d %d %d %d", &h, &m, &s, &k);
	m += k / 60;
	if ((s + k % 60) > 59) {
		m += 1;
		s = (s + k % 60) % 60;
	}
	else 
		s += k % 60;
	if (m > 59) {
		h += m / 60;
		m = m % 60;
	}
	if (h > 23) {
		h = h % 24;
	}
	printf("%d %d %d", h, m, s);
	return 0;
}