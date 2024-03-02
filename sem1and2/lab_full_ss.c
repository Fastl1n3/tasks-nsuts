#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 101
char n[N];
int A[N];
int proverka(char* n, int p, int len) {
	int k = 0;
	for (int i = 0; i < len; i++) {
		if (n[i] == '.') {
			k++;
			if (k == 2)
				return -1;
		}
		else if (n[i] - '0' < 10 && (n[i] - '0') >= p)
			return -1;
		else if ((n[i] - 'a' + 10) >= p)
			return -1;
	}
	return 0;
}
int in_10_int(int b1, char* n, int len) {
	int new_v = 0, stepen = 1;
	for (int i = len - 1; i >= 0; i--) {
		if (n[i] - '0' < 10)
			new_v += (n[i] - '0') * stepen;
		else
			new_v += (n[i] - 'a' + 10) * stepen;
		stepen *= b1;
	}
	return new_v;
}
void in_b2_int(int b2, int n) {
	int i = 0;
	while (n > 0) {
		A[i] = n % b2;
		n = n / b2;
		i++;
	}
	for (int j = i - 1; j >= 0; j--) {
		if (A[j] < 10)
			printf("%d", A[j]);
		else
			printf("%c", 'a' + A[j] - 10);
	}
}
double in_10_drob(double b1, char* n, int len) {
	double new_v = 0, stepen = 1 / b1;
	for (int i = 0; i < len; i++) {
		if (n[i] - '0' < 10)
			new_v += (n[i] - '0') * stepen;
		else
			new_v += (n[i] - 'a' + 10) * stepen;
		stepen /= b1;
	}
	return new_v;
}
void in_b2_drob(double n, int b2, int k) {
	printf("%c", '.');
	char res[N] = {0};
	int a;
	double p;
	for (int i = 0; i < k; i++) {
		p = n * b2;
		a = p;
		if (p < 10) 
			res[i] = a + '0';
		else
			res[i] = a % 10 + 'a';
		n = p - a;
		if (n < 0.000000001)
			break;
		if ((1 - n) < 0.000000001) {
			res[i]++;
			break;
		}
		//n += 0.000000001;
		//printf("%0.20lf\n", n);
		//	printf("%0.20lf!\n", n);
		//if (n == 0)
			//break;	
	}
	int j = 0;
	for (j = k - 1; j >= 0; j--) {
		if (res[j] != 0 && res[j] != '0')
			break;
	}
	for (int i = 0; i <= j; i++)
		printf("%c", res[i]);
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	double b1;
	int b2, kolvo_z, len;
	char n_int[N] = {0}, n_drob[N] = { 0 };
	scanf("%lf%d%d", &b1, &b2, &kolvo_z);
	scanf("%s", n);
	len = strlen(n);
	if (proverka(n, b1, len) == -1) {
		printf("NO");
		return 0;
	}
	int i = 0, j = 0;
	while (n[i] != '.' && i < len) {
		n_int[i] = n[i];
		i++;
	}
	int len_int = i;
	if (len_int != len) {
		for (i += 1; i < len; i++) {
			n_drob[j] = n[i];
			j++;
		}
	}
	int len_drob = j;
	if (n_int[0] != '0') {
		int new10_int = in_10_int(b1, n_int, len_int);
		in_b2_int(b2, new10_int);
	}
	else
		printf("0");
	if (len_int != len) {
		double new10_drob = in_10_drob(b1, n_drob, len_drob);
		in_b2_drob(new10_drob, b2, kolvo_z);
	}
	return 0;
}