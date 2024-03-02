#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
struct list {
	char data;
	struct list* next;
};
typedef struct stack {
	struct list* top;
} Stack;
Stack* create()
{
	Stack* S;
	S = (Stack*)malloc(sizeof(Stack));
	S->top = NULL;
	return S;
}
void makenull(Stack* S)
{
	while (S->top) {
		struct list* p = S->top;
		S->top = p->next;
		free(p);
	}
}
char top(Stack* S)
{
	return (S->top->data);
}
char pop(Stack* S)
{
	char a;
	struct list* p;
	p = S->top;
	a = p->data;
	S->top = p->next;
	free(p);
	return a;
}
void push(Stack* S, char a)
{
	struct list* p;
	p = (struct list*)malloc(sizeof(struct list));
	p->data = a;
	p->next = S->top;
	S->top = p;
}
int empty(Stack* S)
{
	return (S->top == NULL);
}
int prior(char c)
{
	if (c == '(')
		return 1;
	if (c == ')')
		return 2;
	if (c == '+')
		return 4;
	if (c == '-')
		return 4;
	if (c == '~')
		return 4;
	if (c == '*')
		return 5;
	if (c == '/')
		return 5;
}


struct list1 {
	long double data;
	struct list1* next;
};
typedef struct stack1 {
	struct list1* top;
} Stack1;
Stack1* create1()
{
	Stack1* S;
	S = (Stack1*)malloc(sizeof(Stack1));
	S->top = NULL;
	return S;
}
void makenull1(Stack1* S)
{
	while (S->top) {
		struct list1* p = S->top;
		S->top = p->next;
		free(p);
	}
}
long double top1(Stack1* S)
{
	return (S->top->data);
}
long double pop1(Stack1* S)
{
	long double a;
	struct list1* p;
	p = S->top;
	a = p->data;
	S->top = p->next;
	free(p);
	return a;
}
void push1(Stack1* S, long double a)
{
	struct list1* p;
	p = (struct list1*)malloc(sizeof(struct list1));
	p->data = a;
	p->next = S->top;
	S->top = p;
}
int empty1(Stack1* S)
{
	return (S->top == NULL);
}
long double oper(long double a, long double b, char c)
{
	if (c == '*')
		return a * b;
	if (c == '/')
		return a / b;
	if (c == '-')
		return a - b;
	if (c == '+')
		return a + b;
}


int main()
{
	int time1 = time(NULL);
	int ks1 = 0, f = 0, f1 = 0, f2 = 0;
	char s[500005], s1[500005];
	Stack* st = create();
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	gets(s);
	for (int i = 0; s[i]; i++)
	{
		if (s[i] == ' ')
			continue;
		if (s[i] <= '9' && s[i] >= '0')
		{
			s1[ks1] = s[i];
			ks1++;
			f = 1;
			f2 = 0;
		}
		else
		{
			if (f == 1)
			{
				s1[ks1] = ' ';
				ks1++;
				f = 0;
			}
			if (s[i] == '(')
			{
				push(st, s[i]);
				f2 = 1;
			}
			else
				if (s[i] == ')')
				{
					while (top(st) != '(')
					{
						s1[ks1] = pop(st);
						ks1++;
						s1[ks1] = ' ';
						ks1++;
					}
					pop(st);
					f2 = 0;
				}
				else
				{
					while (empty(st) == 0 && prior(top(st)) >= prior(s[i]))
					{
						s1[ks1] = pop(st);
						ks1++;
						s1[ks1] = ' ';
						ks1++;
					}
					if (f1 == 0 && s[i] == '-')
						push(st, '~');
					else
						if (f2 == 1 && s[i] == '-')
							push(st, '~');
						else
							push(st, s[i]);
					f2 = 0;
				}
		}
		f1 = 1;
	}
	while (empty(st) == 0)
	{
		if (f == 1)
		{
			f = 0;
			s1[ks1] = ' ';
			ks1++;
		}
		s1[ks1] = pop(st);
		ks1++;
		s1[ks1] = ' ';
		ks1++;
	}
	s1[ks1] = '\0';
	// for (int i = 0; s1[i]; i++)
	// printf("%c", s1[i]);
	// printf("\n");

	int z = 0;
	long double a, e;
	Stack1* st1 = create1();
	sscanf(s1, "%lf", &a);
	push1(st1, a);
	while (s1[z] != ' ')
		z++;
	z++;
	while (z < strlen(s1))
	{
		if (s1[z] - '0' >= 0 && s1[z] - '0' <= 9)
		{
			a = 0;
			while (s1[z] != ' ')
			{
				a = a * 10 + (s1[z] - '0');
				z++;
			}
			push1(st1, a);
		}
		else
		{
			if (s1[z] == '~')
			{
				a = -1 * pop1(st1);
				push1(st1, a);
			}
			else
			{
				a = oper(pop1(st1), pop1(st1), s1[z]);
				push1(st1, a);
			}
			z++;
		}
		z++;
	}
	printf("%.22g\n", pop1(st1));
	printf("%d", time(NULL) - time1);
	return 0;
}