#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
char arr[13][13] = { 0 };
int check(int m, int n, int k, int i) {
	if (arr[i][k] != '?')
		return 0;
	for (int g = 0; g < i; g++) {
		if (arr[g][k] == 'X')
			return 0;
		for (int j = 0; j < n; j++) {
			if (abs(i - g) == abs(k - j) && arr[g][j] == 'X')
				return 0;
		}
	}
	return 1;
}
int flag = 0;
void Try(FILE* f, int i, int m, int n) {	
	for (int k = 0; k < n; k++) {		
		if (check(m, n, k, i)) {	
			arr[i][k] = 'X';
			if (i < m - 1) {
				Try(f, i + 1, m, n);
			}
			else if (flag == 0) {
				fprintf(f, "YES\n");
				for (int g = 0; g < m; g++) {
					for (int j = 0; j < n; j++) {
						if (arr[g][j] != 'X')
							fprintf(f, ".");
						else
							fprintf(f, "X");
					}
					fprintf(f, "\n");
				}
				flag = 1;
			}
			arr[i][k] = '?';
		}
	}
}
int main() {
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	int n, m;
	fscanf(f1, "%d%d", &m, &n);
	for (int i = 0; i < m; i++) {
		fscanf(f1, "%s", arr[i]);
	}
	Try(f2, 0, m, n);
	if (flag == 0)
		fprintf(f2, "NO");
	fclose(f1);
	fclose(f2);
	return 0;
}