#include <algorithm>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int n, p, res;
int c[1010][1010], f[1010][1010], d[1010];
vector<int> v[1010];

void mf(int s, int e) 
{
    int i, j;
    while (1) {
        fill(d, d + 1010, -1);
        queue<int> q;
        q.push(s);
        d[s] = 0;
        while (!q.empty() && d[e] == -1) {
            int x = q.front();
            q.pop();
            for (i = 0; i < v[x].size(); i++) {
                int nx = v[x][i];
                if (d[nx] == -1 && c[x][nx] - f[x][nx] > 0) {
                    q.push(nx);
                    d[nx] = x;
                    if (nx == e) break;
                }
            }
        }
        if (d[e] == -1) break;
        int pd = 987654321;
        for (i = e; i != s; i = d[i]) {
            pd = min(pd, c[d[i]][i] - f[d[i]][i]);
        }
        for (i = e; i != s; i = d[i]) {
            f[d[i]][i] += pd;
            f[i][d[i]] -= pd;
        }
        res += pd;
    }
}

int main() 
{
    int i, j;
    scanf("%d %d", &n, &p);
    for (i = 1; i <= n; i++) {
        int x = 2 * i;
        int nx = 2 * i - 1;
        c[x][nx] = 1;
        v[nx].push_back(x);
        v[x].push_back(nx);
    }
    for (i = 0; i < p; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        int u = a * 2;
        int nu = a * 2 - 1;
        int z = b * 2;
        int nz = b * 2 - 1;
        c[nu][z] = 1;
        c[nz][u] = 1;
        v[nu].push_back(z);
        v[z].push_back(nu);
        v[nz].push_back(u);
        v[u].push_back(nz);
    }
    mf(1, 4);
    printf("%d", res);
    return 0;
}