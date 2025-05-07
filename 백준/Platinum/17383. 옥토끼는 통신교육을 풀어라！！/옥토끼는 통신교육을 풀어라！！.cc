#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using lD = long double;
using D = double;

#include <bits/stdc++.h>
using namespace std;

bool getpar(ll x, vector<int>& arr) {
    int i, j;
    vector <int> vec;
    for(auto v : arr) {
        if(v % x > 0) vec.push_back(v / x + 1);
        else vec.push_back(v / x);
    }
    if(vec[0] > 1) return false;
    int acc = 0;
    for(i=1;i<vec.size();i++) {
        if(vec[i] == 1) acc++;
        else if(vec[i] - 2 > acc) return false;
        else {
            acc -= (vec[i] - 2);
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int i, j;
    int n;
    cin >> n;
    vector <int> arr(n);
    for(i=0;i<n;i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    ll low = 1, high = 1e9;

    while(low < high) {
        ll mid = (low + high) / 2;
        bool par = getpar(mid, arr);
        if(par) high = mid;
        else low = mid + 1;
    }
    cout << high;
    return 0;
}