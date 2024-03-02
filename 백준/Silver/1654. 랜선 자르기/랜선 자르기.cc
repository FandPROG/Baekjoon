#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

long long n, k;
vector <long long> vec;

long long pand(long long x)
{
	long long i, j;
	long long ans = 0;
	for (i = 0; i < n; i++) {
		if (vec[i] >= x) ans += (vec[i] / x);
	}
	return ans;
}

int main()
{
	long long i, j;
	scanf("%lld %lld", &n, &k);
	long long mx = -2e9;
	for (i = 0; i < n; i++) {
		long long x;
		scanf("%lld", &x);
		vec.push_back(x);
		if (mx < x) mx = x;
	}
	long long low = 1, high = mx;
	while (low <= high)
	{
		long long mid = (low + high) / 2;
		long long mid_res = pand(mid);
		if (mid_res >= k) low = mid + 1;
		else high = mid - 1;
	}
	printf("%lld", high);
	return 0;
}