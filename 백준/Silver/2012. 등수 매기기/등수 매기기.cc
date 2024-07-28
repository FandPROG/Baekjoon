#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int i, j;
	int n;
	vector <long long> vec;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		long long x;
		scanf("%lld", &x);
		vec.push_back(x);
	}
	long long ans = 0;
	sort(vec.begin(), vec.end());
	for (i = 0; i < n; i++) {
		long long x = i + 1;
		ans += abs(x - vec[i]);
	}
	printf("%lld", ans);
	return 0;
}