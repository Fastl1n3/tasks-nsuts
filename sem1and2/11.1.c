#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 100001
typedef struct DateTime_s {
	int year, month, day;
	int hours, minutes, seconds;
} DateTime;
DateTime A[N];
DateTime min_date(const DateTime* arr, int cnt) {
	DateTime min_d = arr[0];
	for (int i = 1; i < cnt; i++) {
		if (arr[i].year <= min_d.year) {
			if (arr[i].year < min_d.year)
				min_d = arr[i];
			else {
				if (arr[i].month <= min_d.month) {
					if (arr[i].month < min_d.month)
						min_d = arr[i];
					else {
						if (arr[i].day <= min_d.day) {
							if (arr[i].day < min_d.day)
								min_d = arr[i];
							else {
								if (arr[i].hours <= min_d.hours) {
									if (arr[i].hours < min_d.hours)
										min_d = arr[i];
									else {
										if (arr[i].minutes <= min_d.minutes) {
											if (arr[i].minutes < min_d.minutes)
												min_d = arr[i];
											else {
												if (arr[i].seconds < min_d.seconds)
													min_d = arr[i];
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return min_d;
}
int main() {
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	int n;
	fscanf(f1, "%d", &n);
	for (int i = 0; i < n; i++) {
		fscanf(f1, "%d", &A[i].year);
		fscanf(f1, "%d", &A[i].month);
		fscanf(f1, "%d", &A[i].day);
		fscanf(f1, "%d", &A[i].hours);
		fscanf(f1, "%d", &A[i].minutes);
		fscanf(f1, "%d", &A[i].seconds);
		//fprintf(f2, "%d %d %d %d %d %d\n", A[i].year, A[i].month, A[i].day, A[i].hours, A[i].minutes, A[i].seconds);
	}
	DateTime m = min_date(A, n);
	fprintf(f2, "%d %d %d %d %d %d", m.year, m.month, m.day, m.hours, m.minutes, m.seconds);
	fclose(f1);
	fclose(f2);
	return 0;
}