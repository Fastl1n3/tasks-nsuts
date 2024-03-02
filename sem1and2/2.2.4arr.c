#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef struct deq {
	int size;
	int first;
	int leng;
	int* arr;
}Deq;
Deq* createdeq() {
	Deq* q = (Deq*)malloc(sizeof(Deq));
	q->first = 0;
	q->leng = 0;
	q->size = 1;
	q->arr = (int*)malloc(sizeof(int) * q->size);
	return q;
}
void push_left(Deq* q, int a) {
	if (q->leng == q->size) {
		q->arr = (int*)realloc(q->arr, sizeof(int) * q->size * 2);
		if (q->first > 0)
			memcpy(q->arr + q->size, q->arr, (q->first) * sizeof(int));
		q->size *= 2;
	}
	if (q->first == 0) {
		q->arr[q->size - 1] = a;
		q->first = q->size - 1;
	}
	else {
		q->arr[--q->first] = a;
	}
	q->leng++;
}
void push_right(Deq* q, int a) {
	if (q->leng == q->size) {
		q->arr = (int*)realloc(q->arr, sizeof(int) * q->size * 2);
		if (q->first > 0)
			memcpy(q->arr + q->size, q->arr, (q->first) * sizeof(int));
		q->size *= 2;
	}
	q->arr[(q->first + q->leng++) % q->size] = a;
}
int pop_left(Deq* q) {
	int a = q->arr[q->first++];
	q->first %= q->size;
	q->leng--;
	return a;
}
int pop_right(Deq* q) {
	int a = q->arr[(q->first + q->leng - 1) % q->size];
	q->leng--;
	return a;
}
int empty(Deq* q) {
	return(q->leng == 0);
}
int convert(char c) {
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c == 'A')
		return 10;
	if (c == 'B')
		return 11;
	if (c == 'C')
		return 12;
	if (c == 'D')
		return 13;
	if (c == 'E')
		return 14;
	if (c == 'F')
		return 15;
}
int main() {
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	Deq* d1 = createdeq();
	Deq* d2 = createdeq();
	int n, m, x;
	fscanf(f1, "%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		push_right(d1, i);
		push_right(d2, -i);
	}
	char c;
	int b0, b1, b2, b3, f, k = n;
	fscanf(f1, "%c", &c);
	for (int i = 0; i < m; i++) {
		f = 0;
		fscanf(f1, "%c", &c);
		while (c == ' ' || c == '\n')
			fscanf(f1, "%c", &c);
		x = convert(c);
		b0 = x & 1;
		b1 = (x & 2) / 2;
		b2 = (x & 4) / 4;
		b3 = (x & 8) / 8;
		if (b3 == 1) {
			if (empty(d2) == 0) {
				k--;
				if (b2 == 1)
					x = pop_right(d2);
				else
					x = pop_left(d2);
			}
			else
				f = 1;
		}
		else {
			if (empty(d1) == 0) {
				if (b2 == 1)
					x = pop_right(d1);
				else
					x = pop_left(d1);
			}
			else
				f = 1;
		}
		if (f == 0) {
			if (b1 == 1) {
				k++;
				if (b0 == 1)
					push_right(d2, x);
				else
					push_left(d2, x);
			}
			else {
				if (b0 == 1)
					push_right(d1, x);
				else
					push_left(d1, x);
			}
		}
	}
	fprintf(f2, "%d ", n * 2 - k);
	while (empty(d1) == 0) {
		fprintf(f2, "%d ", pop_left(d1));
	}
	fprintf(f2, "\n");
	fprintf(f2, "%d ", k);
	while (empty(d2) == 0) {
		fprintf(f2, "%d ", pop_left(d2));
	}
	fclose(f1);
	fclose(f2);
	return 0;
}