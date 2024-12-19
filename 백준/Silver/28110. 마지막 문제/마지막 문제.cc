#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace  std;

int main()
{
    int n;
    vector <int> vec;
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        int x;
        scanf("%d", &x);
        vec.push_back(x);
    }
    sort(vec.begin(), vec.end());
    int ans = 0, ansIdx = -1;
    for(int i=1;i<n;i++) {
        int res = vec[i] - vec[i-1];
        if(ans < res / 2) {
            ans = res / 2;
            ansIdx = i - 1;
        }
    }
    if(ansIdx == -1) {
        printf("-1");
    }
    else {
        printf("%d", vec[ansIdx] + ans);
    }
    return 0;
}