#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        int odd = 0, even = 0;
        cin >> n;
        for(int i=0;i<n;i++) {
            int x;
            cin >> x;
            if(x % 2) odd++;
            else even++;
        }
        //cout << even << ' ' << odd << endl;
        if(even == odd) cout << "heeda0528\n";
        else {
            int mx = max(even, odd);
            if(mx % 2) cout << "amsminn\n";
            else cout << "heeda0528\n";
        }
    }
}