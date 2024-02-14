#include <stdio.h>

long long n, l;

int main()
{
	long long i, j;
	scanf("%lld %lld", &n, &l);
	while (1) {
		long long con = 0, beg = 0;
		for (i = 1; i < l; i++) con += i;
		beg = (n - con) / l;
		if ((n - con) % l == 0 && beg >= 0) {
			for (i = 0; i < l; i++) {
				printf("%d ", beg + i);
			}
			return 0;
		}
		else {
			if (l == 100) {
				printf("-1");
				return 0;
			}
			else {
				l++;
			}
		}
	}
	return 0;
}