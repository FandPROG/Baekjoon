#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int n, k;
int arr[5010];

int main()
{
	int i, j;
	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++) scanf("%d", &arr[i]);
	sort(arr, arr + n);
	reverse(arr, arr + n);
	int sum = 0;
	for (i = 1; i < k; i++) sum -= i;
	for (i = 0; i < k; i++) sum += arr[i];
	printf("%d", sum);
	return 0;
}