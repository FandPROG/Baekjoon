#include <iostream>
#include <string>
#include <map>

using namespace std;

map <int, string> mp_num;
map <string, int> mp_pok;
string s;
int n, m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(0);
    int i, j;
    cin >> n >> m;
    for (i = 1; i <= n; i++) {
        cin >> s;
        mp_num.insert({ i, s });
        mp_pok.insert({ s, i });
    }
    for (i = 1; i <= m; i++) {
        cin >> s;
        if (isdigit(s[0]) != 0) {
            cout << mp_num[stoi(s)] << '\n';
        }
        else {
            cout << mp_pok[s] << '\n';
        }
    }
    return 0;
}