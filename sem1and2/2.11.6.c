#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 50
typedef struct list {
	int x1;
	int y1;
	int x2;
	int y2;
}Spichka;
Spichka S[N] = { 0 };
int A[N][N] = { 0 };
int Max(int a, int b) {
	return a > b ? a : b;
}
int Min(int a, int b) {
	return a < b ? a : b;
}
int area(Spichka s, int x3, int y3) {
	return (s.x2 - s.x1) * (y3 - s.y1) - (s.y2 - s.y1) * (x3 - s.x1);
}
int check_ob(int a, int b, int c, int d) {
	if (a > b) {
		int m = a;
		a = b;
		b = m;
	}
	if (c > d) { 
		int m = c;
		c = d;
		d = m;
	}
	return Max(a, c) <= Min(b, d) ? 1 : 0;
}
int intersect(Spichka s1, Spichka s2) {
	return check_ob(s1.x1, s1.x2, s2.x1, s2.x2)
		&& check_ob(s1.y1, s1.y2, s2.y1, s2.y2)
		&& area(s1, s2.x1, s2.y1) * area(s1, s2.x2, s2.y2) <= 0
		&& area(s2, s1.x1, s1.y1) * area(s2, s1.x2, s1.y2) <= 0;
}
void Floyd(int n) {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (A[i][k] == 1 && A[k][j] == 1)
					A[i][j] = 1;
			}
		}
	}
}
int main() {
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	int n;
	char t = 1;
	while (t != 0) {
		fscanf(f1, "%d", &n);
		if (n == 0)
			break;
		for (int i = 1; i <= n; i++) {
			fscanf(f1, "%d%d%d%d", &S[i].x1, &S[i].y1, &S[i].x2, &S[i].y2);
		}
		for (int i = 1; i <= n; i++) {
			A[i][i] = 1;
			for (int j = i + 1; j <= n; j++) {
				A[i][j] = intersect(S[i], S[j]);
				A[j][i] = A[i][j];
			}
		}
		Floyd(n);
		/*for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				fprintf(f2, "%d ", A[i][j]);
			}
			fprintf(f2, "\n");
		}*/
		int a = 1, b = 1;
		while (a != 0 && b != 0) {
			fscanf(f1, "%d%d", &a, &b);
			if (a == 0 && b == 0)
				break;
			if (A[a][b] == 1)
				fprintf(f2, "CONNECTED\n");
			else
				fprintf(f2, "NOT CONNECTED\n");
		}
	}
	fclose(f1);
	fclose(f2);
	return 0;
}