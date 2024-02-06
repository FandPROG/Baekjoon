#include <stdio.h>
#include <string.h>

int n;
int k;
char s[10];

int main()
{
    int i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        int x;
        scanf("%s", s);
        if (!strcmp(s, "add")) {
            scanf("%d", &x);
            k |= (1 << x);
        }
        else if (!strcmp(s, "remove")) {
            scanf("%d", &x);
            k &= ~(1 << x);
        }
        else if (!strcmp(s, "check")) {
            scanf("%d", &x);
            if (k & (1 << x)) printf("1\n");
            else printf("0\n");
        }
        else if (!strcmp(s, "toggle")) {
            scanf("%d", &x);
            if (k & (1 << x)) k &= ~(1 << x);
            else k |= (1 << x);
        }
        else if (!strcmp(s, "all")) {
            k |= (1 << 21) - 1;
        }
        else k = 0;
    }
    return 0;
}