#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector <int> vec;

int main() 
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		vec.push_back(x);
	}
	int ans = 2e9;
	sort(vec.begin(), vec.end());
	int low = 0, high = 0;
	while (low < n && high < n) {
		int res = vec[high] - vec[low];
		if (res < m) {
			high++;
		}
		else {
			ans = min(ans, res);
			low++;
		}
	}
	printf("%d", ans);
	return 0;
}