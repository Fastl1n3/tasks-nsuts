#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#define N 1001
int invtab_to_permut(int B[], int A[], int n) {
	int kolvo_inv, k, g;
	for (int i = 0; i < n; i++) {
		kolvo_inv = B[i];
		k = 0;
		for (int j = 0; j < n; j++) {
			if (A[j] == 0)
				k += 1;
			if (k == kolvo_inv || kolvo_inv == 0) {
				if (A[0] == 0 && kolvo_inv == 0) {
					A[0] = i + 1;
					break;
				}
				g = j;
				while (A[g + 1] != 0)
					g++;
				A[g + 1] = i + 1;
				break;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (A[i] == 0)
			return 0;
	}
	return 1;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, A[N] = {0}, B[N];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &B[i]);
	}
	if (invtab_to_permut(B, A, n) == 1) {
		for (int i = 0; i < n; i++) {
			printf("%d ", A[i]);
		}
	}
	else
		printf("NO");
	return 0;
}