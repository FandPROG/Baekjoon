#include <stdio.h>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

long long n;
map <long long, long long> mp;

int main()
{
	int i, j;
	scanf("%lld", &n);
	queue <pair<long long, long long>> q;
	q.push({ 0, n });
	mp.insert({ 0, n });
	while (!q.empty()) {
		long long nw = q.front().second;
		long long dis = q.front().first;
		if (nw == 1) {
			printf("%lld", dis);
			return 0;
		}
		q.pop();
		if (nw % 3 == 0) {
			if (mp.find(nw / 3) == mp.end()) {
				mp.insert({ nw / 3, dis + 1 });
				q.push({ dis + 1, nw / 3 });
			}
		}
		if (nw % 2 == 0) {
			if (mp.find(nw / 2) == mp.end()) {
				mp.insert({ nw / 2, dis + 1 });
				q.push({ dis + 1, nw / 2 });
			}
		}
		if (mp.find(nw - 1) == mp.end()) {
			mp.insert({ nw - 1, dis + 1 });
			q.push({ dis + 1, nw - 1 });
		}
	}
	return 0;
}