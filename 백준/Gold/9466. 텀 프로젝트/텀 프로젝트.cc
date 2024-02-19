#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

int t, n;
int arr[100010];
bool ch[100010];
int check = 0;
vector <int> way;
bool ans[100010];

void dfs(int x)
{
	if (ch[x] == 1) {
		int st = 0;
		for (int i = 0; i < way.size(); i++) {
			if (way[i] == x) st = 1;
			if (st == 1) ans[way[i]] = 1;
		}
		return;
	}
	ch[x] = 1;
	way.push_back(x);
	dfs(arr[x]);
}

int main()
{
	int i, j; 
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (i = 1; i <= n; i++) scanf("%d", &arr[i]);
		for (i = 1; i <= n; i++) {
			if(ch[i] == 0) dfs(i);
			while (!way.empty()) way.pop_back();
		}
		int ans_cnt = 0;
		for (i = 1; i <= n; i++) {
			if (ans[i] == 1) ans_cnt++;
		}
		printf("%d\n", n - ans_cnt);
		for (i = 1; i <= n; i++) ch[i] = 0;
		for (i = 1; i <= n; i++) ans[i] = 0;
	}
	return 0;
}