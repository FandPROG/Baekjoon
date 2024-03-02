#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

long long n;
vector <pair<long long, long long>> vec;
long long ans[100010];

int main()
{
	long long i, j;
	scanf("%lld", &n);
	for (i = 0; i < n; i++) {
		long long x, y;
		scanf("%lld %lld", &x, &y);
		vec.push_back({ x, y });
	}
	sort(vec.begin(), vec.end());
	long long L = vec[0].second, use = 1;
	for (i = 1; i < n; i++) {
		L += use++ * (vec[i].first - vec[i - 1].first) + vec[i].second;
	}
	long long R = vec[n - 1].second;
	use = 1;
	for (i = n - 2; i >= 0; i--) {
		R += use++ * (vec[i + 1].first - vec[i].first) + vec[i].second;
	}
	ans[0] = min(L - (vec[0].second + vec[n - 1].first - vec[0].first), R - (vec[0].second + (n - 1) * (vec[1].first - vec[0].first)));
	ans[n - 1] = min(L - (vec[n - 1].second + (n - 1) * (vec[n - 1].first - vec[n - 2].first)), R - (vec[n - 1].second + (vec[n - 1].first - vec[0].first)));
	for (i = 1; i < n - 1; i++) {
		ans[i] = min(L - (vec[i].second + vec[n - 1].first - vec[i].first), R - (vec[i].second + vec[i].first - vec[0].first));
	}
	long long res = 2e19;
	for (i = 0; i < n; i++) {
		if (res > ans[i]) res = ans[i];
	}
	printf("%lld", res);
	return 0;
}