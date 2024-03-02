#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct list {
	int data;
	struct list* next;
} List;
int main() {
	int n, k;
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	List* spisok = (List*)malloc(sizeof(List));
	fscanf(f1, "%d", &n);
	fscanf(f1, "%d", &k);
	spisok->data = 1;
	spisok->next = NULL;
	int i = 2;
	List* p = spisok;
	while (i <= n) {
		List* tmp = (List*)malloc(sizeof(List));
		tmp->data = i;
		tmp->next = NULL;
		p->next = tmp;
		p = p->next;
		i++;
	}
	p->next = spisok;
	p = spisok;
	i = 1;
	while (p != p->next) {
		if (i % k == k - 1) {
			List* clear = p->next;
			p->next = p->next->next;
			free(clear);
			i = 0;
		}
		i++;
		p = p->next;
	}
	if (k == 1)
		fprintf(f2, "%d", n);
	else
		fprintf(f2, "%d", p->data);
	free(p);
	fclose(f1);
	fclose(f2);
	return 0;
}