#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define N 1001
long long A[N][N] = { 0 };
long long dec(long long n, long long k) {
	if (n >= 0 && k >= 0 && A[n][k] > 0) 
		return A[n][k] % 1000000007;
	if (n < 0) 
		return 0;
	if (n <= 1 || k == 1) 
		return 1;
	A[n][k] = dec(n, k - 1) % 1000000007 + dec(n - k, k) % 1000000007;
	return A[n][k];

}
int main() {
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	long long n;
	fscanf(f1, "%lld", &n);
	fprintf(f2, "%lld", dec(n, n));
	fclose(f1);
	fclose(f2);
	return 0;
}