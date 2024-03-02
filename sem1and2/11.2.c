#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 100001
typedef struct Label_s {
	char name[16]; //имя автора (заканчивается нулём)
	int age; //возраст автора (сколько лет)
} Label;
Label A[N];
typedef struct NameStats_s {
	int cntTotal; //сколько всего подписей
	int cntLong; //сколько подписей с именами длиннее 10 букв
} NameStats;
typedef struct AgeStats_s {
	int cntTotal; //сколько всего подписей
	int cntAdults; //сколько подписей взрослых (хотя бы 18 лет)
	int cntKids; //сколько подписей детей (меньше 14 лет)
} AgeStats;
void calcStats(const Label* arr, int cnt, NameStats* oNames, AgeStats* oAges) {
	for (int i = 0; i < cnt; i++) {
		if (strlen(arr[i].name) > 10) {
			oNames->cntLong++;
		}
		if (arr[i].age >= 18)
			oAges->cntAdults++;
		if (arr[i].age < 14)
			oAges->cntKids++;
	}
}
int main() {
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	int n;
	char a[5];
	fscanf(f1, "%d", &n);
	NameStats n_st;
	n_st.cntTotal = n;
	n_st.cntLong = 0;
	AgeStats n_a;
	n_a.cntTotal = n;
	n_a.cntAdults = 0;
	n_a.cntKids = 0;
	for (int i = 0; i < n; i++) {
		fscanf(f1, "%s", &A[i].name);
		fscanf(f1, "%d", &A[i].age);
		fscanf(f1, "%s", a);
	}
	calcStats(A, n, &n_st, &n_a);
	fprintf(f2, "names: total = %d\n", n_st.cntTotal);
	fprintf(f2, "names: long = %d\n", n_st.cntLong);
	fprintf(f2, "ages: total = %d\n", n_a.cntTotal);
	fprintf(f2, "ages: adult = %d\n", n_a.cntAdults);
	fprintf(f2, "ages: kid = %d\n", n_a.cntKids);
	fclose(f1);
	fclose(f2);
	return 0;
}