#include <stdio.h>

int n, m;
int arr[1000100];

int main()
{
    int i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);
    scanf("%d", &m);
    for (i = 0; i < n; i++) {
        int mx = -2e9, idx;
        for (j = i; j <= i + m; j++) {
            if (mx < arr[j]) {
                mx = arr[j];
                idx = j;
            }
        }
        m -= (idx - i);
        int imsi = arr[idx];
        for (j = idx; j > i; j--) {
            arr[j] = arr[j - 1];
        }
        arr[i] = imsi;
    }
    for (i = 0; i < n; i++) printf("%d ", arr[i]);
    return 0;
}