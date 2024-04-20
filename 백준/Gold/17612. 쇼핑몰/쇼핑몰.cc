#include <stdio.h>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

struct shop
{
	long long int id, w, c, idx;
	bool operator < (const shop right) const{
		if (w == right.w) return c > right.c;
		else return w > right.w;
	}
}imsi;

long long int n, k;
priority_queue <shop> pq;
vector <pair<long long int, long long int>> input;
vector <shop> answ;

bool compare(shop a, shop b)
{
	if (a.w == b.w) return a.c > b.c;
	return a.idx < b.idx;
}

int main()
{
	long long int i, j;
	scanf("%lld %lld", &n, &k);
	for (i = 0; i < n; i++) {
		long long int a, b;
		scanf("%lld %lld", &a, &b);
		input.push_back({ a, b });
	}
	long long int cart = 1;
	long long int ans = 0, mct = 1;
	long long int enter_dis = 0, chch = 0;
	for (i = 0; i < n; i++) {
		imsi.id = input[i].first;
		imsi.w = input[i].second + enter_dis;
		imsi.c = cart++;
		pq.push(imsi);
		if (cart > k || chch == 1) {
			answ.push_back(pq.top());
			enter_dis = pq.top().w;
			cart = pq.top().c;
			pq.pop();
			chch = 1;
		}
	}
	while (!pq.empty())
	{
		answ.push_back(pq.top());
		pq.pop();
	}
	for (i = 0; i < (long long)answ.size(); i++) answ[i].idx = i;
	sort(answ.begin(), answ.end(), compare);
	for (i = 0; i < (long long)answ.size(); i++) {
		ans += (answ[i].id * mct);
//		printf("%lld * %lld = %lld\n", answ[i].id, mct, answ[i].id*mct);
		mct++;
	}
	printf("%lld", ans);
	return 0;
}