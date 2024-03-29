#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int n, arr[1010][10];
int m[1010], check;
int vis[1010][9];
vector <int> ans;

void DFS(int x, int last_day)
{
	if (check == 1) return;
	int i, j;
	if (x >= n) {
		check = 1;
		for (i = 0; i < ans.size(); i++) printf("%d\n", ans[i]);
		return;
	}
	for (i = 0; i < m[x]; i++) {
		if (last_day == arr[x][i]) continue;
		if (vis[x][i] == 1) continue;
		vis[x][i] = 1;
		ans.push_back(arr[x][i]);
		DFS(x + 1, arr[x][i]);
		ans.pop_back();
	}
	return;
}

int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &m[i]);
		for (j = 0; j < m[i]; j++) scanf("%d", &arr[i][j]);
	}
	DFS(0, -1);
	if (check == 0) printf("-1");
	return 0;
}