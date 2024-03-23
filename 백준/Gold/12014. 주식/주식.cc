#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int n, k;
int arr[10010];

int main()
{
	int i, tc = 1, t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &k);
		for (i = 0; i < n; i++) scanf("%d", &arr[i]);
		vector <int> lis;
		lis.push_back(arr[0]);
		for (i = 1; i < n; i++) {
			int lb = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
			int sz = lis.size();
			if (sz <= lb) lis.push_back(arr[i]);
			else lis[lb] = arr[i];
		}
		printf("Case #%d\n", tc);
		if (k <= lis.size()) printf("1\n");
		else printf("0\n");
		tc++;
		lis.clear();
	}
	return 0;
}