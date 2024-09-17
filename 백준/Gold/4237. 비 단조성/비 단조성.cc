#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    int i, j;
    int Q;
    scanf("%d", &Q);
    while(Q--) {
        int n;
        scanf("%d", &n);
        vector <int> vec;
        bool now = true; // true = '>', false = '<'
        for(i=0;i<n;i++) {
            int x;
            scanf("%d", &x);
            vec.push_back(x);
        }
        int ans = 1;
        for(i=0;i<n - 1;i++) {
            if(now == true) {
                if(vec[i] > vec[i + 1]) {
                    ans++;
                    now = false;
                }
            }
            if(now == false) {
                if(vec[i] < vec[i + 1]) {
                    ans++;
                    now = true;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}