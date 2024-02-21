#include <stdio.h>
#include <math.h>

int main()
{
	long long int x, y;
	scanf("%lld %lld", &x, &y);
	printf("%lld", abs(x - y));
	return 0;
}