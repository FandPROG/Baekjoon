#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, k;

struct dat {
	int m, v;
};

bool comp(dat a, dat b) {
	return a.m < b.m;
}

vector <dat> vec;
vector <int> bg;
priority_queue <dat> pq;

bool operator <(const dat& a, const dat& b) {
	return a.v < b.v;
}

int main()
{
	int i, j;
	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		vec.push_back({ x, y });
	}
	for (i = 0; i < k; i++) {
		int x;
		scanf("%d", &x);
		bg.push_back(x);
	}
	long long ans = 0;
	sort(vec.begin(), vec.end(), comp);
	sort(bg.begin(), bg.end());
	int cnt = 0;
	for (i = 0; i < k; i++) {
		while (1) {
			if (cnt >= vec.size()) break;
			dat nw = vec[cnt];
			if (nw.m > bg[i]) break;
			pq.push(nw);
			cnt++;
		}
		if (pq.empty()) continue;
		int nw = pq.top().v;
		pq.pop();
		ans += (long long)1 * nw;
	}
	printf("%lld", ans);
}