#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
priority_queue <int> pos, neg;

int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		if (x < 0) neg.push(-x);
		else pos.push(x);
	}
	int pl = pos.size(), nl = neg.size();
	int ans = 0;
	if (pl > 0 && nl > 0) {
		if (pos.top() > neg.top()) {
			ans += pos.top();
			for (i = 0; i < m; i++) {
				pos.pop();
				if (pos.empty()) break;
			}
		}
		else {
			ans += neg.top();
			for (i = 0; i < m; i++) {
				neg.pop();
				if (neg.empty()) break;
			}
		}
		while (!neg.empty()) {
			ans += (2 * neg.top());
			for (i = 0; i < m; i++) {
				neg.pop();
				if (neg.empty()) break;
			}
		}
		while (!pos.empty()) {
			ans += (pos.top() * 2);
			for (i = 0; i < m; i++) {
				pos.pop();
				if (pos.empty()) break;
			}
		}
	}
	else if (pl > 0 && nl == 0) {
		ans += pos.top();
		for (i = 0; i < m; i++) {
			pos.pop();
			if (pos.empty()) break;
		}
		while (!pos.empty()) {
			ans += (pos.top() * 2);
			for (i = 0; i < m; i++) {
				pos.pop();
				if (pos.empty()) break;
			}
		}
	}
	else {
		ans += neg.top();
		for (i = 0; i < m; i++) {
			neg.pop();
			if (neg.empty()) break;
		}
		while (!neg.empty()) {
			ans += (neg.top() * 2);
			for (i = 0; i < m; i++) {
				neg.pop();
				if (neg.empty()) break;
			}
		}
	}
	printf("%d", ans);
	return 0;
}