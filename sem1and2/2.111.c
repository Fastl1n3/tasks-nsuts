#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <limits.h>
long long D[200010] = { 0 };
typedef struct ent {
	int val1;
	int val2;
	int pos;
	int cost;
}Ent;
void qs(Ent mas[], int size)
{
	Ent swap;
	int i = 0;
	int j = size - 1;
	int mid = mas[size / 2].val1;
	do
	{
		while (mas[i].val1 < mid)
			i++;
		while (mas[j].val1 > mid)
			j--;
		if (i <= j)
		{
			swap = mas[i];
			mas[i] = mas[j];
			mas[j] = swap;
			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0)
		qs(mas, j + 1);
	if (i < size)
		qs(&mas[i], size - i);
}
void qs1(Ent mas[], int size)
{
	Ent swap;
	int i = 0;
	int j = size - 1;
	int mid = mas[size / 2].val2;
	do
	{
		while (mas[i].val2 < mid)
			i++;
		while (mas[j].val2 > mid)
			j--;
		if (i <= j)
		{
			swap = mas[i];
			mas[i] = mas[j];
			mas[j] = swap;
			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0)
		qs1(mas, j + 1);
	if (i < size)
		qs1(&mas[i], size - i);
}
typedef struct heap
{
	int size;
	int leng;
	int* arr;
}Heap;
Heap* create()
{
	Heap* h = (Heap*)malloc(sizeof(Heap));
	h->leng = 0;
	h->size = 1;
	h->arr = (int*)malloc(sizeof(int) * 1);
	return h;
}
int empty(Heap* h)
{
	return(h->leng == 0);
}
int parent(int i)
{
	return (i - 1) / 2;
}
int left(int i)
{
	return 2 * i + 1;
}
int right(int i)
{
	return 2 * i + 2;
}
void sift_up(Heap* h, int i)
{
	int a;
	if (i == 0)
		return;
	if (D[h->arr[i]] < D[h->arr[parent(i)]])
	{
		a = h->arr[i];
		h->arr[i] = h->arr[parent(i)];
		h->arr[parent(i)] = a;
		sift_up(h, parent(i));
	}
}
void sift_down(Heap* h, int i)
{
	int l, r, largest = -1, a;
	l = left(i);
	r = right(i);
	if (l <= h->leng - 1)
		if (D[h->arr[l]] < D[h->arr[i]])
			largest = l;
		else
			largest = i;
	if (r <= h->leng - 1)
		if (D[h->arr[r]] < D[h->arr[largest]])
			largest = r;
	if (largest != -1)
	{
		if (largest != i)
		{
			a = h->arr[i];
			h->arr[i] = h->arr[largest];
			h->arr[largest] = a;
			sift_down(h, largest);
		}
	}
}
void push(Heap* h, int a)
{
	if (h->leng == h->size)
	{
		h->arr = (int*)realloc(h->arr, sizeof(int) * (h->size + 10));
		h->size += 10;
	}
	h->arr[h->leng++] = a;
	int b = h->leng - 1;
	sift_up(h, b);
}
int pop(Heap* h)
{
	int a = h->arr[0];
	h->arr[0] = h->arr[--h->leng];
	sift_down(h, 0);
	return a;
}
typedef struct node {
	struct node* next;
	int val;
	int cost;
}Node;
Node* arr[200010] = { NULL };
int MIN(int a, int b) {
	return a < b ? a : b;
}
int MAX(int a, int b) {
	a > b ? a : b;
}
int S[200010] = { 0 };
int Par[200010] = { 0 };
Ent out[200010] = { 0 };
void Dey(int N, int v0, int vend) {
	Heap* h = create();
	for (int i = 0; i < N; i++) {
		D[i] = 0;
		S[i] = 0;
		D[i] = INT_MAX;
		Par[i] = 0;
	}
	S[v0] = 1;
	D[v0] = 0;
	Par[v0] = -1;
	int z = 1;
	Node* p = arr[v0];
	while (p != NULL) {
		if (p->cost < D[p->val])
			D[p->val] = p->cost;
		push(h, p->val);
		Par[p->val] = v0 + 1;
		p = p->next;
	}
	while (1) {
		int pos = pop(h);
		if (pos == vend) {
			free(h->arr);
			free(h);
			return;
		}
		if (pos<0 || pos>N) {
			free(h->arr);
			free(h);
			return;
		}
		if (pos >= 0 && pos < N)
			S[pos] = 1;
		z++;
		if (pos != -1) {
			Node* t = arr[pos];
			while (t != NULL) {
				if (S[t->val] == 0)
					if (D[t->val] == INT_MAX) {
						D[t->val] = D[pos] + t->cost;
						Par[t->val] = pos + 1;
						push(h, t->val);

					}
					else {
						int cmp = D[t->val];
						D[t->val] = MIN(D[t->val], D[pos] + t->cost);
						if (cmp > D[t->val])
							Par[t->val] = pos + 1;
						int l = 0;
						while (h->arr[l] != t->val)
							l++;
						sift_up(h, l);
					}
				t = t->next;
			}
		}
	}
	free(h->arr);
	free(h);
}
int ans[200010] = { 0 };
int Ans1[200010] = { 0 };
int main() {
	int t1 = time(NULL);
	Node* p;
	int N = 0, M = 0, K = 0, a = 0, b = 0, c = 0, cnt1 = 0;
	int goal[2][22] = { 0 };
	//int N, S1, S2, a, b, c;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i < K; i++)
		scanf("%d%d", &goal[0][i], &goal[1][i]);
	for (int i = 0; i < M; i++) {
		(scanf("%d%d%d", &a, &b, &c) == 3);
		out[cnt1].val1 = a;
		out[cnt1].val2 = b;
		out[cnt1].pos = cnt1;
		out[cnt1].cost = c;
		cnt1++;
		if (a == b)
			continue;
		p = (Node*)malloc(sizeof(Node));
		p->val = b - 1;
		p->cost = c;
		p->next = arr[a - 1];
		arr[a - 1] = p;
	}
	qs(out, cnt1);
	int k = 0;
	int k1 = k;
	while (k < M) {
		b = 0;
		a = out[k].val1;
		k1 = k;
		while (out[k].val1 == a) {
			k++;
			b++;
		}
		qs1(&out[k1], b);
	}
	for (int i = 0; i < K; i++) {
		int cnt = 0;
		Dey(N, goal[0][i] - 1, goal[1][i] - 1);
		if (D[goal[1][i] - 1] == INT_MAX)
			printf("DOOMED\n");
		else {
			// for(int i = 0;i<N;i++)
			// printf("%d ", Par[i]);
			printf("quarantine %lld ", D[goal[1][i] - 1]);
			int k = goal[1][i];
			int kol = 0;
			while (k != -1) {
				Ans1[kol++] = k;
				k = Par[k - 1];
			}
			printf("%d ", kol - 1);
			// for (int i = kol - 1; i >= 0; i--)
			// printf("%d ", Ans1[i]);
			for (int i = 0; i < kol - 1; i++) {
				int mal = Ans1[kol - 1 - i];
				int mn = Ans1[kol - 2 - i];
				// printf("~%d %d~ ", mal, mn);
				int l = 0;
				int r = cnt1;
				int mid = (l + r) / 2;
				while (out[mid].val1 != mal && r - l > 1) {
					if (out[mid].val1 > mal) {
						r = mid;
						mid = (l + r) / 2;
					}
					else {
						l = mid;
						mid = (r + l) / 2;
					}
				}
				// printf("-%d -", out[mid].val1);
				if (mn == out[mid].val2) {
					int mm = INT_MAX;
					int ps;
					int ct = mid;
					while (out[ct].val1 == out[mid].val1 && out[ct].val2 == out[mid].val2) {
						if (out[ct].cost < mm) {
							mm = out[ct].cost;
							ps = ct;
						}
						ct++;
					}
					ct = mid;
					while (out[ct].val1 == out[mid].val1 && out[ct].val2 == out[mid].val2) {
						if (out[ct].cost < mm) {
							mm = out[ct].cost;
							ps = ct;
						}
						ct--;
					}
					ans[cnt++] = out[ps].pos;
				}
				else
					if (out[mid].val2 > mn) {
						while (out[mid].val2 > mn)
							mid--;
						int mm = INT_MAX;
						int ps;
						int ct = mid;
						while (out[ct].val1 == out[mid].val1 && out[ct].val2 == out[mid].val2) {
							if (out[ct].cost < mm) {
								mm = out[ct].cost;
								ps = ct;
							}
							ct--;
						}
						ans[cnt++] = out[ps].pos;
					}
					else
						if (out[mid].val2 < mn) {
							while (out[mid].val2 < mn)
								mid++;
							int mm = INT_MAX;
							int ps;
							int ct = mid;
							while (out[ct].val1 == out[mid].val1 && out[ct].val2 == out[mid].val2) {
								if (out[ct].cost < mm) {
									mm = out[ct].cost;
									ps = ct;
								}
								ct++;
							}
							ans[cnt++] = out[ps].pos;
						}
			}
			for (int i = 0; i < kol - 1; i++)
				printf("%d ", ans[i] + 1);
			printf("\n");
		}
	}
	printf("%d ", time(NULL) - t1);
	return 0;
}