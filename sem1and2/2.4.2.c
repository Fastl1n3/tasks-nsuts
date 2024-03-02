#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#define N 54400000 
typedef struct list {
	long long value;
	int index;
	struct list* next;
} List;
List* H[N] = { 0 };
List* append(List* spisok, long long x, int i) {
	List* head = (List*)malloc(sizeof(List));
	head->value = x;
	head->index = i;
	head->next = spisok;
	return head;
}
long long key(long long x) {
	return x % N;
}
uint64_t func(uint64_t s, long long a, long long  b, long long c, long long M) {
	return (s * s * a + s * b + c) % M;
}
int main() {
	int t1 = time(NULL);
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	long long M, a, b, c, k;
	uint64_t state = 1;
	fscanf(f1, "%lld %lld %lld %lld", &M, &a, &b, &c);
	int f = 0, i = 0;
	while (f == 0) {
		k = key(state);
		if (H[k] == NULL) {
			List* L = (List*)malloc(sizeof(List));
			L->value = state;
			L->index = i;
			L->next = NULL;
			H[k] = L;
		}
		else {
			List* p = H[k];
			while (p != NULL) {
				if (state == p->value) {
					f = 1;
					fprintf(f2, "%d %d\n", p->index, i);
					break;
				}
				p = p->next;
			}
			if (f == 0)
				H[k] = append(H[k], state, i);
			else
				break;
		}
		state = func(state, a, b, c, M);
		i++;
	}
	printf("%d", time(NULL) - t1);
	fclose(f1);
	fclose(f2);
	return 0;
}