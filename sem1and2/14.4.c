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
int k = 0;
int lvl_t = 0;
void cnt(Tree* t, FILE* f2, int lvl) {
	if (t == NULL) {
		return;
	}
	lvl_t++;
	if (lvl_t - 1 == lvl)
		k++;
	cnt(t->left, f2, lvl);
	cnt(t->right, f2, lvl);
	lvl_t--;
	free(t);
}
int main() {
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	int a, lvl;
	fscanf(f1, "%d", &lvl);
	Tree* tree = (Tree*)malloc(sizeof(Tree));
	fscanf(f1, "%d", &a);
	tree->value = a;
	tree->left = NULL;
	tree->right = NULL;
	while (fscanf(f1, "%d", &a) == 1) {
		add(tree, a);
	}
	cnt(tree, f2, lvl);
	fprintf(f2, "%d", k);
	fclose(f1);
	fclose(f2);
	return 0;
}