#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int main() {
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	double pi = 2 * asin(1.0);
	int n;
	fscanf(f1, "%d", &n);
	double ax, ay, bx, by, cx, cy;
	double cosA, angle, sinA;
	for (int i = 0; i < n; i++) {
		fscanf(f1, "%lf%lf%lf%lf%lf%lf", &ax, &ay, &bx, &by, &cx, &cy);
		cosA = (cx -ax) * (bx - ax) + (cy - ay) * (by - ay);
		sinA = (cx - ax) * (by - ay) - (bx - ax) * (cy - ay);
		angle = atan2(sinA, cosA) * 180.0 / pi;
		if (angle < 0)
			angle *= -1;
		fprintf(f2, "%0.20g\n", angle);
	}
	fclose(f1);
	fclose(f2);
	return 0;
}