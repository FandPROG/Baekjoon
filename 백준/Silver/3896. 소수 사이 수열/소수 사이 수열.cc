#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> prim;
bool ch[1299710];

int main()
{
    int i, j;
    for(i=2;i<=1299709;i++) {
        if(ch[i] == 1) continue;
        prim.push_back(i);
        for(j=i * 2;j<=1299709;j+=i) {
            if(ch[j] == 1) continue;
            else ch[j] = 1;
        }
    }
    int t;
    scanf("%d", &t);
    while(t--) {
        int x;
        scanf("%d", &x);
        int lb = lower_bound(prim.begin(), prim.end(), x) - prim.begin();
        if(ch[x] == 0) printf("0\n");
        else printf("%d\n", prim[lb] - prim[lb - 1]);
    }
    return 0;
}