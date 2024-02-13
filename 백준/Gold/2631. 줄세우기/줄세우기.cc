#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int arr[1000010];
vector <int> LIS;

int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &arr[i]);
	LIS.push_back(arr[0]);
	for (i = 1; i < n; i++) {
		int up = lower_bound(LIS.begin(), LIS.end(), arr[i]) - LIS.begin();
		if (up >= LIS.size()) LIS.push_back(arr[i]);
		else LIS[up] = arr[i];
	}
	printf("%d", n - LIS.size());
	return 0;
}