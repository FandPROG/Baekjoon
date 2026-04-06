#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    queue <pair<string, int>> q;
    for(int i=0;i<n;i++) {
        string a;
        int x;
        cin >> a >> x;
        q.push({a, x});
    }
    while(!q.empty()) {
        if(q.size() == 1) break;
        pair<string, int> p = q.front();
        q.pop();
        int c = p.second - 1;
        while(c--) {
            pair<string, int> p1 = q.front();
            q.pop();
            q.push(p1);
        }
        q.pop();
    }
    cout << q.front().first;
    return 0;
}