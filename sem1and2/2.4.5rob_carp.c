#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <math.h>
#define N 10000001
typedef struct list {
	char *str;
	int index;
	struct list* next;
} List;
List* H[10000001] = { 0 };
List* append(List* spisok, char* x, int i) {
	List* head = (List*)malloc(sizeof(List));
	head->str = x;
	head->index = i;
	head->next = spisok;
	return head;
}
long long hash_first(char *s, int m) {
	int b = 7; 
	long long h = 0;
	for (int j = 0; j < m; j++) {
		h = (h * b + s[j]) % N;
	}
	return h;
}
long long hash(long long h, char* s, int m, long long c) {
	int base = 7;
	long long hash = h;
	hash += N;
	hash -= (c * s[-1]) % N;
	hash *= base;
	hash += s[m - 1];
	hash %= N;
	return hash;
}
int main() {
	int t1 = time(NULL);
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	int n, m, d = 0, f, base = 7;
	long long hash_pod, c = 1;
	char s[1000001] = { 0 };
	fscanf(f1, "%d%d", &n, &m);
	fscanf(f1, "%s", s);
	for (int i = 0; i < m - 1; i++) {
		c *= base;
		c %= N;
	}
	for (int i = 0; i < n - m + 1; i++) {
		if (i == 0)
			hash_pod = hash_first(&s[i], m);
		else
			hash_pod = hash(hash_pod, &s[i], m, c);
		if (H[hash_pod] == 0) {
			List* L = (List*)malloc(sizeof(List));
			char* str = &s[i];
			L->str = str;
			L->index = d;
			fprintf(f2, "%d ", d);
			d++;
			L->next = NULL;
			H[hash_pod] = L;
		}
		else {
			List* p = H[hash_pod];
			while (p != NULL) {
				f = 0;
				for (int j = i, g = 0; j < i + m; j++, g++) {
					if (s[j] != (p->str)[g]) {
						f = 1;
						break;
					}
				}
				if (f == 0) {
					fprintf(f2, "%d ", p->index);
					break;
				}
				if (p->next == NULL) {
					H[hash_pod] = append(H[hash_pod], &s[i], d);
					fprintf(f2, "%d ", d);
					d++;
				}
				p = p->next; 
			}
		}
	}
	printf("%d", time(NULL) - t1);
	fclose(f1);
	fclose(f2);
	return 0;
}