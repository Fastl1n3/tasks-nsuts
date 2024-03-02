#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef struct node {
	int value;
	struct node* next;
	struct node* last;
} list;
typedef struct deq {
	list* left;
	list* right;
} Deq;
Deq* createdeq() {
	Deq* d = (Deq*)malloc(sizeof(Deq));
	d->left = NULL;
	d->right = NULL;
	return d;
}
void push_left(Deq* d, int k) {
	list* L = (list*)malloc(sizeof(list));
	L->value = k;
	L->next = NULL;
	L->last = NULL;
	if (empty(d) == 0) {
		L->next = d->left;
		d->left->last = L;
	}
	d->left = L;
	if (empty(d) == 1)
		d->right = d->left;
}
void push_right(Deq* d, int k) {
	list* L = (list*)malloc(sizeof(list));
	L->value = k;
	L->next = NULL;
	L->last = NULL;
	if (empty(d) == 0) {
		L->last = d->right;
		d->right->next = L;
	}
	d->right = L;
	if (empty(d) == 1)
		d->left = d->right;
}
int pop_left(Deq* d) {
	int out = d->left->value;
	list* p = d->left;
	d->left = p->next;
	free(p);
	return out;
}
int pop_right(Deq* d) {
	int out = d->right->value;
	list* p = d->right;
	d->right = p->last;
	free(p);
	return out;
}
int empty(Deq* d) {
	return(d->left == NULL || d->right == NULL);
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
	fprintf(f2, "%d ", n*2 - k);
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