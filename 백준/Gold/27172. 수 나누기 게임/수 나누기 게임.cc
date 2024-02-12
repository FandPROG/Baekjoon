#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector <int> v;
int ch[1000010];
int cnt[1000010];

int main()
{
	int i, j;
	scanf("%d", &n);
	int mx = -2e9;
	for (i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		v.push_back(x);
		if (x > mx) mx = x;
		ch[x] = 1;
	}
	for (i = 0; i < v.size(); i++) {
		int x = v[i];
		for (j = x * 2; j <= mx; j += x) {
			if (ch[j] == 1) {
				cnt[j]--;
				cnt[x]++;
			}
		}
	}
	for (i = 0; i < v.size(); i++) {
		printf("%d ", cnt[v[i]]);
	}
	return 0;
}