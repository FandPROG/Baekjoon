#include <stdio.h>
#include <algorithm>

using namespace std;

long long n;
long long arr[500010];
long long ans;

int main()
{
	long long i, j;
	scanf("%lld", &n);
	for (i = 0; i < n; i++) scanf("%lld", &arr[i]);
	long long nw = 0;
	for (i = n - 1; i >= 0; i--) {
		nw = min(nw + 1, arr[i]);
		ans += nw;
	}
	printf("%lld", ans);
}