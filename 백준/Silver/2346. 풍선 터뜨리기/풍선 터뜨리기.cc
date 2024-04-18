#include <stdio.h>
#include <deque>
#include <vector>

using namespace std;

int main()
{
	int i, j;
	int n;
	scanf("%d", &n);
	deque <pair<int, int>> dq;
	for (i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		dq.push_back({ x, i + 1 });
	}
	int now = dq.front().first;
	printf("%d ", dq.front().second);
	dq.pop_front();
	while (!dq.empty()) {
		if (now > 0) {
			for (i = 1; i < now; i++) {
				pair<int, int> t = dq.front();
				dq.pop_front();
				dq.push_back(t);
			}
			now = dq.front().first;
			printf("%d ", dq.front().second);
			dq.pop_front();
		}
		else {
			now *= (-1);
			for (i = 1; i < now; i++) {
				pair<int, int> b = dq.back();
				dq.pop_back();
				dq.push_front(b);
			}
			now = dq.back().first;
			printf("%d ", dq.back().second);
			dq.pop_back();
		}
	}
	return 0;
}