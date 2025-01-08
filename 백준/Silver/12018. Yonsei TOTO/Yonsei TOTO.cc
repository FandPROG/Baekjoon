#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;

int main()
{
    int i, j;
    scanf("%d %d", &n, &m);
    vector <int> vec;
    for(i=0;i<n;i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        vector <int> arr(x);
        for(j=0;j<x;j++) scanf("%d", &arr[j]);
        sort(arr.begin(), arr.end());
        //for(j=0;j<x;j++) printf("%d ", arr[j]);
        //printf("\n");
        int res;
        if(x < y) res = 1;
        else res = arr[x - y];
        vec.push_back(res);
    }
    //for(i=0;i<n;i++) printf("%d ", vec[i]);
    //printf("\n");
    sort(vec.begin(), vec.end());
    int ans = 0;
    for(i=0;i<n;i++) {
        if(vec[i] > m) break;
        ans++;
        m -= vec[i];
    }
    printf("%d", ans);
    return 0;
}