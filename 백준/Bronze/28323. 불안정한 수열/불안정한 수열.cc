#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector <int> a(n), b;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        a[i] = a[i] % 2;
    }
    int res = 0;
    int zeroans = 0;
    for(int i=0;i<n;i++) {
        if(a[i] == res) {
            res = (res == 1) ? 0 : 1;
            zeroans++;
        }
    }
    res = 1;
    int oneans = 0;
    for(int i=0;i<n;i++ ){
        if(a[i] == res) {
            res = (res == 1) ? 0 : 1;
            oneans++;
        }
    }
    int ans = max(oneans, zeroans);
    if(ans == 0) cout << 1;
    else cout << ans;
    return 0;
}