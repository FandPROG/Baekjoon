#include <stdio.h>
#include <math.h>

int n;
long long P_fibo[1000010], M_fibo[1000010];

int main()
{
	int i, j;
	scanf("%d", &n);
	if (n == 0) printf("0\n0");
	else if (n > 0) {
		P_fibo[0] = 0;
		P_fibo[1] = 1;
		for (i = 2; i <= n; i++) P_fibo[i] = (P_fibo[i - 1] + P_fibo[i - 2]) % 1000000000;
		printf("1\n%lld", P_fibo[n]);
	}
	else {
		n *= (-1);
		M_fibo[0] = 0;
		M_fibo[1] = 1;
		for (i = 2; i <= n; i++) M_fibo[i] = (M_fibo[i - 2] - M_fibo[i - 1]) % 1000000000;
		if (M_fibo[n] < 0) printf("-1\n%lld", (-1) * M_fibo[n]);
		else printf("1\n%lld", M_fibo[n]);
	}
	return 0;
}