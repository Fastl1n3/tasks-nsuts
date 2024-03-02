#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define N 1001
typedef struct node {
	char value;
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
void push(Stack* s, char k) {
	list* L = (list*)malloc(sizeof(list));
	L->value = k;
	L->next = s->top;
	s->top = L;
}
char pop(Stack* s) {
	char out = s->top->value;
	list* p = s->top;
	s->top = p->next;
	free(p);
	return out;
}
char top(Stack* s) {
	return s->top->value;
}
int empty(Stack* s) {
	return (s->top == NULL);
}
int main() {
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	Stack* st = createstack();
	char s_in[N] = { 0 }, s_out[N] = { 0 };
	char x;
	fscanf(f1, "%s", s_in);
	int len = strlen(s_in);
	int j = 0;
	for (int i = 0; i < len; i++) {
		x = s_in[i];
		if (x >= 40 && x <= 47) {
			if (empty(st) == 1)
				push(st, x);
			else {
				if (x == '(')
					push(st, x);
				if (x == ')') {
					while (top(st) != '(') {
						s_out[j] = pop(st);
						j++;
					}
					pop(st);
				}
				if (strchr("*/", x)) {
					while (empty(st) == 0 && strchr("*/", top(st)) != NULL) {
						s_out[j] = pop(st);
						j++;
					}
					push(st, x);
				}
				if (strchr("+-", x)) {
						while (empty(st) == 0 && top(st) != '(') {
							s_out[j] = pop(st);
							j++;
						}
						push(st, x);
				}
			}
		}
		else {
			s_out[j] = x;
			j++;
		}		
	}
	while (empty(st) == 0) {
		s_out[j] = pop(st);
		j++;
	}
	fprintf(f2, "%s", s_out);
	fclose(f1);
	fclose(f2);
	return 0;
}