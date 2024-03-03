#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int n, s, d;
int deep[100010];
int ans = 0;
vector <int> vec[100010];
bool ch1[100010], ch2[100010];

void ans_find(int x)
{
	int i;
	for (i = 0; i < vec[x].size(); i++) {
		int now = vec[x][i];
		if (ch2[now] == 0 && deep[now] > d) {
			ans++;
			ch2[now] = 1;
			ans_find(now);
			ch2[now] = 0;
		}
	}
	return;
}

int deep_find(int x)
{
	int i, dep = 0;
	for (i = 0; i < vec[x].size(); i++) {
		int now = vec[x][i];
		if (ch1[now] == 1) continue;
		ch1[now] = 1;
		dep = max(dep, deep_find(now));
	}
	return deep[x] = max(dep, deep[x]) + 1;
}

int main()
{
	int i, j;
	scanf("%d %d %d", &n, &s, &d);
	for (i = 0; i < n - 1; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
    ch1[s] = 1;
	deep_find(s);
    ch2[s] = 1;
	ans_find(s);
	printf("%d", ans * 2);
	return 0;
}