#include <stdio.h>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

char s[300010];
int n, ans;
queue <int> bidx;
queue <int> aidx;

int main()
{
	int i, j;
	scanf("%s", s);
	n = strlen(s);
	for (i = 0; i < n; i++) {
		if (s[i] == 'B') {
			bidx.push(i);
		}
		if (s[i] == 'C') {
			if (!bidx.empty()) {
				bidx.pop();
				ans++;
			}
		}
		if (s[i] == 'A') {
			aidx.push(i);
		}
	}
	while (!bidx.empty() && !aidx.empty()) {
		int af = aidx.front(), bf = bidx.front();
		if (af < bf) {
			ans++;
			aidx.pop();
			bidx.pop();
		}
		else {
			bidx.pop();
		}
	}
	printf("%d", ans);
	return 0;
}