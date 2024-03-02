#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#define N 1000000
typedef unsigned int bitword;
bitword A[N];
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int num = 2;
	bitword b = 1;
	b <<= 31;
	for (int i = 0; i < num; i++) {
		
		A[i] = b;
	}
	printf("%u", ~1);
	return 0;
}