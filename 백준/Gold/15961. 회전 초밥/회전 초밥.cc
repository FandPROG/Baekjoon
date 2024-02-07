#include <stdio.h>

int n, d, k, c;
int arr[3000010];
int cnt[3010];

int main()
{
    int i, j;
    scanf("%d %d %d %d", &n, &d, &k, &c);
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);
    int ct = 0, ans = 0;
    for (i = 0; i < k; i++) {
        if (arr[i] != c && cnt[arr[i]] == 0) {
            ct++;
        }
        cnt[arr[i]]++;
    }
    if (ans < ct) ans = ct;
    int t = 0, h = k;
    while (t < n)
    {
        if (h >= n) h -= n;
        if (arr[t] != c && cnt[arr[t]] == 1) ct--;
        cnt[arr[t]]--;
        if (arr[h] != c && cnt[arr[h]] == 0) ct++;
        cnt[arr[h]]++;
        h++, t++;
        if (ans < ct) ans = ct;
    }
    printf("%d", ans + 1);
    return 0;
}