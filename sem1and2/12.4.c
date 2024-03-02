#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct list {
	int data;
	struct list* next;
} List;
List* append(List* head, int a) {
	List* tmp = (List*)malloc(sizeof(List));
	tmp->data = a;
	tmp->next = head;
	return tmp;
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
		spisok = append(spisok, a);
	}
	int k = 0;
	while (spisok != NULL)
	{
		List* p = spisok;
		if (spisok->data < 0 && spisok->data % 7 == 0)
			k += 1;
		spisok = spisok->next;
		free(p);
	}
	fprintf(f2, "%d", k);
	fclose(f1);
	fclose(f2);
	return 0;
}