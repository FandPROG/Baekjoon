#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

long long n, arr[100010];

long long func(int x) {
	long long i;
	long long res = 0;
	for (i = 1; i < n; i++) res += abs(x * i - arr[i]);
	return res;
}

int main() 
{
	long long i, j;
	scanf("%lld", &n);
	for (i = 0; i < n; i++) scanf("%lld", &arr[i]);
	int low = 0, high = arr[n - 1];
	while (high >= 3 + low) {
		int p = (low * 2 + high) / 3, q = (low + high * 2) / 3;
		if (func(p) <= func(q)) high = q;
		else low = p;
	}
	long long ans = 2e15;
	for (int i = low; i <= high; i++) ans = min(ans, func(i));
	printf("%lld", ans);
	return 0;
}