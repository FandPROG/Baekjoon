#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

struct balls {
    int bx, by;
    int rx, ry;
    int cnt;
};

int n, m;
char map[15][15];
int check_map[15][15][15][15];
queue <balls> q;
int ex, ey;

int dx[5] = {0, 0, 1, -1};
int dy[5] = {1, -1, 0, 0};

int ans = 2e9;

void BFS()
{
    int i, j;
    while(!q.empty()) {
        int rnx = q.front().rx, rny = q.front().ry;
        int bnx = q.front().bx, bny = q.front().by;
        int now_cnt = q.front().cnt;
        q.pop();
        if(now_cnt + 1 > 10) continue;
        for(i=0;i<4;i++) {
            int rx = rnx, ry = rny, bx = bnx, by = bny;
            bool blue_ball_win = false, red_ball_win = false;
            while(1) {
                bool running = false;
                if(rx + dx[i] < n && ry + dy[i] < m && rx + dx[i] >= 0 && ry + dy[i] >= 0) {
                    if(map[rx + dx[i]][ry + dy[i]] == 'O') {
                        red_ball_win = true;
                    }
                    if(rx + dx[i] != bx || ry + dy[i] != by) {
                        if(map[rx + dx[i]][ry + dy[i]] != '#') {
                            rx += dx[i];
                            ry += dy[i];
                            running = true;
                        }
                    }
                }
                if(bx + dx[i] < n && by + dy[i] < m && bx + dx[i] >= 0 && by + dy[i] >= 0) {
                    if(map[bx + dx[i]][by + dy[i]] == 'O') {
                        blue_ball_win = true;
                    }
                    if(map[bx + dx[i]][by + dy[i]] != '#' && (red_ball_win == true || (bx + dx[i] != rx || by + dy[i] != ry))) {
                        bx += dx[i];
                        by += dy[i];
                        running = true;
                    }
                }
                if(!running) break;
            }
            if(blue_ball_win) continue;
            if(red_ball_win) ans = min(ans, now_cnt + 1);
            if(check_map[rx][ry][bx][by] > now_cnt + 1) {
                //if(red_ball_win) ans = min(ans, now_cnt + 1);
                check_map[rx][ry][bx][by] = now_cnt + 1;
                q.push({bx, by, rx, ry, now_cnt + 1});
            }
        }
    }
}

int main()
{
    int i, j;
    scanf("%d %d", &n, &m);
    for(i=0;i<n;i++) scanf("%s", map[i]);
    int bx, by, rx, ry;
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            if(map[i][j] == 'R') rx = i, ry = j;
            if(map[i][j] == 'B') bx = i, by = j;
            if(map[i][j] == 'O') ex = i, ey = j;
        }
    }
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            for(int ij=0;ij<n;ij++) {
                for(int ji=0;ji<m;ji++) {
                    check_map[i][j][ij][ji] = 2e9;
                }
            }
        }
    }
    q.push({bx, by, rx, ry, 0});
    BFS();
    if(ans == 2e9) printf("-1\n");
    else printf("%d\n", ans);
    return 0;
}