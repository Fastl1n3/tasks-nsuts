#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <math.h>
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int x, y, z, s;
    scanf("%d%d%d", &x, &y, &z);
    if (x > 0 && y > 0 && z > 0) s = 2 * (x * y + x * z + y * z);
    else {
        if (x <= 0) s = -1;
        else {
            if (y <= 0) s = -2;
            else s = -3;
        }
    }
    printf("%d", s);
    return 0;
}
