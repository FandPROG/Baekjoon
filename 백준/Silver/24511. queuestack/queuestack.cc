#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
int arr[100010];
queue <int> q;
vector <int> vc;

int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d", &arr[i]);
	for (i = 1; i <= n; i++) {
		int qs;
		scanf("%d", &qs);
		if (arr[i] == 1) continue;
		vc.push_back(qs);
	}
	reverse(vc.begin(), vc.end());
	for (i = 0; i < vc.size(); i++) q.push(vc[i]);
	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		q.push(x);
		printf("%d ", q.front());
		q.pop();
	}
	return 0;
}