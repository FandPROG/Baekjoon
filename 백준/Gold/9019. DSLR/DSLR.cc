#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

struct dat
{
   int way, pass;
};

int n;
int ch[10010];
dat ans[10010];
vector <pair<int, int>> vec;

int Lef(int x)
{
   int y = x / 1000;
   x %= 1000;
   return (x * 10) + y;
}

int Rig(int x)
{
   int y = x % 10;
   x /= 10;
   return (y * 1000) + x;
}

int Dou(int x)
{
   return (x * 2) % 10000;
}

int smi(int x)
{
    if(x <= 0) return 9999;
    else return x - 1;
}

void BFS(int x)
{
   int i;
   queue <int> q;
   q.push(x);
   for (i = 0; i <= 9999; i++) ans[i] = { 0, 0 }, ch[i] = 2e9;
   ch[x] = 0;
    ans[x].way = x;
   while (!q.empty()) {
      int now = q.front();
      q.pop();
      int no[5];
      no[1] = Dou(now);
      no[2] = Rig(now);
      no[3] = Lef(now);
       no[4] = smi(now);
      for (i = 1; i <= 4; i++) {
         if (ch[no[i]] > ch[now] + 1) {
            ch[no[i]] = ch[now] + 1;
            q.push(no[i]);
            ans[no[i]].way = now;
            ans[no[i]].pass = i;
         }
      }
   }
   return;
}

void DFS(int x)
{
   if (ans[x].way == x) return;
    vec.push_back({ans[x].way, ans[x].pass});
   DFS(ans[x].way);
}

int main()
{
   int i, j;
   scanf("%d", &n);
   for (i = 0; i < n; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      BFS(x);
       DFS(y);
       int vesize = vec.size();
       for(j=vesize - 1;j>=0;j--) {
//           printf("%d ", vec[j].first);
           if(vec[j].second == 1) printf("D");
           else if(vec[j].second == 2) printf("R");
           else if(vec[j].second == 3) printf("L");
           else if(vec[j].second == 4) printf("S");
//           printf("\n");
       }
       printf("\n");
       for(j=0;j<vesize;j++) vec.pop_back(); 
   }
   return 0;
}