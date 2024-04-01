#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector <int> vec;
int ans;

int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		vec.push_back(x);
	}vec.push_back(0);
	int low = 0, high = 0;
	int res = vec[0];
	while (low < n && high < n) {
		if (res == m) res += vec[++high], ans++;
		else if (res < m) res += vec[++high];
		else res -= vec[low++];
	}
	printf("%d", ans);
}