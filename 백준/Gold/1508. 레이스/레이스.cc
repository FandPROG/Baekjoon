#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using lD = long double;
using D = double;

int getres(int x, vector <int> vec, int m)
{
    int res = 1, dis = 0;
    for(auto k : vec) {
        dis += k;
        if(dis >= x && m > res) {
            res++;
            dis = 0;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int i, j;
    int n, m, k;
    cin >> n >> m >> k;
    vector <int> vec(k), dis;
    for(i=0;i<k;i++)  cin >> vec[i];
    for(i=0;i<k - 1;i++) {
        dis.push_back(vec[i + 1] - vec[i]);
    }
    int ansmid;
    int low = 0, high = vec[k - 1] - vec[0];
    while(low <= high) {
        int mid = (low + high) / 2;
        int midres = getres(mid, dis, m);
        if(midres >= m) {  
            ansmid = mid;
            low = mid + 1; 
        } else { 
            high = mid - 1; 
        }
    }
    vector <int> ans;
    ans.push_back(1);
    int dist = 0;
    int resone = 1;
    for(auto as : dis) {
        dist += as;
        if(dist >= ansmid && resone < m) {
            dist = 0;
            resone++;
            ans.push_back(1);
        } else ans.push_back(0);
    }
    for(auto i : ans) cout << i;
    return 0;
}