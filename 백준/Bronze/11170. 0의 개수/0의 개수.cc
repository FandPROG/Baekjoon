#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int ans = 0;
        for(int i=n;i<=m;i++) {
            int x = i;
            while(x >= 10) {
                if(x % 10 == 0) ans++;
                 x /= 10;
            }
            if(x == 0) ans++;
        }
        cout << ans << endl;
    }
}