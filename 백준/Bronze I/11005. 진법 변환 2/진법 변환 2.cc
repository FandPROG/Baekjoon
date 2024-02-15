#include <stdio.h>
#include <math.h>
#include <string.h>
#include <vector>

using namespace std;

int n, m;
vector <int> ans;

int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	while (n >= m) {
		ans.push_back(n % m);
		n /= m;
	}
	ans.push_back(n);
	for (i = ans.size() - 1; i >= 0; i--) {
		if (ans[i] > 9) printf("%c", 'A' + (ans[i] - 10));
		else printf("%d", ans[i]);
	}
	return 0;
}