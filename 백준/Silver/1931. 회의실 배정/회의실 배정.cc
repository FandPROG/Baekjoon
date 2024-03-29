#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector <pair<int, int>> vec;

int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		vec.push_back({ y, x });
	}
	sort(vec.begin(), vec.end());
	int ed = vec[0].first;
	int ans = 1;
	for (i = 1; i < n; i++) {
		if (ed <= vec[i].second) {
			ed = vec[i].first;
			ans++;
		}
	}
	printf("%d", ans);
	return 0;
}