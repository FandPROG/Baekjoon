#include <stdio.h>
#include <stack>
#include <string.h>

using namespace std;

int main()
{
	int i, j, t;
	scanf("%d", &t);
	int ans = 0;
	while (t--) {
		char s[100010];
		scanf("%s", s);
		int l = strlen(s);
		stack <char> st;
		st.push(s[0]);
		for (i = 1; i < l; i++) {
			if (!st.empty() && s[i] == st.top()) {
				st.pop();
			}
			else {
				st.push(s[i]);
			}
		}
		if (st.empty()) ans++;
		while (!st.empty()) st.pop();
	}
	printf("%d", ans);
	return 0;
}