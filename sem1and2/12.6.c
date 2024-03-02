#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct list {
	int data;
	struct list* next;
} List;
List* append_tail(List* head, int a) {
	List* tmp = (List*)malloc(sizeof(List));
	tmp->data = a;
	List* p = head;
	while (a >= p->data && p->next != NULL) {
		if (p->next != NULL) {
			if (a < p->next->data)
				break;
		}
		p = p->next;
	}
	if (p->data == a) {
		free(tmp);
		return head;
	}
	tmp->data = a;
	if (a < head->data) {
		tmp->next = p;
		return tmp;
	}
	else {
		tmp->next = p->next;
		p->next = tmp;
		return head;
	}
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
		spisok = append_tail(spisok, a);
	}
	int k = 0, s = 0;
	while (spisok != NULL) {
		List* p = spisok;
		fprintf(f2, "%d ", spisok->data);
		spisok = spisok->next;
		free(p);
	}
	fclose(f1);
	fclose(f2);
	return 0;
}