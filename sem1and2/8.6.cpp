#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#define N 251
int key[N][N] = { 0 };
int new_key[N][N] = { 0 };
char X[N][N] = { 0 };
char shifr[63000] = { 0 };
int check[251][251];
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < 2 * n; i++) {
		for (int j = 0; j < 2 * n; j++) {
			scanf("%d", &key[i][j]);
		}
	}
	for (int i = 0; i < 2 * n; i++) {
		for (int j = 0; j < 2 * n; j++) {
			scanf("%c", &X[i][j]);
			while (X[i][j] == '\n' || X[i][j] == ' ')
				scanf("%c", &X[i][j]);
		}
	}
	int g = 0;
	
	for (int p = 0; p < 4; p++) {
		for (int i = 0; i < 2 * n; i++) {
			for (int j = 0; j < 2 * n; j++) {
				if (key[i][j] == 1) {
					shifr[g] = X[i][j];
					g++;
					check[i][j]++;
				}
				if (check[i][j] == 2) {
					printf("No");
					return 0;
				}
			}
		}
		for (int i = 0; i < n * 2; i++) {
			for (int j = n * 2 - 1; j >= 0; j--) {
				new_key[j][i] = key[i][j];
			}
		}
		for (int i = 0; i < n * 2; i++) {
			for (int j = n * 2 - 1, t = 0; j >= 0; j--, t++) {
			key[i][t] = new_key[i][j];
			}
		}
//		for (int i = 0; i < n * 2; i++) {
//			for (int j = 0; j < n * 2; j++) {
//				printf("%d ", key[i][j]);
//			}
//			printf("\n");
//		}
//		printf("\n"); 
	}
	for (int i = 0; i < g; i++) {
		printf("%c", shifr[i]);
	}
	if (g == 0)
		printf("\n");
	return 0;
}