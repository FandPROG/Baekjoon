#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int arr[1000010];
vector <int> lis, ans;
int p[1000010];

int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &arr[i]);
	lis.push_back(arr[0]);
	for (i = 1; i < n; i++) {
		int lb = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
		int l = lis.size();
		if (lb >= l) {
			lis.push_back(arr[i]);
			p[i] = l;
		}
		else {
			lis[lb] = arr[i];
			p[i] = lb;
		}
	}
	int cnt = lis.size() - 1;
	for (i = n - 1; i >= 0; i--) {
		if (cnt == p[i]) {
			ans.push_back(arr[i]);
			cnt--;
		}
	}
	printf("%d\n", ans.size());
	for (i = ans.size() - 1; i >= 0; i--) printf("%d ", ans[i]);
	return 0;
}