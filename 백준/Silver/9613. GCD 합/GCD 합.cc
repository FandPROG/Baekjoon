#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int GCD(int a, int b)
{
	if (b == 0) return a;
	else return GCD(b, a % b);
}

int main()
{
	int i, j;
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		vector <int> vec;
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			vec.push_back(x);
		}
		sort(vec.begin(), vec.end());
		long long ans = 0;
		for (i = 0; i < vec.size() - 1; i++) {
			for (j = i + 1; j < vec.size(); j++) {
				ans += GCD(vec[j], vec[i]);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}