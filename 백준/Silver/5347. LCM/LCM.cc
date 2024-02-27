#include <stdio.h>

long long GCD(long long a, long long b)
{
	if (b == 0) return a;
	else return GCD(b, a % b);
}

int main()
{
	int i, j;
	int t;
	scanf("%d", &t);
	while (t--) {
		long long n, m;
		scanf("%lld %lld", &n, &m);
		long long gcd;
		if (n > m) gcd = GCD(n, m);
		else gcd = GCD(m, n);
		printf("%lld\n", n * m / gcd);
	}
	return 0;
}