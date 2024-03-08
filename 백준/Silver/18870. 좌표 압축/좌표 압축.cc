#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector <pair<int, int>> vec;
int ans[1000010];

int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		vec.push_back({ x, i });
	}
	sort(vec.begin(), vec.end());
	int idx = 0;
	for (i = 0; i < n; i++) {
		ans[vec[i].second] = idx++;
		if (i < n - 1 && vec[i].first == vec[i + 1].first) idx--;
	}
	for (i = 0; i < n; i++) printf("%d ", ans[i]);
	return 0;
}