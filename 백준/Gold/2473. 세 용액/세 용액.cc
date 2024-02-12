#include <stdio.h>
#include <algorithm>
#include <cmath>

using namespace std;

long long n;
long long arr[5010];
long long ans = 9e20, ans_arr[5];

int main()
{
	long long i, j;
	scanf("%lld", &n);
	for (i = 0; i < n; i++) scanf("%lld", &arr[i]);
	sort(arr, arr + n);
	for (i = 0; i < n - 2; i++) {
		long long fir = i + 1, sec = n - 1;
		while (fir < sec)
		{
			long long res = arr[fir] + arr[sec] + arr[i];
			if (abs(res) < ans) {
				ans = abs(res);
				ans_arr[0] = arr[fir];
				ans_arr[1] = arr[sec];
				ans_arr[2] = arr[i];
			}
			if (res < 0) fir++;
			else sec--;
		}
	}
	sort(ans_arr, ans_arr + 3);
	for (i = 0; i < 3; i++) printf("%lld ", ans_arr[i]);
	return 0;
}