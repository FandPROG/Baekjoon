#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

long long kat[5010];

int main()
{
	int i, j, n;
	scanf("%d", &n);
	kat[0] = 1;
	kat[1] = 1;
	kat[2] = 2;
	kat[3] = 5;
	for (i = 4; i <= n/2; i++) {
		for (j = 0; j < i; j++) {
			long long res = (kat[i - 1 - j] * kat[j]) % 987654321;
			kat[i] = (kat[i] + res) % 987654321;
		}
	}
	printf("%lld", kat[n / 2]);
	return 0;
}