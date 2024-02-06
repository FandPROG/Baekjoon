#include <stdio.h>

int n, r, c;
int ans, ch;
int cnt = 0;

void Devide(int x, int y, int l)
{
    if (x == r && y == c) {
        ans = cnt;
        return;
    }
    if (r < x + l && r >= x && c < y + l && c >= y) {
        Devide(x, y, l / 2);
        Devide(x, y + (l / 2), l / 2);
        Devide(x + (l / 2), y, l / 2);
        Devide(x + (l / 2), y + (l / 2), l / 2);
    }
    else {
        cnt += l * l;
    }
}

int main()
{
    int i, j;
    scanf("%d %d %d", &n, &r, &c);
    Devide(0, 0, (1 << n));
    printf("%d", ans);
    return 0;
}