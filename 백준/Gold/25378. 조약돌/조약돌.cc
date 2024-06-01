#include <stdio.h>
#include <algorithm>

using namespace std;

int d[2510];

int n;
int arr[2510];

int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d", &arr[i]);
	for (i = 1; i <= n; i++) {
		d[i] = d[i - 1] + 1;
		int p = arr[i];
		for (j = i - 1; j >= 1; j--) {
			p = arr[j] - p;
			if (p < 0) break;
			if(p == 0) d[i] = min(d[i], d[j - 1] + i - j);
		}
	}
	printf("%d", d[n]);
	return 0;
}