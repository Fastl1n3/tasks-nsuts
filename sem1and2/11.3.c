#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct str {
	int lower_cnt;
	int upper_cnt;
	int digits_cnt;
} Str;
int calcLetters(char* iStr, int* oLowerCnt, int* oUpperCnt, int* oDigitsCnt) {
	int len = strlen(iStr) - 1;
	for (int i = 0; i < len; i++) {
		if (iStr[i] >= 97 && iStr[i] <= 122)
			(*oLowerCnt)++;
		if (iStr[i] >= 65 && iStr[i] <= 90)
			(*oUpperCnt)++;
		if (iStr[i] >= 48 && iStr[i] <= 57)
			(*oDigitsCnt)++;
	}
	return len;
}
int main() {
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	char A[102] = { 0 };
	int i = 1, chars;
	while (fgets(A, sizeof(A), f1) != NULL) {
		Str a;
		a.digits_cnt = 0;
		a.lower_cnt = 0;
		a.upper_cnt = 0;
		int x = 0, y = 0, z = 0;
		chars = calcLetters(A, &a.lower_cnt, &a.upper_cnt, &a.digits_cnt);
		fprintf(f2, "Line %d has %d chars: %d are letters (%d lower, %d upper), %d are digits.\n", i, chars, a.upper_cnt + a.lower_cnt, a.lower_cnt, a.upper_cnt, a.digits_cnt);
		i++;
	}
	fclose(f1);
	fclose(f2);
	return 0;
}