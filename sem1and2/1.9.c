#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <math.h>
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m, p, k, l, kvartonfloor, pod, floor, b, kvartinpod;
	scanf("%d\n %d %d %d %d", &n, &m, &p, &k, &l);
	if (m % (l * (p - 1) + k) != 0) kvartonfloor = m / (l * (p - 1) + k) + 1;
	else kvartonfloor = m / (l * (p - 1) + k);
	//printf("%d\n", kvartonfloor);
	kvartinpod = kvartonfloor * l;
	//printf("%d\n", kvartinpod);
	if (n % kvartinpod != 0) pod = n / kvartinpod + 1;
	else pod = n / kvartinpod;
	if (n % kvartinpod != 0) {
		if (n % kvartinpod % kvartonfloor != 0) floor = n % kvartinpod / kvartonfloor + 1;
		else floor = n % kvartinpod / kvartonfloor;
	}
	else floor = l;
	printf("%d %d", pod, floor);
	return 0;
}

