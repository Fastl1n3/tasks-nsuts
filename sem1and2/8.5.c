#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#define N 1000
char A[N][N] = { 0 };
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	char c, ignor[21][21] = { 0 }, s[N];
	scanf("%c", &c);
	int i = 0, j = 0;
	while (c != '\n') {
		ignor[i][j] = c;
		j++;
		scanf("%c", &c);
		if (c == ' ') {
			scanf("%c", &c);
			i++;
			j = 0;
		}
	}
	int len_ignor = i + 1;
	i = 0;
	int len_word;
	while (scanf("%s", A[i]) == 1) {
		if (A[i][0] >= 65 && A[i][0] <= 90)
			A[i][0] += 32;
		len_word = strlen(A[i]);
		if (A[i][len_word - 1] < 97 || A[i][len_word - 1] > 122)
			A[i][len_word - 1] = 0;
		i++;
	}
	A[i-1][len_word - 3] = 0;
	int max_count = 0;
	char max_word[N] = { 0 };
	for (int j = 0; j < i; j++) {
		int f = 0;
		for (int g = 0; g < len_ignor; g++) {
			if (strcmp(A[j], ignor[g]) == 0) {
				f = 1;
				break;
			}
		}
		if (f == 0) {
			int count = 0;
			for (int g = j + 1; g < i; g++) {
				if (strcmp(A[j],A[g]) == 0)
					count++;
			}
			if (count > max_count) {
				max_count = count;
				strcpy(max_word, A[j]);
			}
		}
	}
	int len_maxword = strlen(max_word);
	for (int i = 0; i < len_maxword; i++) {
		max_word[i] -= 32;
	}
	printf("%s", max_word);
	return 0;
}