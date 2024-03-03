#include <stdio.h>
#include <algorithm>

using namespace std;

long long n, k;

long long pand(long long x)
{
	long long i, ans = 0;
	for (i = 1; i <= n; i++) ans += min(x / i, n);
	return ans;
}

int main()
{
	scanf("%lld %lld", &n, &k);
	long long low = 1, high = n * n;
	while (low <= high)
	{
		long long mid = (low + high) / 2;
		long long mid_res = pand(mid);
		if (mid_res < k) low = mid + 1;
		else high = mid - 1;
	}
	printf("%lld", high + 1);
	return 0;
}