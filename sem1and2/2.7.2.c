#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
int f = 0;
typedef struct node {
	int value;
	struct node* parent;
	struct node* left;
	struct node* right;
} Tree;
Tree* add(Tree* t, int val) {
	if (val < t->value) {
		if (t->left == NULL) {
			t->left = (Tree*)malloc(sizeof(Tree));
			t->left->value = val;
			t->left->parent = t;
			t->left->left = NULL;
			t->left->right = NULL;
			f = 0;
			return t;
		}
		else
			t->left = add(t->left, val);
	}
	if (val > t->value) {
		if (t->right == NULL) {
			t->right = (Tree*)malloc(sizeof(Tree));
			t->right->value = val;
			t->right->parent = t;
			t->right->left = NULL;
			t->right->right = NULL;
			f = 0;
			return t;
		}
		else
			t->right = add(t->right, val);
	}
	if (val == t->value)
		f = 1;
	return t;
}
Tree* Remove(Tree* t, int val) {
	Tree* y = t;
	if (t == NULL)
		return 0;
	if (val > t->value)
		Remove(t->right, val);
	if (val < t->value)
		Remove(t->left, val);
	if (val == t->value) {
		if (t->left == NULL && t->right == NULL) {
			Tree* clear = t;
			if (t->parent != NULL) {
				if (t->parent->left == t)
					t->parent->left = NULL;
				else
					t->parent->right = NULL;
			}
			else {
				t->value = INT_MIN;
				return t;
			}
			free(clear);
			return 1;
		}
		if (t->left == NULL && t->right != NULL) {
			Tree* clear = t;
			t->right->parent = t->parent;
			if (t->parent != NULL) {
				if (t->parent->left == t)
					t->parent->left = t->right;
				else
					t->parent->right = t->right;
			}
			else {
				t = t->right;
				return t;
			}
			free(clear);
			return 1;
		}
		if (t->left != NULL && t->right == NULL) {
			Tree* clear = t;
			t->left->parent = t->parent;
			if (t->parent != NULL) {
				if (t->parent->left == t)
					t->parent->left = t->left;
				else
					t->parent->right = t->left;
			}
			else {
				t = t->left;
				return t;
			}
			free(clear);
			return 1;
		}
		if (t->left != NULL && t->right != NULL) {
			if (t->right->left == NULL) {
				t->value = t->right->value;
				if (t->right->right != NULL)
					t->right->right->parent = t;
				t->right = t->right->right;
				return 1;
			}
			else {
				t = Down(t);
				return 1;
			}
		}
	}
	return y;
}
int Down(Tree* t) {
	Tree* p = t->right;
	Tree* m = 0;
	while (p != NULL) {
		m = p;
		p = p->left;
	}
	Tree* clear = m;
	t->value = m->value;
	if (m->right != NULL)
		m->right->parent = m->parent;
	m->parent->left = m->right;
	free(clear);
	return t;
}
int lower(Tree* t, int val) {
	int y;
	if (t == NULL)
		return INT_MIN;
	if (t->value < val)
		y = lower(t->right, val);
	if (t->value == val)
		return val;
	if (t->value > val) {
		if (t->left == NULL) {
			y = t->value;
			return y;
		}
		else {
			y = lower(t->left, val);
			if (y == INT_MIN)
				y = lower(t->right, val);
		}
		if (t->value < y || y == INT_MIN)
			y = t->value;
	}
	return y;
}
int main() {
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	int n, a;
	char oper[10];
	Tree* tree = (Tree*)malloc(sizeof(Tree));
	tree->value = INT_MIN;
	tree->parent = NULL;
	tree->left = NULL;
	tree->right = NULL;
	fscanf(f1, "%d", &n);
	for (int i = 0; i < n; i++) {
		fscanf(f1, "%s %d", oper, &a);
		if (oper[0] == 'a') {
			if (tree->value == INT_MIN) {
				tree->value = a;
			}
			else
				tree = add(tree, a);
			if (f == 0)
				fprintf(f2, "added\n");
			else
				fprintf(f2, "dupe\n");
		}
		if (oper[0] == 'r') {
			Tree* ans = Remove(tree, a);
			if (ans != 0) {
				fprintf(f2, "removed\n");
			//	if (ans != 1)
					tree = ans;
			}
			else
				fprintf(f2, "miss\n");
		}
		if (oper[0] == 'l') {
			int ans = lower(tree, a);
			if (ans == INT_MIN)
				fprintf(f2, "###\n");
			else
				fprintf(f2, "%d\n", ans);
		}
	}
	fclose(f1);
	fclose(f2);
	return 0;
}