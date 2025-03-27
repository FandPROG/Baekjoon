#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using lD = long double;
using D = double;

int N, M;
string ordr;
vector <int> xx, yy;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int i, j;
    cin >> N >> M;
    for(i=0;i<N;i++) {
        int x, y;
        cin >> x >> y;
        xx.push_back(x);
        yy.push_back(y);
    }
    sort(xx.begin(), xx.end());
    sort(yy.begin(), yy.end());
    cin >> ordr;
    int sx = 0, sy = 0;
    vector <ll> xsum(N), ysum(N);
    xsum[0] = xx[0], ysum[0] = yy[0];
    for(i=1;i<N;i++) {
        xsum[i] = xsum[i - 1] + xx[i];
        ysum[i] = ysum[i - 1] + yy[i];
    }
    for(i=0;i<M;i++) {
        if(ordr[i] == 'S') sy++;
        else if(ordr[i] == 'J') sy--;
        else if(ordr[i] == 'I') sx++;
        else sx--;

        int xlb = lower_bound(xx.begin(), xx.end(), sx) - xx.begin();
        int ylb = lower_bound(yy.begin(), yy.end(), sy) - yy.begin();

        ll res = 0;
        if(xlb > 0) res += (sx * xlb) - xsum[xlb - 1];
        if(ylb > 0) res += (sy * ylb) - ysum[ylb - 1];
        
        ll zxsum, zysum;
        
        if(xlb > 0) zxsum = xsum[xlb - 1];
        else zxsum = 0;
        
        if(ylb > 0) zysum = ysum[ylb - 1];
        else zysum = 0;
        
        res += xsum[N - 1] - zxsum - (sx * (N - xlb));
        res += ysum[N - 1] - zysum - (sy * (N - ylb));

        cout << res << "\n";
    }
    return 0;
}
