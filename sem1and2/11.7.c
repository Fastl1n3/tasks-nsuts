#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 100001
typedef struct node {
	char data[10];
	int next;
} List;
List list[N];
int main() {
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	int t, n, head, q;
	fscanf(f1, "%d", &t);
	for (int i = 0; i < t; i++) {
		fscanf(f1, "%d%d%d", &n, &head, &q);
		for (int j = 0; j < n; j++) {
			fscanf(f1, "%s%d", list[j].data, &list[j].next);
		}
		int k, index;
		char new_d[10] = {0};
		for (int j = 0; j < q; j++) {
			fscanf(f1, "%d%d%s", &k, &index, new_d);
			if (k == 0) {
				strcpy(list[n].data, new_d);
				list[n].next = index + 1;
				if (index == -1)
					head += 1;
				fprintf(f2, "%d\n", n);
				n++;

			}
		}
		fprintf(f2, "===\n");
		int j = head;
		while (j != -1) {
			fprintf(f2, "%s\n", list[j].data);
			j = list[j].next;
		}
		fprintf(f2, "===\n");
	}
	fclose(f1);
	fclose(f2);
	return 0;
}