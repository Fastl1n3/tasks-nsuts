#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct list {
	int data;
	struct list* next;
} List;
void append_tail(List* head, int a) {
	List* tmp = (List*)malloc(sizeof(List));
	tmp->data = a;
	tmp->next = NULL;
	List* p = head;
	while (p->next != NULL) {
		p = p->next;
	}
	p->next = tmp;
}
int main() {
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	int n, a;
	List* spisok = (List*)malloc(sizeof(List));
	fscanf(f1, "%d", &a);
	spisok->data = a;
	spisok->next = NULL;
	while (fscanf(f1, "%d", &a) == 1) {
		append_tail(spisok, a);
	}
	int k = 0, s = 0;
	while (spisok != NULL)
	{
		List* p = spisok;
		s += spisok->data;
		k += 1;
		spisok = spisok->next;
		free(p);
	}
	fprintf(f2, "%d", s / k);
	fclose(f1);
	fclose(f2);
	return 0;
}