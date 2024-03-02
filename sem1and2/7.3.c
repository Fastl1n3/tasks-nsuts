#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <math.h>
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout); 
    unsigned int n, st = 1, j = 0, new_n = 0, i = 2147483648, a = 1;
    scanf("%d", &n);
    while (a == 1) {
        if (n & i) {
            printf("1");
            st = pow(2, j);
            new_n += st;
        }
        else
            printf("0");
        if (i == 1) {
            printf("\n");
            break;
        }
        i >>= 1;
        j++;
    }
    printf("%d\n", new_n);
    i <<= 31;
    while (a == 1) {
        if (new_n & i) {
            printf("1");
        }
        else
            printf("0");
        if (i == 1)
            break;
        i >>= 1;
    }
	return 0;
}