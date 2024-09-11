#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int arr[200010];
int cnt[10];
int num = 0;

int main()
{
    int i, j;
    scanf("%d", &n);
    for(i=0;i<n;i++) {
        scanf("%d", &arr[i]);
    }
    int low = 0, high = 0;
    while(high < n && low <= high) {
        
        if(cnt[arr[high]] == 0) num++;
        cnt[arr[high++]]++;

        if(num > 2) {
            cnt[arr[low]]--;
            if(cnt[arr[low]] == 0) num--;
            low++;
        }
    }
    printf("%d", high - low);
    return 0;
}