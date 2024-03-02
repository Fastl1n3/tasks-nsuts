#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
void ins_sort(char A[], int n) {
	for (int i = 1; i < n; i++) {
		int x = A[i];
		int j = i - 1;
		while (j >= 0 && A[j] > x) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = x;
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	char s1[26], s2[26], s3[26] = {0}, c1, c2;
	int len1, len2, g = 0;
	scanf("%s", s1);
	scanf("%s", s2);
	len1 = strlen(s1);
	len2 = strlen(s2);
	for (int i = 0; i < len1; i++) {
		int f = 0;
		for (int j = 0; j < len2; j++) {
			if (s1[i] == s2[j]) {
				f = 1;
				break;
			}
		}
		if (f == 0) {
			s3[g] = s1[i];
			g++;
		}
	}
	if (s3[0] == 0) {
		printf("Empty Set");
		return 0;
	}
	ins_sort(s3, strlen(s3));
	printf("%s", s3);
	return 0;
}