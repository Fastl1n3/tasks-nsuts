#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node {
	int value;
	struct node* left;
	struct node* right;
} Tree;
Tree* add(Tree* t, int val) {
	if (t == NULL) {
		t = (Tree*)malloc(sizeof(Tree));
		t->value = val;
		t->left = NULL;
		t->right = NULL;
		return t;
	}
	if (t->value > val)
		t->left = add(t->left, val);
	else if (t->value < val)
		t->right = add(t->right, val);
	return t;
}
void pref(Tree* t, FILE* f2) {
	if (t == NULL)
		return;
	fprintf(f2, "%d ", t->value);
	pref(t->left, f2);
	pref(t->right, f2);
}
void post(Tree* t, FILE* f2) {
	if (t == NULL)
		return;
	post(t->left, f2);
	post(t->right, f2);
	fprintf(f2, "%d ", t->value);
	free(t);
}
int main() {
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	int a;
	Tree* tree = (Tree*)malloc(sizeof(Tree));
	fscanf(f1, "%d", &a);
	tree->value = a;
	tree->left = NULL;
	tree->right = NULL;
	while (fscanf(f1, "%d", &a) == 1) {
		add(tree, a);
	}
	pref(tree, f2);
	fprintf(f2, "\n");
	post(tree, f2);
	fclose(f1);
	fclose(f2);
	return 0;
}