#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define N 2000001
int A[N] = { 0 };
typedef struct list {
	int value;
	struct list* next;
} List;
List* H[N] = { 0 };
List* append(List* spisok, int x) {
	List* head = (List*)malloc(sizeof(List));
	head->value = x;
	head->next = spisok;
	return head;
}
int key(int x) {
	return x % 1000000;
}
int main() {
	FILE* f1 = fopen("input.bin", "rb");
	FILE* f2 = fopen("output.bin", "wb");
	int n, x, f = 0, k = 0, j = 0;
	fread(&n, sizeof(n), 1, f1);
	for (int i = 0; i < n; i++) {
		fread(&A[i], sizeof(int), 1, f1);
	}
	for (int i = 0; i < n; i++) {
		f = 0;
		x = A[i];
		if (H[key(x)] == 0) {
			List* L = (List*)malloc(sizeof(List));
			L->value = x;
			L->next = NULL;
			H[key(x)] = L;
			A[j] = x;
			j++;
		}
		else {
			List* p = H[key(x)];
			while (p != NULL) {
				if (x == p->value) {
					f = 1;
					break;
				}
				p = p->next;
			}
			if (f == 0) {
				H[key(x)] = append(H[key(x)], x);
				A[j] = x;
				j++;
			}
		}
	}
	fwrite(&j, sizeof(j), 1, f2);
	for (int i = 0; i < j; i++) {
		fwrite(&A[i], sizeof(A[i]), 1, f2);
	}
	fclose(f1);
	fclose(f2);
	return 0;
}