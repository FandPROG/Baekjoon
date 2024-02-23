#include <stdio.h>
#include <vector>

using namespace std;

long long n, s;
long long arr[25];
long long ans;

void DFS(long long idx, long long sum)
{
	long long i;
	if (sum == s && idx >= 1) {
		ans++;
	}
	for (i = idx; i < n; i++) {
		sum += arr[i];
		DFS(i + 1, sum);
		sum -= arr[i];
	}
}

int main()
{
	long long i, j;
	scanf("%lld %lld", &n, &s);
	for (i = 0; i < n; i++) scanf("%lld", &arr[i]);
	DFS(0, 0);
	printf("%lld", ans);
	return 0;
}