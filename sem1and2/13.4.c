#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct list {
	int data;
	struct list* next;
} List;
int main() {
	int n1, n2;
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	List* spisok1 = (List*)malloc(sizeof(List));
	List* spisok2 = (List*)malloc(sizeof(List));
	fscanf(f1, "%d%d", &n1, &n2);
	int a;
	fscanf(f1, "%d", &a);
	spisok1->data = a;
	spisok1->next = NULL;
	List* p1 = spisok1;
	for (int i = 0; i < n1 - 1; i++) {
		List* tmp = (List*)malloc(sizeof(List));
		fscanf(f1, "%d", &a);
		tmp->data = a;
		tmp->next = spisok1;
		spisok1 = tmp;
	}
	fscanf(f1, "%d", &a);
	spisok2->data = a;
	spisok2->next = NULL;
	List* p2 = spisok2;
	for (int i = 0; i < n2 - 1; i++) {
		List* tmp = (List*)malloc(sizeof(List));
		fscanf(f1, "%d", &a);
		tmp->data = a;
		tmp->next = spisok2;
		spisok2 = tmp;
	}
	List* t1;
	if (spisok1->data > spisok2->data) {
		p1 = spisok1->next;
		spisok1->next = spisok2;
		spisok2 = spisok1;
		spisok1 = p1;
	}
	p1 = spisok1;
	p2 = spisok2;
	while (p2 != NULL && p1 != NULL) {
		t1 = p1;
		while (p2->next != NULL && p2->next->data > p1->data) {
			p2 = p2->next;
		}
		p1 = p1->next;
		if (p2->next == NULL) {
			p2->next = t1;
			t1->next = NULL;
			p2 = p2->next;
		}
		else {
			t1->next = p2->next;
			List* t2 = p2->next;
			p2->next = t1;
		}	
		if (p1 == NULL)
			break;
	}
	while (spisok2 != NULL) {
		fprintf(f2, "%d ", spisok2->data);
		List* clear = spisok2;
		spisok2 = spisok2->next;
		free(clear);
	}
	fclose(f1);
	fclose(f2);
	return 0;
}