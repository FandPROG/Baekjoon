#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int arr[100010];

int main()
{
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &arr[i]);
	vector <int> lis;
	lis.push_back(arr[0]);
	for (i = 1; i < n; i++) {
		int lb = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
		int sz = lis.size();
		if (lb >= sz) lis.push_back(arr[i]);
		else lis[lb] = arr[i];
	}
	printf("%d", n - lis.size());
	return 0;
}