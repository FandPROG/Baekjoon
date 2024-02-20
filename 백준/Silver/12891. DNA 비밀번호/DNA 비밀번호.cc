#include <stdio.h>

int n, k;
int arr[5];
int cnt[5];
char s[1000010];

int main()
{
	int i, j;
	scanf("%d %d", &n, &k);
	scanf("%s", s);
	for (i = 0; i < 4; i++) scanf("%d", &arr[i]);
	for (i = 0; i < k; i++) {
		if (s[i] == 'A') cnt[0]++;
		else if (s[i] == 'C') cnt[1]++;
		else if (s[i] == 'G') cnt[2]++;
		else if (s[i] == 'T') cnt[3]++;
	}
	int l = 0, h = k, c = 0, ans = 0;
	for (i = 0; i < 4; i++) if (cnt[i] >= arr[i]) c++;
	if (c == 4) ans++;
	while (h < n) {
		if (s[l] == 'A') cnt[0]--;
		else if (s[l] == 'C') cnt[1]--;
		else if (s[l] == 'G') cnt[2]--;
		else if (s[l] == 'T') cnt[3]--;
		if (s[h] == 'A') cnt[0]++;
		else if (s[h] == 'C') cnt[1]++;
		else if (s[h] == 'G') cnt[2]++;
		else if (s[h] == 'T') cnt[3]++;
		l++;
		h++;
		c = 0;
		for (i = 0; i < 4; i++) if (cnt[i] >= arr[i]) c++;
		if (c == 4) ans++;
	}
	printf("%d", ans);
	return 0;
}