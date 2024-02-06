#include <stdio.h>

int n, d, k, c;
int arr[30010];
int ch[3010];

int main()
{
    int i, j;
    scanf("%d %d %d %d", &n, &d, &k, &c);
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);
    int ans = 0;
    for (i = 0; i < n; i++) {
        int cnt = 0;
        for (j = 0; j < k; j++) {
            if (i + j >= n) {
                if (arr[i + j - n] != c && ch[arr[i + j - n]] == 0) {
                    cnt++;
                    ch[arr[i + j - n]] = 1;
                }
            }
            else {
                if (arr[i + j] != c && ch[arr[i + j]] == 0) {
                    ch[arr[i + j]] = 1;
                    cnt++;
                }
            }
        }
        for (j = 0; j <= d; j++) ch[j] = 0;
        if (cnt > ans) ans = cnt;
    }
    printf("%d", ans + 1);
    return 0;
}