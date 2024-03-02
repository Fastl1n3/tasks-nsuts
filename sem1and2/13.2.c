#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <malloc.h>
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
	fscanf(f1, "%d", &n);
	fscanf(f1, "%d", &a);
	spisok->data = a;
	spisok->next = NULL;
	while (fscanf(f1, "%d", &a) == 1) {
		List* tmp = (List*)malloc(sizeof(List));
		tmp->data = a;
		tmp->next = spisok;
		spisok = tmp;
	}
	List* p1 = spisok->next;
	List* p2;
	while (p1 != NULL) {
		if (p1->data == n) {
			if (spisok->next == p1) {
				List* clear = spisok;
				spisok = p1;
				free(clear);
			}
			else {
				p2 = spisok;
				while (p2->next->next != p1) {
					p2 = p2->next;
				}
				List* clear = p2->next;
				p2->next = p1;
				free(clear);
			}
		}
		p1 = p1->next;
	}
	while (spisok != NULL) {
		fprintf(f2, "%d ", spisok->data);
		p1 = spisok;
		spisok = spisok->next;
		free(p1);
	}
	fclose(f1);
	fclose(f2);
	return 0;
}