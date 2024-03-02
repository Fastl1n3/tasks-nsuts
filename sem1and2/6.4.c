#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#define N 1000
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int f;
	char s_main[N], s[N];
	scanf("%s", s_main);
	//len_main = strlen(s_main);
	while (scanf("%s", s) == 1) {
		//len_s = strlen(s);
		f = 0;
		for (int i = 0; s[i]; i++) {
			for (int j = 0; s_main[j]; j++) {
				if (s[i] == s_main[j]) {
					f++;
					break;
				}
			}
			if (f == 1)
				break;
		}
		if (f == 0)
			printf("%s\n", s);
	}
	printf("\n");
	return 0;
}