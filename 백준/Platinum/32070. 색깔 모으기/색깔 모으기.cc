#include <iostream>
#include <vector>

using namespace std;

int par[200010];
int cnt[200010];
int check[200010];
int set2outDe[200010];
int outDegree[200010];

int ffind(int x)
{
    if(x == par[x]) return x;
    else return par[x] = ffind(par[x]);
}

void funion(int x, int y)
{
    int a = ffind(x), b = ffind(y);
    if(a < b) {
        par[b] = a;
        cnt[a] += cnt[b];
    }
    else {
        par[a] = b;
        cnt[b] += cnt[a];
    }
}

int main()
{
    int i, j;
    int n;
    cin >> n;
    for(i=1;i<=n;i++) {
        par[i] = i;
        cnt[i] = 1;
    }
    for(i=0;i<n;i++) {
        int x, y;
        cin >> x >> y;
        outDegree[y]++;
        if(ffind(x) == ffind(y)) continue;
        funion(x, y);
    }
    int ans = 0;
    for(i=1;i<=n;i++) {
        //cout << par[i] << ' ' << cnt[i] << endl;
        int res = 0;
        int nowset = ffind(i);
        if(!check[nowset]) {
            check[nowset] = 1;
            if(cnt[nowset] > 1) ans += cnt[nowset] + 1;
        }
        if(outDegree[i] >= 2) {
            set2outDe[nowset]++;
            if(set2outDe[nowset] >= 2) {
                cout << "-1";
                return 0;
            }
        }
    }
    cout << ans;
    return 0;
}