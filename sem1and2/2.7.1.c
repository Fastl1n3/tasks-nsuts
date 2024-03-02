#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define N 500001
int A[N] = { 0 };
typedef struct node {
	int value;
	int count;
	struct node* left;
	struct node* right;
} Tree;
Tree* add(Tree* t, int val) {
	if (t == NULL) {
		t = (Tree*)malloc(sizeof(Tree));
		t->value = val;
		t->count = 1;
		t->left = NULL;
		t->right = NULL;
		return t;
	}
	if (val < t->value)
		t->left = add(t->left, val);
	if (val > t->value)
		t->right = add(t->right, val);
	if (val == t->value)
		t->count++;
	return t;
}
void pr(FILE* f, Tree* t) {
	if (t == NULL)
		return;
	pr(f, t->left);;
	for (int i = 0; i < t->count; i++) {
		fwrite(&t->value, sizeof(int), 1, f);
	}
	pr(f, t->right);
}
void shuffle(int* arr, int n) {
	srand(time(NULL));
	for (int i = n - 1; i >= 1; i--) {
		int j = rand() % (i + 1);
		int tmp = arr[j];
		arr[j] = arr[i];
		arr[i] = tmp;
	}
}
int main() {
	FILE* f1 = fopen("input.bin", "rb");
	int n, a;
	fread(&n, sizeof(int), 1, f1);
	if (n == 0) {
		return 0;
	}
	FILE* f2 = fopen("output.bin", "wb");
	for (int i = 0; i < n; i++) {
		fread(&A[i], sizeof(int), 1, f1);
	}
	shuffle(A, n);
	Tree* tree = (Tree*)malloc(sizeof(Tree));
	tree->value = A[0];
	tree->count = 1;
	tree->left = NULL;
	tree->right = NULL;
	for (int i = 1; i < n; i++) {
		tree = add(tree, A[i]);
	}
	pr(f2, tree);
 	fclose(f1);
	//fclose(f2);
	return 0;
}