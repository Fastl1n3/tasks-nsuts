#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct time {
	int hours;
	int minutes;
	int seconds;
} Time;
int readTime(char* iStr, int* oHours, int* oMinutes, int* oSeconds) {
	int f = 1;
	int d = 0, i = 0, k = 10;
	if (iStr[1] == '|')
		f = 0;
	while (f == 1 && iStr[i] != ':') {
		if (i >= 1)
			d *= 10;
		d += (iStr[i] - '0');
		i++;
	}
	if (d >= 0 && d <= 23 && f == 1)
		(*oHours) = d;
	else
		f = 0;
	i++;
	int j = 0;
	d = 0;
	while (f == 1 && iStr[i] != ':' && iStr[i] != '\0') {
		if (j >= 1)
			d *= 10;
		d += (iStr[i] - '0');
		i++;
		j++;
	}
	if (d >= 0 && d <= 59 && f == 1)
		(*oMinutes) = d;
	else
		f = 0;
	i++;
	j = 0;
	d = 0;
	while (f == 1 && iStr[i] != '\0') {
		if (j >= 1)
			d *= 10;
		d += (iStr[i] - '0');
		i++;
		j++;
	}
	if (d >= 0 && d <= 59 && f == 1)
		(*oSeconds) = d;
	else
		f = 0;
	if (f == 0) {
		(*oHours) = -1;
		(*oMinutes) = -1;
		(*oSeconds) = -1;
	}
	return f;
}
int main() {
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	Time t;
	int h, m, s, f;
	char A[20] = { 0 }, c1, c2;
	char res[20] = { 0 };
	fgets(A, sizeof(A), f1);
	int k = sscanf(A, "%d%c%d%c%d", &h, &c1, &m, &c2, &s);
		if (k == 5) {
			sprintf(A, "%d%c%d%c%d", h, c1, m, c2, s);
			f = readTime(A, &t.hours, &t.minutes, &t.seconds);
			fprintf(f2, "%d %d %d %d\n", f, t.hours, t.minutes, t.seconds);
			readTime(A, &t.hours, &t.minutes, &t.seconds);
			fprintf(f2, "%d %d %d\n", f, t.hours, t.minutes);
			readTime(A, &t.hours, &t.minutes, &t.seconds);
			fprintf(f2, "%d %d\n", f, t.hours);
		}
		if (k != 5) {
			s = 0;
			c2 = '\0';
			sprintf(A, "%d%c%d%c%d", h, c1, m, c2, s);
			f = readTime(A, &t.hours, &t.minutes, &t.seconds);
			fprintf(f2, "%d %d %d %d\n", f, t.hours, t.minutes, t.seconds);
			readTime(A, &t.hours, &t.minutes, &t.seconds);
			fprintf(f2, "%d %d %d\n", f, t.hours, t.minutes);
			readTime(A, &t.hours, &t.minutes, &t.seconds);
			fprintf(f2, "%d %d\n", f, t.hours);
		}
	fclose(f1);
	fclose(f2);
	return 0;
}