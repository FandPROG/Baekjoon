#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int l, c;
char s[20];
bool ch[20];
char moum[5] = {'a', 'e', 'i', 'o', 'u'};

vector <char> vec;
int moumcnt, jaumcnt;

void dffs(int x, int st)
{
    int i;
    if(x >= l) {
        if(moumcnt >= 1 && 2 <= jaumcnt) {
            for(i=0;i<vec.size();i++) printf("%c", vec[i]);
            printf("\n");
        }
        return;
    }
    for(i=st;i<c;i++) {
        if(ch[i]) moumcnt++;
        else jaumcnt++;
        vec.push_back(s[i]);
        dffs(x + 1, i + 1);
        if(ch[i]) moumcnt--;
        else jaumcnt--;
        vec.pop_back();
    }
}

int main()
{
    int i, j;
    scanf("%d %d", &l, &c);
    for(i=0;i<c;i++) scanf(" %c", &s[i]);
    sort(s, s + c);
    for(i=0;i<c;i++) {
        for(j=0;j<5;j++) {
            if(moum[j] == s[i]) {
                ch[i] = true;
                break;
            }
        }
    }
    dffs(0, 0);
    return 0;
}