#include <stdio.h>
  
int n, c[100], ch[100], che[100], cnt;
  
void qn(int x) {
    int i;
    if(n <= x) {
        cnt++;
        return;
    }
    for(i=0;i<n;i++) {
        if(c[i] == 1) continue;
        if(ch[x+i] == 1) continue;
        if(che[x-i+n] == 1) continue;
        c[i] = 1;
        ch[x+i] = 1;
        che[x-i+n] = 1;
        qn(x+1);
        c[i] = 0;
        ch[x+i] = 0;
        che[x-i+n] = 0;
    }
}
  
int main()
{
    scanf("%d", &n);
    qn(0);
    printf("%d", cnt);
}