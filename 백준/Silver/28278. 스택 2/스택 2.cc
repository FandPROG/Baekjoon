#include <stdio.h>
#include <stack>

using namespace std;

stack <int> st;
int n;

int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		if (x == 1) {
			int y;
			scanf("%d", &y);
			st.push(y);
		}
		else if (x == 2) {
			if (st.empty()) printf("-1\n");
			else {
				printf("%d\n", st.top());
				st.pop();
			}
		}
		else if (x == 3) {
			printf("%d\n", st.size());
		}
		else if (x == 4) {
			if (st.empty()) printf("1\n");
			else printf("0\n");
		}
		else if (x == 5) {
			if (st.empty()) printf("-1\n");
			else printf("%d\n", st.top());
		}
	}
	return 0;
}