#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#define N 700000
typedef unsigned int bitword;
bitword A[N];
void bitsetZero(bitword* arr, int num) {
	int n1 = num / 32, n2 = num % 32;
	for (int i = 0; i < n1; i++) {
		arr[i] = 0;
	}
	if (n2 != 0)
		arr[n1] = 0;
}
int bitsetGet(const bitword* arr, int idx) {
	unsigned int n1 = 0, n2 = 0;
	n1 = idx / 32;
	n2 = (arr[n1] >> (idx % 32)) & 1;
	return n2;
}
void bitsetSet(bitword* arr, int idx, int newval) {
	int n1;
	n1 = idx / 32;
	if (newval == 1) {
		if ((arr[n1] & (1 << (idx % 32))) == 0)
			arr[n1] += newval << (idx % 32);
	}
	else if ((arr[n1] & (1 << (idx % 32))) != 0)
		arr[n1] -= 1 << (idx % 32);
}
void bitsetSetSeg(bitword* arr, int left, int right, int newval) {
	int n1;
	n1 = left / 32;
	for (int i = left; i < right; i++) {
		if (i % 32 == 0 && i != left)
			n1++;
		if (i % 32 == 0 && right - i >= 32) {
			arr[n1] = newval * 4294967295;	
			i += 31;
		}
		else {
			if (newval == 1) {
				if ((arr[n1] & (1 << (i % 32))) == 0)
					arr[n1] += newval << (i % 32);
			}
			else if ((arr[n1] & (1 << (i % 32))) != 0)
				arr[n1] -= 1 << (i % 32);
		}
	}
}
bitword bitsetCount(const bitword* arr, int left, int right) {
	bitword res = 0, n2;
	int n1;
	n1 = left / 32;
	for (int i = left; i < right; i++) {
		//printf("%u!!\n", res);
		if (i % 32 == 0 && i != left)
			n1++;
		if (i % 32 == 0 && right - i >= 32) {
			n2 = arr[n1];
			n2 = n2 - ((n2 >> 1) & 0x55555555);
			n2 = (n2 & 0x33333333) + ((n2 >> 2) & 0x33333333);
			n2 = (n2 + (n2 >> 4)) & 0x0F0F0F0F;
			n2 = n2 + (n2 >> 8);
			n2 = n2 + (n2 >> 16);
			res += n2 & 0x0000003F;
			i += 31;
		}
		else {
			n2 = (arr[n1] >> (i % 32)) & 1;
			if (n2 == 1)
				res++;
		}
	}
	return res;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	bitword n, t, num, idx, newval, left, right;
	scanf("%u", &n);
	for (int i = 0; i < n; i++) {
		scanf("%u", &t);
		if (t == 0) {
			scanf("%u", &num);
			bitsetZero(A, num);
		}
		if (t == 1) {
			scanf("%u", &idx);
			printf("%u\n", bitsetGet(A, idx));
		}
		if (t == 2) {
			scanf("%u%u", &idx, &newval);
			bitsetSet(A, idx, newval);
		}
		if (t == 3) {
			scanf("%u%u%u", &left, &right, &newval);
			bitsetSetSeg(A, left, right, newval);
		}
		if (t == 4) {
			scanf("%u%u", &left, &right);
			printf("%d\n", bitsetCount(A, left, right));
		}
	}
	return 0;
}
