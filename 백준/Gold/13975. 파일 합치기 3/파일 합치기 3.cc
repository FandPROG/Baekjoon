#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int i, n;
		scanf("%d", &n);
		priority_queue<long long> pq;
		for (i = 0; i < n; i++) {
			long long x;
			scanf("%lld", &x);
			pq.push(-x);
		}
		long long res = 0;
		while (pq.size() > 1) {
			long long x = -pq.top();
			pq.pop();
			long long y = -pq.top();
			pq.pop();
			pq.push(-(x + y));
			res += x + y;
		}
		printf("%lld\n", res);
	}
}