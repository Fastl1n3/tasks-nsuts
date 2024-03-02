#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define N 1001
typedef struct node {
	int value;
	struct node* next;
} list;
typedef struct stack {
	list* top;
}Stack;
Stack* createstack() {
	Stack* s = (Stack*)malloc(sizeof(Stack));
	s->top = NULL;
	return s;
}
void push(Stack* s, int k) {
	list* L = (list*)malloc(sizeof(list));
	L->value = k;
	L->next = s->top;
	s->top = L;
}
int pop(Stack* s) {
	int out = s->top->value;
	list* p = s->top;
	s->top = p->next;
	free(p);
	return out;
}
int top(Stack* s) {
	return s->top->value;
}
int empty(Stack* s) {
	return (s->top == NULL);
}
int main() {
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	Stack* st = createstack();
	char a;
	int x, x1, x2;
	while (fscanf(f1, "%c", &a) == 1) {
		if (a >= 48 && a <= 57) {
			x = a - '0';
			while (fscanf(f1, "%c", &a) == 1 && a != ' ') {
				x = x * 10 + a - '0';
			}
			push(st, x);
		}
		else if (a != ' ' && a != '\n') {
			x1 = pop(st);
			x2 = pop(st);
			if (a == '+')
				push(st, x2 + x1);
			if (a == '-')
				push(st, x2 - x1);
			if (a == '*')
				push(st, x2 * x1);
			if (a == '/')
				push(st, x2 / x1);
		}
	}
	fprintf(f2, "%d", top(st));
	fclose(f1);
	fclose(f2);
	return 0;
}