#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	char a;
	int k = 0, f = 0;
	scanf("%c", &a);
	while (a != '.') {
		k++;
		if (k == 2 && a != 'A') {
			printf("DOES NOT FIT");
			f = 1;
			break;
		}
		scanf("%c", &a);
	}
	if (k == 3)
		printf("FITS");
	else if (f == 0)
		printf("DOES NOT FIT");
	return 0;
}