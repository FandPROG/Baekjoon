#include <stdio.h>
#include <vector>

using namespace std;

int isprime[100010];
vector <int> prime;

void IsPrime()
{
	int i, j;
	for (i = 2; i <= 100000; i++) {
		if (isprime[i] == 1) continue;
		for (j = i * 2; j <= 100000; j += i) {
			if (isprime[j] == 1) continue;
			isprime[j] = 1;
		}
	}
	for (i = 2; i <= 100000; i++) {
		if (isprime[i] == 0) prime.push_back(i);
	}
	return;
}

int main()
{
	int t;
	scanf("%d", &t);
	IsPrime();
	while (t--) {
		int n;
		vector<pair<int, int>> ans;
		scanf("%d", &n);
		for (int i = 0; i < prime.size(); i++) {
			if (n % prime[i] == 0) {
				int cnt = 0;
				while (1) {
					if (n % prime[i] != 0) break;
					n /= prime[i];
					cnt++;
				}
				ans.push_back({ prime[i], cnt });
			}
		}
		for (int i = 0; i < ans.size(); i++) printf("%d %d\n", ans[i].first, ans[i].second);
		ans.clear();
	}
	return 0;
}