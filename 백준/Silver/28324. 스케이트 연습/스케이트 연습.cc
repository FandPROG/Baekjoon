#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int arr[500010];
int ans;

int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &arr[i]);
	int nw = 0;
	for (i = n - 1; i >= 0; i--) {
		nw = min(nw + 1, arr[i]);
		ans += nw;
	}
	printf("%d", ans);
}