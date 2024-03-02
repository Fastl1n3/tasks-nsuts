#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node {
	char str[101];
	struct node* left;
	struct node* right;
} Tree;
Tree* add(Tree* t, char* val) {
	if (t == NULL) {
		t = (Tree*)malloc(sizeof(Tree));
		strcpy(t->str, val);
		t->left = NULL;
		t->right = NULL;
		return t;
	}
	int cmp = strcmp(t->str, val);
	if (cmp > 0)
		t->left = add(t->left, val);
	else if (cmp < 0)
		t->right = add(t->right, val);
	return t;
}
void inf(Tree* t, FILE* f2) {
	if (t == NULL) {
		return;
	}
	inf(t->left, f2);
	fprintf(f2, "%s\n", t->str);
	inf(t->right, f2);
	free(t);
}
int main() {
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	char a[101];
	Tree* tree = (Tree*)malloc(sizeof(Tree));
	fscanf(f1, "%s", a);
	strcpy(tree->str, a);
	tree->left = NULL;
	tree->right = NULL;
	while (fscanf(f1, "%s", a) == 1) {
		add(tree, a);
	}
	inf(tree, f2);
	fclose(f1);
	fclose(f2);
	return 0;
}