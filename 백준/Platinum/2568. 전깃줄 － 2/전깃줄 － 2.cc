#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int n, p[100010];
vector <pair<int, int>> vec;
vector <int> lis, ans;

int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		vec.push_back({ x, y });
	}
	sort(vec.begin(), vec.end());
	lis.push_back(vec[0].second);
	for (i = 1; i < n; i++) {
		int l = lis.size();
		int lb = lower_bound(lis.begin(), lis.end(), vec[i].second) - lis.begin();
		if (lb >= l) {
			lis.push_back(vec[i].second);
			p[i] = l;
		}
		else {
			lis[lb] = vec[i].second;
			p[i] = lb;
		}
	}
	int l = lis.size() - 1;
	for (i = n - 1; i >= 0; i--) {
		if (l == p[i]) {
			l--;
			continue;
		}
		ans.push_back(vec[i].first);
	}
	printf("%d\n", n - lis.size());
	for (i = ans.size() - 1; i >= 0; i--) printf("%d\n", ans[i]);
	return 0;
}