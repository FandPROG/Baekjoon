#include <stdio.h>
#include <algorithm>

using namespace std;

long long n, arr[1000010];

long long int right(long long int x)
{
	long long int cnt = 0, ans = 0;
	long long int i;
	for (i = 0; i < n; i++) {
		if (arr[i] == x) {
			ans += i - cnt;
			cnt++;
		}
	}
	return ans;
}

long long int left(long long int x)
{
	long long int cnt = 0, ans = 0;
	long long int i;
	for (i = n - 1; i >= 0; i--) {
		if (arr[i] == x) {
			ans += (n - 1 - i) - cnt;
			cnt++;
		}
	}
	return ans;
}

int main()
{
	long long int i, j;
	scanf("%lld", &n);
	for (i = 0; i < n; i++) {
		long long int x;
		scanf("%lld", &x);
		arr[i] = x % 2;
	}
	long long int r1 = right(1), l1 = left(1);
	long long int r0 = right(0), l0 = left(0);
	printf("%lld", min(r1, min(l1, min(r0, l0))));
	return 0;
}