#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

long long n;

struct dat
{
	long long idx, col, val;
};

bool comp(dat a, dat b)
{
	if (a.val == b.val) return a.col < b.col;
	return a.val < b.val;
}

long long sum_col[200010], sum_val[200010];
long long ans[200010];
vector<dat> vec;

int main()
{
	long long i, j;
	scanf("%lld", &n);
	for (i = 0; i < n; i++) {
		long long x, y;
		scanf("%lld %lld", &x, &y);
		vec.push_back({ i, x, y });
	}
	sort(vec.begin(), vec.end(), comp);
	long long sum = 0;
	for (i = 0; i < n; i++) {
		long long col = vec[i].col, val = vec[i].val;
		long long idx = vec[i].idx;
		sum += val;
		sum_col[col] += val;
		sum_val[val] += val;
		if (i > 0 && val == vec[i - 1].val && col == vec[i - 1].col) ans[idx] = ans[vec[i - 1].idx];
		else ans[idx] = sum - sum_col[col] - sum_val[val] + val;
	}
	for (i = 0; i < n; i++) printf("%lld\n", ans[i]);
	return 0;
}