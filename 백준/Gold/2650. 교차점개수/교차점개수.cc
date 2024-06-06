#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int arr[55];
vector <pair<int, int>> vec[5];
int ord[5] = { 3, 1, 4, 2 };
int ch[55];
int check[55];

int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n / 2; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		vec[x].push_back({ y, i });
		scanf("%d %d", &x, &y);
		vec[x].push_back({ y, i });
	}
	for (i = 1; i <= 4; i++) sort(vec[i].begin(), vec[i].end());
	reverse(vec[3].begin(), vec[3].end());
	reverse(vec[2].begin(), vec[2].end());
	int cnt = 0;
	for (i = 0; i < 4; i++) {
		int k = ord[i];
		for (j = 0; j < vec[k].size(); j++) arr[cnt++] = vec[k][j].second;
	}
	int ans = 0, mx = -2e9;
	for (i = 0; i < cnt; i++) {
		int nw = arr[i];
		if (check[nw] == 1) continue;
		check[nw] = 1;
		for (j = i + 1;; j++) {
			if (nw == arr[j]) break;
			else {
				ch[arr[j]]++;
			}
		}
		int res = 0;
		for (j = 1; j <= 50; j++) {
			if (ch[j] == 1) res++;
			ch[j] = 0;
		}
		mx = max(res, mx);
		ans += res;
	}
	printf("%d\n%d", ans / 2, mx);
	return 0;
}