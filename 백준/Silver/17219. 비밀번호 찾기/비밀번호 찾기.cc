#include <iostream>
#include <map>
#include <string>

using namespace std;

map <string, string> mp;
string x, y;
int n, m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(0);
    int i, j;
    cin >> n >> m;
    for (i = 0; i < n; i++) {
        cin >> x >> y;
        mp.insert({ x, y });
    }
    for (i = 0; i < m; i++) {
        cin >> x;
        cout << mp[x] << '\n';
    }
    return 0;
}