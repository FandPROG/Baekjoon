#include <stack>
#include <string>
#include <queue>
#include <deque>
#include <stdio.h>

using namespace std;

int n;
stack <pair<int, char>> st;
deque <char> ans;

int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		char s;
		int op;
		scanf("%d", &op);
		if (op == 3 && st.size() > 0) st.pop();
		else if (op == 2 || op == 1) {
			scanf(" %c", &s);
			st.push({ op, s });
		}
	}
	stack <pair<int, char>> sta;
	while (!st.empty()) {
		sta.push(st.top());
		st.pop();
	}
	while (!sta.empty()) {
		int t = sta.top().first;
		char s = sta.top().second;
		sta.pop();
		if (t == 1) ans.push_back(s);
		else ans.push_front(s);
	}
	if (ans.size() == 0) printf("0");
	else {
		for(i=0;i<ans.size();i++) printf("%c", ans[i]);
	}
	return 0;
}