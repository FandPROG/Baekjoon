#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

long long n;
long long sum, L, R;
vector <pair<long long, long long>> vec;
long long ans = 2e19;
long long ans_idx;

int main()
{
	long long i, j;
	scanf("%lld", &n);
	for (i = 0; i < n; i++) {
		long long x, y;
		scanf("%lld %lld", &x, &y);
		vec.push_back({ x, y });
		sum += y;
	}
	sort(vec.begin(), vec.end());
	for (i = 0; i < n; i++) {
		R = sum - L - vec[i].second;
		long long res = abs(R - L);
		if (res < ans) ans = res, ans_idx = i;
		L += vec[i].second;
	}
	ans_idx = vec[ans_idx].first;
	printf("%lld", ans_idx);
	return 0;
}