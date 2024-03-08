#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector <pair<int, int>> vec[110];
int small[110][10010];

int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			int x;
			scanf("%d", &x);
			vec[i].push_back({x, j});
		}
		sort(vec[i].begin(), vec[i].end());
		int idx = 0;
		for (j = 0; j < m; j++) {
			small[i][vec[i][j].second] = idx++;
			if (j < m - 1 && vec[i][j].first == vec[i][j + 1].first) idx--;
		}
	}
	int ans = 0;
	for (i = 0; i < n - 1; i++) {
		int ch;
		for (j = i + 1; j < n; j++) {
			ch = 1;
			for (int k = 0; k < m; k++) {
				if (small[i][k] != small[j][k]) ch = 0;
			}
			if (ch == 1) ans++;
		}
	}
	printf("%d", ans);
}