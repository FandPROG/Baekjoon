#include <stdio.h>
#include <math.h>

int n;

int main()
{
	scanf("%d", &n);
	long long res = 1 + pow(2, n);
	printf("%lld", res * res);
	return 0;
}