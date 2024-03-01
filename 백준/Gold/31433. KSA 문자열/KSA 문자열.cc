#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

string s;
char comp[5] = { 'K', 'S', 'A' };
int cnt, x;

int main()
{
	int i, j;
	cin >> s;
	x = s.size();
	int n = 0, cnt = 0;
	for (i = 0; i < x; i++) {
		if (s[i] == comp[n % 3]) n++;
		else cnt++;
	}
	int ans = cnt + abs(x - n);
	string s1 = "K" + s;
	n = 0;
	int cnt1 = 1;
	for (i = 0; i < x + 1; i++) {
		if (s1[i] == comp[n % 3]) n++;
		else cnt1++;
	}
	int ans1 = cnt1 + abs(x - n);
	string s2 = "KS" + s;
	n = 0;
	int cnt2 = 2;
	for (i = 0; i < x + 2; i++) {
		if (s2[i] == comp[n % 3]) n++;
		else cnt2++;
	}
	int ans2 = cnt2 + abs(x - n);
	printf("%d", min(ans, min(ans1, ans2)));
	return 0;
}