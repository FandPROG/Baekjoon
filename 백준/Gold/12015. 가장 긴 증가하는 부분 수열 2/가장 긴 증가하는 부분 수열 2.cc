#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int arr[1000010];
vector <int> lis;

int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &arr[i]);
	lis.push_back(arr[0]);
	for (i = 1; i < n; i++) {
		int l = lis.size();
		int lb = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
		if (lb >= l) lis.push_back(arr[i]);
		else {
			lis[lb] = arr[i];
		}
	}
	printf("%d", lis.size());
	return 0;
}