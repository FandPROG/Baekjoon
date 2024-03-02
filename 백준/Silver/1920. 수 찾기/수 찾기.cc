#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int arr[100010];
int m;

int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &arr[i]);
	sort(arr, arr + n);
	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		int low = 0, che = 0, high = n - 1;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (arr[mid] == x) {
				printf("1\n");
				che = 1;
				break;
			}
			else if (arr[mid] < x) low = mid + 1;
			else high = mid - 1;
		}
		if(che == 0) printf("0\n");
	}
	return 0;
}