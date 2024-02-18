#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int i, j;
	int t;
	scanf("%d", &t);
	int cnt = 1;
	while (t--) {
		int n, x;
		scanf("%d %d", &n, &x);
		vector <pair<int, int>> q;
		for (i = 0; i < n; i++) {
			int a;
			scanf("%d", &a);
			q.push_back({ a, i + 1 });
		}
		printf("Case #%d: ", cnt);
		for (i = 0; i < n; i++) {
			q[i].first = (q[i].first + x - 1) / x;
		}
		sort(q.begin(), q.end());
		for (i = 0; i < n; i++) {
			if (q[i].first == 2e9) continue;
			else {
				printf("%d ", q[i].second);
			}
		}
		printf("\n");
		cnt++;
	}
	return 0;
}