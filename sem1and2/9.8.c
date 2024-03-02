#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#define N 100000001
unsigned char s[N] = { 0 };
unsigned char d1[10][20] = { "desyat'", "odinnadtsat'", "dvenadtsat'", "trinadtsat'", "chetyrnadtsat'", "pyatnadtsat'", "shestnadtsat'", "semnadtsat'", "vosemnadtsat'", "devyatnadtsat'" };
unsigned char edin[9][10] = { "odna", "dve", "tri", "chetyre", "pyat'", "shest'", "sem'", "vosem'", "devyat'" };
unsigned char edin1_2[2][10] = { "odin", "dva" };
unsigned char dec[3][10] = { "dvadtsat'", "tridtsat'", "sorok" };
unsigned char st[4][20] = { "sto", "dvesti", "trista", "chetyresta" };
void strok_(unsigned char a, FILE *f2) {
	if (a > '1' && a < '5')
		fprintf(f2, "stroki\n");
	if ((a >= '5' && a < '10') || a == '0')
		fprintf(f2, "strok\n");
	if (a == '1')
		fprintf(f2, "stroka\n");
}
void tysyacha(unsigned char a, FILE* f2) {
	if (a > '1' && a < '5')
		fprintf(f2, "tysyachi ");
	if ((a >= '5' && a < '10') || a == '0')
		fprintf(f2, "tysyach ");
	if (a == '1')
		fprintf(f2, "tysyacha ");
}
void million(unsigned char a, FILE* f2) {
	if (a > '1' && a < '5')
		fprintf(f2, "milliona ");
	if ((a >= '5' && a < '10') || a == '0')
		fprintf(f2, "millionov ");
	if (a == '1')
		fprintf(f2, "million ");
}
void edinitsa(unsigned char a, unsigned char b,  FILE* f2) {
	if (b != '1')
		fprintf(f2, "%s ", edin[a - '0' - 1]);
}
void desyatki(unsigned char a, int b, FILE* f2) {
	if (a == '1')
		fprintf(f2, "%s ", d1[b - '0']);
	else {
		if (a == '9')
			fprintf(f2, "devyanosto ");
		else if (a > '4')
			fprintf(f2, "%sdesyat ", edin[a - '0' - 1]);
		else
			fprintf(f2, "%s ", dec[a - '0' - 2]);
	}
}
void sotnya(unsigned char a, int len, FILE *f2) {
	if (a <= '4')
		fprintf(f2, "%s ", st[a - '0' - 1]);
	else
		fprintf(f2, "%ssot ", edin[a - '0' - 1]);
}
int main() {
	
	FILE* f = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");
	int n, len;
	fscanf(f, "%d", &n);
	for (int i = 0; i < n; i++) {
		fscanf(f, "%s", s);
		//fprintf(f2, "%s ", s);
		len = strlen(s);
		if (len >= 9 && s[len - 9] != '0')
			sotnya(s[len - 9], len, f2);
		if (len >= 8 && s[len - 8] != '0')
			desyatki(s[len - 8], s[len - 7], f2);
		if (len >= 7 && s[len - 7] != '0') {
			if ((s[len - 7] == '1' || s[len - 7] == '2') && s[len - 8] != '1')
				fprintf(f2, "%s ", edin1_2[s[len - 7] - '0' - 1]);
			else
				edinitsa(s[len - 7], s[len - 8], f2);
		}
		if (len >= 8 && s[len - 8] == '1')
			fprintf(f2, "millionov ");
		else
			million(s[len - 7], f2);
		if (len >= 6 && s[len - 6] != '0')
			sotnya(s[len - 6], len, f2);
		if (len >= 5 && s[len - 5] != '0')
			desyatki(s[len - 5], s[len - 4], f2);
		if (len >= 4 && s[len - 4] != '0')
			edinitsa(s[len - 4], s[len - 5], f2);
		if (len >= 5 && s[len - 5] == '1')
			fprintf(f2, "tysyach ");
		else if (s[len - 4] - '0' + s[len - 5] - '0' + s[len - 6] - '0' != 0)
			tysyacha(s[len - 4], f2);
		if (len >= 3 && s[len - 3] != '0')
			sotnya(s[len - 3], len, f2);
		if (len >= 2 && s[len - 2] != '0')
			desyatki(s[len - 2], s[len - 1], f2);
		if (s[len - 1] != '0')
			edinitsa(s[len - 1], s[len - 2], f2);
		if (len >= 2 && s[len - 2] == '1')
			fprintf(f2, "strok\n");
		else
			strok_(s[len - 1], f2);
	}
	fprintf(f2, "\n");
	return 0;
}