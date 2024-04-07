#include <stdio.h>
#include <algorithm>

int n;
char s[110];
int arr[110];

int main()
{
	int i, t;
	scanf("%d", &t);
	while (t--) {
		int ans = 0;
		scanf("%d", &n);
		for (i = 0; i < n; i++) scanf("%1d", &arr[i]);
		scanf("%s", s);
		if (n == 1) {
			printf("%d\n", arr[0]);
			continue;
		}
		for (i = 0; i < n; i++) {
			if (s[i] == '*') {
				ans++;
				if(i > 0) arr[i - 1]--;
				arr[i + 1]--, arr[i]--;
			}
		}
		if (arr[0] > 0 && arr[1] > 0) {
			arr[0]--;
			arr[1]--;
			ans++;
		}
		for (i = 1; i < n - 1; i++) {
			if (s[i] == '*') continue;
			if (arr[i - 1] > 0 && arr[i] > 0 && arr[i + 1] > 0) {
				arr[i - 1]--;
				arr[i]--;
				arr[i + 1]--;
				ans++;
			}
		}
		if (arr[n - 1] > 0 && arr[n - 2] > 0) {
			arr[n - 1]--;
			arr[n - 2]--;
			ans++;
		}
		printf("%d\n", ans);
	}
}