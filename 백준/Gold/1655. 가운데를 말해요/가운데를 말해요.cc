#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    int i, j;
    int n, mid;
    priority_queue <int> low, high;
    scanf("%d %d", &n, &mid);
    printf("%d\n", mid);
    for(i=2;i<=n;i++) {
        int x;
        scanf("%d", &x);
        if(x > mid) high.push(-x);
        else low.push(x);
        if(!(i % 2)) {
            if(low.size() > high.size()) {
                high.push(-mid);
                mid = low.top();
                low.pop();
            }
        }
        else {
            if(low.size() < high.size()) {
                low.push(mid);
                mid = -high.top();
                high.pop();
            }
            if(low.size() > high.size()) {
                high.push(-mid);
                mid = low.top();
                low.pop();
            }
        }
        printf("%d\n", mid);
    }
    return 0;
}