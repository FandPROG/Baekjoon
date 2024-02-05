#include <stdio.h>
#include <string.h>

int n;
char x[210];

int main()
{
    int i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%s", x);
        int now = 0, ch = 0, l = strlen(x);
        while (now < l)
        {
            if (x[now] == '1' && x[now + 1] == '0' && x[now + 2] == '0') {
                now += 3;
                char now_ch = '0';
                int one = 0;
                while (now < l) {
                    if (one >= 1 && x[now] == '1' && x[now + 1] == '0' && x[now + 2] == '0') break;
                    if (x[now] == '0' && now_ch == '1') break;
                    if (x[now] == '1') one++;
                    now_ch = x[now++];
                }
                if (one == 0) {
                    printf("NO\n");
                    ch = 1;
                    break;
                }
            }
            else if (x[now] == '0' && x[now + 1] == '1') now += 2;
            else {
                printf("NO\n");
                ch = 1;
                break;
            }
        }
        if (ch == 0) printf("YES\n");
    }
    return 0;
}