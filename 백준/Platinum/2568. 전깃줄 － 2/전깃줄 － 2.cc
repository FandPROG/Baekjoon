#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector <pair<int, int>> vec;
vector <int> lis, way;
int p[1000010];

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
		if (lis.back() < vec[i].second) {
			lis.push_back(vec[i].second);
			p[i] = lis.size() - 1;
		}
		else {
			auto lb = lower_bound(lis.begin(), lis.end(), vec[i].second);
			*lb = vec[i].second;
			p[i] = lb - lis.begin();
		}
	}
	int cnt = lis.size();
	cnt--;

	for (int i = n - 1; i >= 0; i--) {
		if (p[i] == cnt) {
			cnt--;
			continue;
		}
		way.push_back(vec[i].first);
	}

	printf("%d\n", way.size());
	for (i = way.size() - 1; i >= 0; i--) printf("%d\n", way[i]);
	return 0;
}