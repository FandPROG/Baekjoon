#include <stdio.h>
#include <deque>

using namespace std;

deque <int> dq;

int main()
{
	int i, j;
	int n;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		if (x == 1) {
			int y;
			scanf("%d", &y);
			dq.push_front(y);
		}
		else if (x == 2) {
			int y;
			scanf("%d", &y);
			dq.push_back(y);
		}
		else if (x == 3) {
			if (dq.empty()) printf("-1\n");
			else {
				printf("%d\n", dq.front());
				dq.pop_front();
			}
		}
		else if (x == 4) {
			if (dq.empty()) printf("-1\n");
			else {
				printf("%d\n", dq.back());
				dq.pop_back();
			}
		}
		else if (x == 5) {
			printf("%d\n", dq.size());
		}
		else if (x == 6) {
			if (dq.empty()) printf("1\n");
			else printf("0\n");
		}
		else if (x == 7) {
			if (dq.empty()) printf("-1\n");
			else {
				printf("%d\n", dq.front());
			}
		}
		else if (x == 8) {
			if (dq.empty()) printf("-1\n");
			else {
				printf("%d\n", dq.back());
			}
		}
	}
}