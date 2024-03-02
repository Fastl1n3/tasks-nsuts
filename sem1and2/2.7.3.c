#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
int flag1 = 0, flag2 = 0;
typedef struct node {
	int value;
	int height;
	struct node* left;
	struct node* right;
} Tree;
int height(Tree* t) {
	return t ? t->height : 0;
}
int bfactor(Tree* t) {
	return height(t->right) - height(t->left);
}
void fixheight(Tree* t) {
	if (t != NULL) {
		int hl = height(t->left);
		int hr = height(t->right);
		t->height = (hl > hr ? hl : hr) + 1;
	}
}
Tree* pov_right(Tree* t) {
	Tree* q = t->left;
	t->left = q->right;
	q->right = t;
	fixheight(t);
	fixheight(q);
	return q;
}
Tree* pov_left(Tree* t) {
	Tree* q = t->right;
	t->right = q->left;
	q->left = t;
	fixheight(t);
	fixheight(q);
	return q;
}
Tree* balance(Tree* t) {
	fixheight(t);
	if (bfactor(t) == 2) {
		if (bfactor(t->right) < 0)
			t->right = pov_right(t->right);
		return pov_left(t);
	}
	if (bfactor(t) == -2) {
		if (bfactor(t->left) > 0)
			t->left = pov_left(t->left);
		return pov_right(t);
	}
	return t;
}
Tree* add(Tree* t, int val) {
	if (t == NULL) {
		t = (Tree*)malloc(sizeof(Tree));
		t->value = val;
		t->left = NULL;
		t->right = NULL;
		t->height = 1;
		flag1 = 0;
		return t;
	}
	if (val < t->value) 
		t->left = add(t->left, val);
	if (val > t->value)
		t->right = add(t->right, val);
	if (val == t->value)
		flag1 = 1;
	return balance(t);
}
Tree* find_min(Tree* t) {
	return t->left ? find_min(t->left) : t;
}
Tree* remove_min(Tree* t) {
	if (t->left == NULL)
		return t->right;
	t->left = remove_min(t->left);
	return balance(t);
}
Tree* Remove(Tree* t, int val) {
	if (t == NULL) {
		flag2 = 1;
		return NULL;
	}
	if (val < t->value)
		t->left = Remove(t->left, val);
	if (val > t->value)
		t->right = Remove(t->right, val);
	if (val == t->value) {
		flag2 = 0;
		Tree* l = t->left;
		Tree* r = t->right;
		free(t);
		if (r == NULL)
			return l;
		Tree* min = find_min(r);
		min->right = remove_min(r);
		min->left = l;
		return balance(min);
	}
	return balance(t);
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
	Tree* tree = NULL;
	fscanf(f1, "%d", &n);
	for (int i = 0; i < n; i++) {
		fscanf(f1, "%s %d", oper, &a);
		if (oper[0] == 'a') {
			tree = add(tree, a);
			if (flag1 == 0)
				fprintf(f2, "added\n");
			else
				fprintf(f2, "dupe\n");
		}
		if (oper[0] == 'r') {
			tree = Remove(tree, a);
			if (flag2 == 0) {
				fprintf(f2, "removed\n");
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