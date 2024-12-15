#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int n;

int main()
{
    int i, j;
    scanf("%d", &n);
    int y, idx = n;
    vector <int> arr;
    scanf("%d", &y);
    arr.push_back(y);
    for(i=1;i<n;i++) {
        int x;
        scanf("%d", &x);
        arr.push_back(x);
        if(idx != n) continue;
        if(y <= x) {
            y = x;
        } 
        else {
            idx = i;
        }
    }
    int ans = 0;
    y = arr[idx - 1];
    for(i=idx;i<n;i++) {
        int now = arr[i];
        if(now < y) {
            int res = 0;
            while(now < y) {
                now *= 2;
                res++;
            }
            y = now;
            ans += res;
        }
        else {
            y = now;
        }
    }
    printf("%d", ans);
    return 0;
}