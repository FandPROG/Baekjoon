#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using lD = long double;
using D = double;

map <int, int> JBNU;
int k;

int searchidx(int x)
{
    int value;
    if(JBNU.find(x) != JBNU.end()) return x;
    else {
        auto lb = JBNU.lower_bound(x);
        int r = -1, l = -1;
        if(lb != JBNU.end()) r = lb->first;
        if(lb != JBNU.begin()) l = prev(lb)->first;
        if(r == -1 && l == -1) return - 1;
        if(r == -1 && l != -1) {
            if(x - l > k) return -1;
            else return l;
        }
        if(l == -1 && r != -1) {
            if(r - x > k) return -1;
            else return r;
        }
        if(r - x < x - l) {
            if(r - x > k) return -1;
            else return r;
        }
        else if(r - x > x - l) {
            if(x - l > k) return -1;
            else return l;
        }
        else {
            return -2;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int i, j;
    int n, m;
    cin >> n >> m >> k;
    while(n--) {
        int key, val;
        cin >> key >> val;
        JBNU.insert({key, val});
    }
    while(m--) {
        int oper;
        cin >> oper;
        if(oper == 1) {
            int key, val;
            cin >> key >> val;
            JBNU.insert({key, val});
        }
        else if(oper == 2) {
            int x, val;
            cin >> x >> val;
            int idx = searchidx(x);
            if(idx == -1 || idx == -2) continue;
            JBNU[idx] = val;
        }
        else {
            int x;
            cin >> x;
            int idx = searchidx(x);
            if(idx == -1) cout << "-1" << "\n";
            else if(idx == -2) cout << "?" << "\n";
            else cout << JBNU[idx] << "\n";
        }
    }
    return 0;
}