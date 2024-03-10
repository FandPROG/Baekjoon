#include <stdio.h>
#include <string.h>

int dp[1010][1010], mp[1010][1010], d[1010], cnt;
char s[2][1001];

void map(int x, int y)
{
	for(;;) { 
		if(y==0 || x==0) break; 
		if(mp[y][x] == 1) { 
			d[cnt++] = s[0][y-1]; 
			y--; 
			x--; 
		} 
		else { 
			if(mp[y][x] == 2) { 
				y--; 
			} 
			else{ 
				x--; 
			} 
		} 
	}
}

int main()
{
	int a, b, i, j;
	scanf("%s", s[0]);
	scanf("%s", s[1]);
	a = strlen(s[0]);
	b = strlen(s[1]);
	for(i=1;i<=a;i++) {
		for(j=1;j<=b;j++) {
			if(s[0][i-1] == s[1][j-1]) {
				dp[i][j] = dp[i-1][j-1]+1;
				mp[i][j] = 1;
			}
			else {
				if(dp[i-1][j] < dp[i][j-1]) {
					dp[i][j] = dp[i][j-1];
					mp[i][j] = 3;
				}
				else {
					dp[i][j] = dp[i-1][j];
					mp[i][j] = 2;
				}
			}
		}
	}
	map(b, a);
	printf("%d", dp[a][b]);
	if(dp[a][b] == 0) return 0;
	printf("\n");
	for(i=cnt-1;i>=0;i--) printf("%c", d[i]);
	return 0;
}