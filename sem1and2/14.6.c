#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node {
	char znak;
	int val;
	struct node* left;
	struct node* right;
} Tree;
int z = 0;
char A[5] = "+-*/";
Tree* add(Tree* t, char x) {
	if (t == NULL) {
		z = 1;
		t = (Tree*)malloc(sizeof(Tree));
		if (strchr(A, x) == NULL || strchr(A, x) == &A[4]) {
			t->val = x - '0';
			t->znak = NULL;
		}
		else {
			t->znak = x;
			t->val = NULL;
		}
		t->left = NULL;
		t->right = NULL;
		return t;
	}
	z = 0;
	if (t->left == NULL || t->left->znak != NULL)
		t->left = add(t->left, x);
	if (z == 0 && (t->right == NULL || t->right->znak != NULL))
		t->right = add(t->right, x);
	return t;
}
int f = 0;
void inf(Tree* t, FILE* f2) {
	if (t == NULL) {
		return;
	}
	inf(t->left, f2);
	inf(t->right, f2);
	if (t->right != NULL && t->left != NULL && t->znak != NULL) { 
		if (t->znak == '+')
			t->val = (t->left->val + t->right->val);
		if (t->znak == '-')
			t->val = (t->left->val - t->right->val);
		if (t->znak == '*')
			t->val = ((t->left->val) * (t->right->val));
		if (t->znak == '/') {
			if (t->right->val == 0) {
				f = 1;
				return;
			}
			t->val = ((t->left->val) / (t->right->val));
		}
		t->znak = NULL;
		printf("=%d) ", t->val);
		free(t->right);
		free(t->left);
		t->right = NULL;
		t->left = NULL;
	}
}
int main() {
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	char a;
	Tree* tree = (Tree*)malloc(sizeof(Tree));
	fscanf(f1, "%c", &a);
	if (a >='0' && a <= '9') {
		tree->val = a - '0';
		tree->znak = NULL;
	}
	else {
		tree->znak = a;
		tree->val = NULL;
	}
	tree->left = NULL;
	tree->right = NULL;
	
	while (fscanf(f1, "%c", &a) == 1) {
		add(tree, a);
	}
	inf(tree, f2);
	if (f == 1) {
		fprintf(f2, "NO");
		return 0;
	}
	if (tree->left != NULL && tree->right != NULL) {
		if (tree->znak == '+')
			tree->val = (tree->left->val + tree->right->val);
		if (tree->znak == '-')
			tree->val = (tree->left->val - tree->right->val);
		if (tree->znak == '*')
			tree->val = ((tree->left->val) * (tree->right->val));
		if (tree->znak == '/') {
			if (tree->right->val == 0) {
				fprintf(f2, "NO");
				return 0;
			}
			tree->val = (tree->left->val) / (tree->right->val);
		}
		tree->znak = NULL;
		free(tree->right);
		free(tree->left);
	}
	fprintf(f2, "%d\n", tree->val);
	free(tree);
	fclose(f1);
	fclose(f2);
	return 0;
}