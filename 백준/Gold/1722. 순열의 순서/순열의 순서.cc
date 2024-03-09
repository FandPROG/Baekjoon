#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

long long facto[25];
int n, k;
int ch[25];

int main()
{
	int i, j;
	scanf("%d %d", &n, &k);
	facto[0] = 1;
	for (i = 1; i <= n; i++) facto[i] = facto[i - 1] * i;
	if (k == 2) {
		long long ans = 0;
		vector <int> vec;
		for (i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			vec.push_back(x);
		}
		for (i = 0; i < vec.size() - 1; i++) {
			int idx = 0;
			for (j = 1; j <= n; j++) {
				if (ch[j] == 1) continue;
				if (j == vec[i]) break;
				idx++;
			}
			ch[vec[i]] = 1;
			ans += (idx) * facto[n - i - 1];
		}
		printf("%lld", ans + 1);
	}
	else if (k == 1) {
		long long num;
		scanf("%lld", &num);
		vector <int> ans;
		for (i = 1; i <= n; i++) {
			int idx = 0;
			vector<int> now;
			for (j = 1; j <= n; j++) {
				if (ch[j] == 0) now.push_back(j);
			}
			if (num <= facto[n - i]) idx = 0;
			else {
				while (1) {
					num -= facto[n - i];
					idx++;
					if (num <= facto[n - i]) break;
				}
			}
			ans.push_back(now[idx]);
			ch[now[idx]] = 1;
			now.clear();
		}
		for (i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
	}
	return 0;
}