#include <stdio.h>

int max(int x, int y)
{
	if(x>y) return x;
	else return y;
}
int n, a[100010], s[100010], ans;

int main()
{
	int i;
	scanf("%d", &n);
	for(i=1;i<=n;i++){
		scanf("%d", &a[i]);
		s[i]=s[i-1]+a[i];
	}
	for(i=2;i<=n-1;i++) ans = max(ans,s[n-1]-a[1]+a[i]);
	for(i=2;i<=n-1;i++) ans = max(ans,s[i-1]-a[1]+2*(s[n]-s[i]));
	for(i=2;i<=n-1;i++) ans = max(ans,2*s[i-1]+s[n-1]-s[i]);
	printf("%d", ans);
	return 0;
}