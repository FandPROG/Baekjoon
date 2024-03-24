#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int n, ans;
int par[55];
char map[55][55];

struct dat {
	int x, y, val;
};

bool compare(dat a, dat b)
{
	return a.val < b.val;
}

vector <dat> vec;

int ffind(int x)
{
	if (par[x] == x) return x;
	else return par[x] = ffind(par[x]);
}

void funion(int x, int y)
{
	int a = ffind(x), b = ffind(y);
	if (a < b) par[b] = a;
	else par[a] = b;
	return;
}

int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%s", map[i]);
	for (i = 1; i <= n; i++) par[i] = i;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (map[i][j] == '0') continue;
			int res;
			if ('a' <= map[i][j] && map[i][j] <= 'z') res = map[i][j] - 'a' + 1;
			else res = map[i][j] - 'A' + 27;
			vec.push_back({ i + 1, j + 1, res });
			ans += res;
		}
	}
	sort(vec.begin(), vec.end(), compare);
	for (i = 0; i < vec.size(); i++) {
		int x = vec[i].x, y = vec[i].y;
		int a = ffind(x), b = ffind(y);
		if (a == b) continue;
		funion(a, b);
		ans -= vec[i].val;
	}
	int check = 1;
	int che = par[1];
	for (i = 1; i <= n; i++) {
		if (che != par[ffind(i)]) check = 0;
	}
	if (check == 0) printf("-1");
	else printf("%d", ans);
	return 0;
}