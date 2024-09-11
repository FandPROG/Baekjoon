#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int n;
string s[10];
int ch[10];
int ans = 2e9;
vector <int> vec;

void DFS(int x) {
    int i, j;
    if(x >= n) {
        int cnt = 0;
        for(i=0;i<vec.size() - 1;i++) {
            int now = vec[i], next = vec[i + 1];
            if(s[now][s[now].size() - 1] != s[next][0]) {
                cnt++;
            }
        }
        ans = min(ans, cnt);
        return;
    }
    for(i=0;i<n;i++) {
        if(ch[i] == 1) continue;
        vec.push_back(i);
        ch[i] = 1;
        DFS(x + 1);
        ch[i] = 0;
        vec.pop_back();
    }
}

int main()
{
    int i, j;
    cin >> n;
    int res = 0;
    for(i=0;i<n;i++) {
        cin >> s[i];
        int ssz = s[i].size();
        for(j=0;j<ssz - 1;j++) {
            if(s[i][j] != s[i][j + 1]) {
                res++;
            }
        }
    }
    DFS(0);
    cout << res + ans << endl;
    return 0;
}