#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int a, b, h1, h2, h3, h4;
	scanf("%d %d %d", &a, &b);
	if (a >= 0)
		{ 
		h1 = a / b;
		if (a % b != 0)
			h2 = a / b + 1;
		else
			h2 = a / b;
		h3 = a / b;
		h4 = a % b;
		}
	else
		{ 
		if (a % b != 0)
			h1 = a / b - 1;
		else
			h1 = a / b;
		h2 = a / b;
		h3 = a / b;
		if (a % b == 0)
			h4 = 0;
		else h4 = b + (a % b);
		}
	printf("%d %d %d %d\n", h1, h2, h3, h4);
	return 0;
}