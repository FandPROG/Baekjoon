#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int i, j, n, ans = 0;
	string lo = "2023";
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		string s = to_string(i);
		int cnt = 0;
		for (j = 0; j < s.size(); j++) {
			if (lo[cnt] == s[j]) cnt++;
			if (cnt == 4) break;
		}
		if (cnt == 4) ans++;
	}
	printf("%d", ans);
}