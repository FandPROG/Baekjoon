#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n;
int ent[1000010];
vector <int> vec[1000010];
int ans[1000010], num = 1;

int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 1; j <= n - 1; j++) {
			int n1 = (n * i) + j;
			int n2 = n1 + 1;
			char c;
			scanf(" %c", &c);
			if (c == '>') vec[n2].push_back(n1), ent[n1]++;
			else if (c == '<') vec[n1].push_back(n2), ent[n2]++;
		}
	}
	for (i = 0; i < n - 1; i++) {
		for (j = 1; j <= n; j++) {
			int n1 = (n * i) + j;
			int n2 = n1 + n;
			char c;
			scanf(" %c", &c);
			if (c == '>') vec[n2].push_back(n1), ent[n1]++;
			else if (c == '<') vec[n1].push_back(n2), ent[n2]++;
		}
	}
	queue <int> q;
	for (i = 1; i <= n * n; i++) {
		if (ent[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int nw = q.front();
		ans[nw] = num++;
		q.pop();
		for (i = 0; i < vec[nw].size(); i++) {
			int now = vec[nw][i];
			ent[now]--;
			if (ent[now] == 0) {
				q.push(now);
			}
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 1; j <= n; j++) {
			printf("%d ", ans[(i * n) + j]);
		}
		printf("\n");
	}
	return 0;
}