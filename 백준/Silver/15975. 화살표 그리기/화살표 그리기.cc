#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector <int> vec[100010];

int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		vec[y].push_back(x);
	}
	long long ans = 0;
	for (i = 1; i <= n; i++) {
		if (vec[i].size() == 0) continue;
		sort(vec[i].begin(), vec[i].end());
		for (j = 0; j < vec[i].size(); j++) {
			int res = 2e9;
			if (j > 0 && res > vec[i][j] - vec[i][j - 1]) res = vec[i][j] - vec[i][j - 1];
			if (j < vec[i].size() - 1 && res > vec[i][j + 1] - vec[i][j]) res = vec[i][j + 1] - vec[i][j];
			if (res != 2e9) ans += res;
		}
	}
	printf("%lld", ans);
}