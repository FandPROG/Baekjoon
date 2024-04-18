#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int n, l, r, x;
int arr[20];
vector <int> ans;
int ch[20], res;

void dfs(int k, int st)
{
	int i, j;
	if (k >= 2) {
		int sum = 0, mx = -2e9, mn = 2e9;
		for (i = 0; i < ans.size(); i++) {
			//printf("%d ", ans[i]);
			sum += ans[i];
			mx = max(mx, ans[i]);
			mn = min(mn, ans[i]);
		}
		//printf("\n");
		if (l <= sum && sum <= r && mx - mn >= x) res++;
	}
	if (k >= n) return;
	for (i = st; i < n; i++) {
		if (ch[i] == 1) continue;
		ch[i] = 1;
		ans.push_back(arr[i]);
		dfs(k + 1, i + 1);
		ch[i] = 0;
		ans.pop_back();
	}
}

int main()
{
	int i, j;
	scanf("%d %d %d %d", &n, &l, &r, &x);
	for (i = 0; i < n; i++) scanf("%d", &arr[i]);
	dfs(0, 0);
	printf("%d", res);
	return 0;
}