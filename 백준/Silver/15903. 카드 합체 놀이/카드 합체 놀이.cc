#include <stdio.h>
#include <algorithm>

using namespace std;

long long n, m;
long long arr[1010];

int main()
{
	long long i, j;
	scanf("%lld %lld", &n, &m);
	for (i = 0; i < n; i++) scanf("%lld", &arr[i]);
	for (i = 0; i < m; i++) {
		sort(arr, arr + n);
		long long x = arr[0] + arr[1];
		arr[0] = x;
		arr[1] = x;
	}
	long long ans = 0;
	for (i = 0; i < n; i++) ans += arr[i];
	printf("%lld", ans);
	return 0;
}