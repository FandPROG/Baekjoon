#include <stdio.h>

long long n;

int main()
{
	scanf("%lld", &n);
	if (n % 7 == 0 || n % 7 == 2) printf("CY");
	else printf("SK");
	return 0;
}
