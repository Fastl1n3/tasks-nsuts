#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#define N 1000001
char* concat(char *pref, char *suff) {
	int len1 = strlen(pref), len2 = strlen(suff);
	int j = 0;
	for (int i = len1; i < len1 + len2; i++) {
		pref[i] = suff[j];
		j++;
	}
	return pref + len1 + len2;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	char s_new[101] = { 0 }, s[N] = { 0 };
	char* ss = s;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", s_new);
		ss = concat(ss, s_new);
	}
	printf("%s", s);
	return 0;
}