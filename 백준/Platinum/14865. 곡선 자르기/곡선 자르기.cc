#include <stdio.h>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<pair<int, int>> vec;
stack <int> st, sta;
int sx[1000010], sy[1000010];

int main()
{
	int i, j;
	scanf("%d", &n);
	int now = 0;
	int str_spot = 2e9, strt;
	for (i = 0; i < n; i++) {
		scanf("%d %d", &sx[i], &sy[i]);
		if (sy[i] <= str_spot) strt = i, str_spot = sy[i];
	}
	for (i = 0; i < n; i++) {
		int x = sx[strt], y = sy[strt];
		if (now == -1 && y > 0) {
			if (st.size() == 0) st.push(x);
			else {
				int nx = st.top();
				int mnx = min(nx, x);
				int mxx = max(nx, x);
				vec.push_back({ mnx, mxx });
				st.pop();
			}
		}
		else if (now == 1 && y < 0) {
			if (st.size() == 0) st.push(x);
			else {
				int nx = st.top();
				int mnx = min(nx, x);
				int mxx = max(nx, x);
				vec.push_back({ mnx, mxx });
				st.pop();
			}
		}
		if (y > 0) now = 1;
		else now = -1;
		strt++;
		strt %= n;
	}
	sort(vec.begin(), vec.end());
	int ans_1 = 1, ans_2 = 0;
	int st = vec[0].first, ed = vec[0].second;
	for (i = 1; i < vec.size(); i++) {
		if (ed < vec[i].first) {
			ans_1++;
			st = vec[i].first;
			ed = vec[i].second;
		}
	}
	vector <pair<int, int>> as;
	for (i = 0; i < vec.size(); i++) {
		as.push_back({ vec[i].first, 1 });
		as.push_back({ vec[i].second, 2 });
	}
	sort(as.begin(), as.end());
	for (i = 0; i < as.size() - 1; i++) {
		if (as[i].second == 1 && as[i + 1].second == 2) ans_2++;
	}
	printf("%d %d", ans_1, ans_2);
	return 0;
}