#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 100001
int main() {
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	int n, t, len, id;
	fscanf(f1, "%d", &n);
	char* p[N];
	int j = 0;
	for (int i = 0; i < n; i++) {
		fscanf(f1, "%d", &t);
		if (t == 0) {
			fscanf(f1, "%d", &len);
			p[j] = (char*)malloc(sizeof(char) * (len + 1));
			fscanf(f1, "%s", p[j]);	
			j++;
		}
		if (t == 1) {
			fscanf(f1, "%d", &id);
			free(p[id]);
			p[id] = NULL;
		}
		if (t == 2) {
			fscanf(f1, "%d", &id);
			fprintf(f2, "%s\n", p[id]);
		}
		if (t == 3) {
			fscanf(f1, "%d", &id);
			char c;
			fscanf(f1, " %c", &c);
			int len = strlen(p[id]), k = 0;
			for (int g = 0; g < len; g++) {
				if (p[id][g] == c)
					k++;
			}
			fprintf(f2, "%d\n", k);
		}
	}
	for (int i = 0; i < j; i++) {
		if (p[i] != NULL)
			free(p[i]);
	}
	fclose(f1);
	fclose(f2);
	return 0;
}