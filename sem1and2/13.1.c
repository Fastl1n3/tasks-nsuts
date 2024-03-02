#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct list {
	int data;
	struct list* next;
} List;
int main() {
	int n, a;
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	List* spisok = (List*)malloc(sizeof(List));
	fscanf(f1, "%d", &a);
	spisok->data = a;
	spisok->next = NULL;
	List* p = spisok;
	while (fscanf(f1, "%d", &a) == 1) {
		List* tmp = (List*)malloc(sizeof(List));
		p->next = tmp;
		tmp->data = a;
		tmp->next = NULL;
		p = p->next;
	}
	while (spisok != NULL) {
		List* p = spisok;
		a = spisok->data;
		while (p->next != NULL && p->next->data == a) {
			List* clear = p->next;
			p->next = p->next->next;
			free(clear);		
		}
		fprintf(f2, "%d ", spisok->data);
		spisok = spisok->next;
	}
	fclose(f1);
	fclose(f2);
	return 0;
}