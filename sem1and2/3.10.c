#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int d1, m1, y1, d2, m2, y2;
	scanf("%d %d %d %d %d %d", &d1, &m1, &y1, &d2, &m2, &y2);
	int c;
	if (y2 < y1) {
		c = y2;
		y2 = y1;
		y1 = c;
		c = m2;
		m2 = m1;
		m1 = c;
		c = d2;
		d2 = d1;
		d1 = c;
	}
	else {
		if (m2 < m1 && y2 == y1) {
			c = m2;
			m2 = m1;
			m1 = c;
			c = d2;
			d2 = d1;
			d1 = c;
		}
		else if (d2 < d1 && m2 == m1) {
			c = d2;
			d2 = d1;
			d1 = c;
		}
	}
	int M[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int vis1, vis2;
	if (y1 % 4 == 0 && y1 % 100 != 0 || y1 % 400 == 0)
		vis1 = 1;
	else
		vis1 = 0;
	if (y2 % 4 == 0 && y2 % 100 != 0 || y2 % 400 == 0)
		vis2 = 1;
	else
		vis2 = 0;
	if ((d1 > 28 && m1 == 2 && vis1 == 0) || (d2 > 28 && m2 == 2 && vis2 == 0) || (d1 > 29 && m1 == 2 && vis1 == 1) || (d2 > 29 && m2 == 2 && vis2 == 1) || m1 > 12 || m1 < 1 || m2 < 1 || m2 > 12 || d1 > M[m1 - 1] && m1 != 2 || d2 > M[m2 - 1] && m2 != 2 || d1 < 1 || d2 < 1 || y1 < 1 || y2 < 1) {
		printf("ERROR");
		return 0;
	}
	
	int m = 0;
	for (int j = 0; j < m1 - 1; j++) {
		if (j == 1 && vis1 == 1)
			m += M[j] + 1;
		else
			m += M[j];
		}
	int all_d1, all_d2 = 0;
	all_d1 = d1 + m;
	
	m = 0;
	for (int j = 0; j < m2 - 1; j++) {
		if (j == 1 && vis2 == 1)
			m += M[j] + 1;
		else
			m += M[j];
	}
	for (int i = y1; i < y2; i++) {
		if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
			all_d2 += 366;
		else
			all_d2 += 365;
	}
	all_d2 += d2 + m;
	printf("%d", all_d2 - all_d1);
	return 0;
}