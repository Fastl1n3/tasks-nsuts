#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#define N 1000000
typedef struct list {
	unsigned value;
	unsigned index;
	struct list* next;
} List;
List* H[N] = { 0 };
List* append(List* spisok, unsigned x, unsigned i) {
	List* head = (List*)malloc(sizeof(List));
	head->value = x;
	head->index = i;
	head->next = spisok;
	return head;
}
unsigned key(unsigned x) {
	return x % N;
}
int main() {
	int t1 = time(NULL);
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	int f = 0, i = 1, k;
	unsigned x;
	while (f == 0) {
		printf("eval %u\n", i);
		fflush(stdout);
		scanf("%u", &x);
		k = key(x);
		if (H[k] == 0) {
			List* L = (List*)malloc(sizeof(List));
			L->value = x;
			L->index = i;
			L->next = NULL;
			H[k] = L;
		}
		else {
			List* p = H[k];
			while (p != NULL) {
				if (x == p->value) {
					printf("answer %d %d\n", p->index, i);
					fflush(stdout);
					return 0;
				}
				p = p->next;
			}
		}
		i++;
	}
	return 0;
}