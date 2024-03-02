#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void reverse(int* x) {
	char* name = x;
	char m;
	m = name[0];
	name[0] = name[3];
	name[3] = m;
	m = name[1];
	name[1] = name[2];
	name[2] = m;
}
int main() {
	FILE* f1 = fopen("input.bin", "rb");
	FILE* f2 = fopen("output.bin", "wb");
	int f = 0, n, a, s = 0;
	fread(&n, sizeof(n), 1, f1);
	if (n > 10000 || n < 1) {
		reverse(&n);
		f = 1;
	}
	//printf("%d \n", n);
	for (int i = 0; i < n; i++) {
		fread(&a, sizeof(a), 1, f1);
		if (f == 1)
			reverse(&a);
		s += a;
		//printf("%d ", a);
	}
	//printf("=%d", s); 
	if (f == 1)
		reverse(&s);
	fwrite(&s, sizeof(s), 1, f2);
	fclose(f1);
	fclose(f2);
	return 0;
}