#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

long long n, par[1010];

struct dat
{
	long long x, y, dis;
};

bool comp(dat x, dat y)
{
	return x.dis < y.dis;
}

vector <dat> vec;
long long res;

long long ffind(long long x)
{
	if (x == par[x]) return x;
	else return par[x] = ffind(par[x]);
}

void funion(long long x, long long y)
{
	long long a = ffind(x), b = ffind(y);
	if (a < b) par[b] = a;
	else par[a] = b;
	return;
}

int main()
{
	int i, j;
	scanf("%lld", &n);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			long long x;
			scanf("%lld", &x);
			if (i == j) continue;
			if (i < j) {
				vec.push_back({ i, j, x });
			}
		}
	}
	for (i = 1; i <= n; i++) par[i] = i;
	sort(vec.begin(), vec.end(), comp);
	for (i = 0; i < vec.size(); i++) {
		long long a = vec[i].x, b = vec[i].y;
		if (ffind(a) == ffind(b)) continue;
		funion(a, b);
		res += vec[i].dis;
	}
	printf("%lld", res);
	return 0;
}