#include <stdio.h>
#include <vector>

using namespace std;

long long n;
long long int ans = -2e15;
long long skill[200010], pt;
long long int ta[200010], tb[200010], gp[200010];
vector <long long> tree[200010];


void dfs(int N)
{
	ta[N] = skill[N];
	tb[N] = -2e15;
	long long int mx1 = -2e15, mx2 = -2e15;
	for (long long i : tree[N]) {
		dfs(i);
		if (ta[i] <= 0) tb[N] = max(tb[N], gp[i]);
		else {
			ta[N] += ta[i];
			tb[N] = max(tb[N], tb[i]);
		}
		if (mx1 < gp[i]) {
			mx2 = mx1;
			mx1 = gp[i];
		}
		else if (mx2 < gp[i]) mx2 = gp[i];
	}
	gp[N] = max(ta[N], mx1);
	ans = max(ans, ta[N] + tb[N]);
	ans = max(ans, mx1 + mx2);
}

int main()
{
	long long i, j;
	scanf("%lld", &n);
	scanf("%lld %lld", &skill[1], &pt);
	for (i = 2; i <= n; i++) {
		scanf("%lld %lld", &skill[i], &pt);
		tree[pt].push_back(i);
	}
	dfs(1);
	printf("%lld", ans);
	return 0;
}