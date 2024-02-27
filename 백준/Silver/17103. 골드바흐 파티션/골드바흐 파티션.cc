#include <stdio.h>
#include <vector>

using namespace std;

int prime[1000010];
vector <int> v_prime;

void IsPrime()
{
	int i, j;
	for (i = 2; i <= 1000000; i++) {
		if (prime[i] == 1) continue;
		for (j = i * 2; j <= 1000000; j += i) {
			prime[j] = 1;
		}
	}
	for (i = 2; i <= 1000000; i++) if (prime[i] == 0) v_prime.push_back(i);
	return;
}

int main()
{
	int i, j;
	int t;
	IsPrime();
	scanf("%d", &t);
	while (t--) {
		int x;
		scanf("%d", &x);
		int cnt = 0;
		for (i = 0; i < v_prime.size(); i++) {
			if (x / 2 < v_prime[i]) break;
			if (prime[x - v_prime[i]] == 0) cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}