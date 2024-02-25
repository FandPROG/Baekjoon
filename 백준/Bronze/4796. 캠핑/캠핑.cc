#include <stdio.h>

int main()
{
	int t = 1;
	while (1)
	{
		int L, P, V;
		scanf("%d %d %d", &L, &P, &V);
		if (L == 0 && P == 0 && V == 0) break;
		int res;
		if ((V % P) > L) res = L;
		else res = (V % P);
		printf("Case %d: %d\n", t, (L * (V / P)) + res);
		t++;
	}
	return 0;
}