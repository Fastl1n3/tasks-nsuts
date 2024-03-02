#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 1000100
char s_in[N] = { 0 };
char s_out[N] = { 0 };
typedef struct node_ch {
	char value;
	struct node* next;
} list_ch;
typedef struct node_int {
	double value;
	struct node* next;
} list_int;
typedef struct stack {
	list_ch* top_ch;
	list_int* top_int;
}Stack;
Stack* createstack_ch() {
	Stack* s = (Stack*)malloc(sizeof(Stack));
	s->top_ch = NULL;
	return s;
}
void push_ch(Stack* s, char k) {
	list_ch* L = (list_ch*)malloc(sizeof(list_ch));
	L->value = k;
	L->next = s->top_ch;
	s->top_ch = L;
}
char pop_ch(Stack* s) {
	char out = s->top_ch->value;
	list_ch* p = s->top_ch;
	s->top_ch = p->next;
	free(p);
	return out;
}
char top_ch(Stack* s) {
	return s->top_ch->value;
}
int empty_ch(Stack* s) {
	return (s->top_ch == NULL);
}
Stack* createstack_int() {
	Stack* s = (Stack*)malloc(sizeof(Stack));
	s->top_int = NULL;
	return s;
}
void push_int(Stack* s, double k) {
	list_int* L = (list_int*)malloc(sizeof(list_int));
	L->value = k;
	L->next = s->top_int;
	s->top_int = L;
}
double pop_int(Stack* s) {
	double out = s->top_int->value;
	list_int* p = s->top_int;
	s->top_int = p->next;
	free(p);
	return out;
}
double top_int(Stack* s) {
	return s->top_int->value;
}
int empty_int(Stack* s) {
	return (s->top_int == NULL);
}
char* inf_to_post(char* s_inf, Stack* st) {
	char x;
	int j = 0, i = 0;
	while (s_inf[i] != '\0') {
		x = s_inf[i];
		if (x >= '(' && x <= '/') {
			s_out[j] = ' ';
			j++;
			if (x == '-' && (i == 0 || s_inf[i - 1] == '(')) {
				x = '~';
			}
			if (empty_ch(st) == 1)
				push_ch(st, x);
			else {
				if (x == '(')
					push_ch(st, x);
				if (x == ')') {
					while (top_ch(st) != '(') {
						s_out[j] = pop_ch(st);
						j++;
						s_out[j] = ' ';
						j++;
					}
					pop_ch(st);
				}
				if (x == '~') {
					while (empty_ch(st) == 0 && top_ch(st) == '~') {
						s_out[j] = pop_ch(st);
						j++;
					}
					push_ch(st, x);
				}
				if (strchr("*/", x)) {
					while (empty_ch(st) == 0 && (strchr("*/", top_ch(st)) != NULL || top_ch(st) == '~')) {
						s_out[j] = pop_ch(st);
						j++;	
					}
					push_ch(st, x);
				}
				if (strchr("+-", x)) {
					while (empty_ch(st) == 0 && top_ch(st) != '(') {
						s_out[j] = pop_ch(st);
						j++;
						s_out[j] = ' ';
						j++;
					}
					push_ch(st, x);
				}
			}
		}
		else if (x != ' ' && x != '\n') {
			s_out[j] = x;
			j++;
		}
		i++;
	}
	s_out[j] = ' ';
	j++;
	while (empty_ch(st) == 0) {
		s_out[j] = pop_ch(st);
		j++;
		s_out[j] = ' ';
		j++;
	}
	return s_out;
}
double count(char* s, Stack* st) {
	char a;
	int x;
	double x1, x2;
	int i = 0;
	while (s[i] != '\0') {
		a = s[i];
		if (a >= '0' && a <= '9') {
			x = a - '0';
			i++;
			a = s[i];
			while (s[i] != '\0' && a != ' ') {
				x = x * 10 + a - '0';
				i++;
				a = s[i];
			}
			push_int(st, x);
		}
		else if (strchr("~+-*/", a) != NULL) {
			x1 = pop_int(st);
			if (a == '~') {
				push_int(st, 0 - x1);
			}
			else {
				x2 = pop_int(st);
				if (a == '+')
					push_int(st, x2 + x1);
				if (a == '-')
					push_int(st, x2 - x1);
				if (a == '*')
					push_int(st, x2 * x1);
				if (a == '/')
					push_int(st, x2 / x1);
			}
		}
		i++;
	}
	return top_int(st);
}
int main() {
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	Stack* st_ch = createstack_ch();
	Stack* st_int = createstack_int();
	char c;
	int i = 0;
	while (fscanf(f1, "%c", &c) == 1) {
		if (c != ' ' && c != '\n') {
			s_in[i] = c;
			i++;
		}
	}
	char* s_post = inf_to_post(s_in, st_ch);
	double res = count(s_post, st_int);
	fprintf(f2, "%0.20lf\n", res);
	fclose(f1);
	fclose(f2);
	return 0;
}
