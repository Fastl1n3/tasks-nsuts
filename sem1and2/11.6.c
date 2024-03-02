#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 100001
typedef struct node {
	double data;
	int next;
} List;
List list[N];
int main() {
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	int n, head;
	fscanf(f1, "%d%d", &n, &head);
	for (int i = 0; i < n; i++) {
		fscanf(f1, "%lf%d", &list[i].data, &list[i].next);
	}
	int i = head;
	while (i != -1) {
		fprintf(f2, "%0.3lf\n", list[i].data);
		i = list[i].next;
	}
	fclose(f1);
	fclose(f2);
	return 0;
}