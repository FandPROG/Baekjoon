#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int i, j;
	int n;
	scanf("%d", &n);
	vector<int> vec, lis;
	for (i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		vec.push_back(x);
	}
	lis.push_back(vec[0]);
	for (i = 1; i < n; i++) {
		int lb = lower_bound(lis.begin(), lis.end(), vec[i]) - lis.begin();
		int sz = lis.size();
		if (lb >= sz) lis.push_back(vec[i]);
		else lis[lb] = vec[i];
	}
	printf("%d", lis.size());
	return 0;
}