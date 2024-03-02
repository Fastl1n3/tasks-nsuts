#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <math.h>
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    float x1, y1, x2, y2, x3, y3;
    scanf("%f %f\n %f %f\n %f %f", &x1, &y1, &x2, &y2, &x3, &y3);
    double a1, a2, a3, p, s, P;
    a1 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    a2 = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
    a3 = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    P = ("%0.3lf\n", a1 + a2 + a3);
    printf("%0.3lf\n", P);
    p = P / 2;
    s = sqrt(p*(p - a1)*(p - a2)*(p - a3));
    printf("%0.3lf", s);
    return 0;
}