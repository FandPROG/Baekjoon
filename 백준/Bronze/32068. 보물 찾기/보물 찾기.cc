#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int L, S, R;
        cin >> L >> R >> S;
        int l = S - L;
        int r = R - S;
        if(l >= r) {
            cout << r * 2 << endl;
        }
        else {
            cout << l * 2 + 1 << endl;
        }
    }
}