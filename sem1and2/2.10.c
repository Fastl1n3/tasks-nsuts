#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <math.h>
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int k, cislo, i, c, stepen = 1, cifra;
	cislo = i = c = 1;
	scanf("%d", &k);
	while (cislo > 0) {
		if (i >= k) {
			for (int j = 0; j <= (i - k); j++) {
				cifra = cislo % 10;
				cislo /= 10;
			}
			break;
		}
		cislo++;
		if (cislo % (int)pow(10, stepen) == 0) {
			c += 1;
			stepen += 1;
		}
		i += c;
	}
	printf("%d", cifra);
	return 0;
}