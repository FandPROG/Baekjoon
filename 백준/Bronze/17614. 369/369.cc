#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main()
{
    int n;
    int ans = 0;
    cin >> n;
    for(int i=1;i<=n;i++) {
        int x = i;
        while(1) {
            if(x < 10) break;
            int res = x % 10;
            if(res % 3 == 0 && res > 0) ans++;
            x /= 10;
        }
        if(x % 3 == 0 && x > 0) ans++;
    }
    cout << ans;
    return 0;
}