#include <stdio.h>
#include <algorithm>

using namespace std;

long long n, m;
long long arr[100010];

long long pand(long long x)
{
	long long i, ans = 0;
	long long s = 0;
	for (i = 0; i < n; i++) {
		if (s + arr[i] > x) {
			ans++;
			s = arr[i];
		}
		else s += arr[i];
	}
	return ans;
}

int main()
{
	long long i, j;
	scanf("%lld %lld", &n, &m);
	long long low = -2e9, high = 0;
	for (i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
		high += arr[i];
		if (low < arr[i]) low = arr[i];
	}
	while (low <= high)
	{
		long long mid = (low + high) / 2;
		long long mid_res = pand(mid);
		if (mid_res < m) high = mid - 1;
		else low = mid + 1;
	}
	printf("%lld", low);
	return 0;
}