#include <stdio.h>

long long n;

int main()
{
	scanf("%lld", &n);
	if (n % 7 == 1 || n % 7 == 3) printf("CY");
	else printf("SK");
	return 0;
}
