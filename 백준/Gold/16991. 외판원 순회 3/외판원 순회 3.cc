#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int n;
double arr[16][16], dp[16][1 << 16];
vector <pair<double, double>> vec;

double TSP(int x, int vis)
{
	int i, j;
	if (vis == (1 << n) - 1) return arr[x][0];
	if (dp[x][vis] != -2e9) return dp[x][vis];
	dp[x][vis] = 2e9;
	for (i = 0; i < n; i++) {
		if (i != x && (vis & (1 << i)) == 0) {
			dp[x][vis] = min(dp[x][vis], TSP(i, vis | (1 << i)) + arr[x][i]);
		}
	}
	return dp[x][vis];
}

int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		double x, y;
		scanf("%lf %lf", &x, &y);
		vec.push_back({ x, y });
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i == j) continue;
			arr[i][j] = sqrt(pow((vec[j].first - vec[i].first), 2) + pow((vec[j].second - vec[i].second), 2));
		}
	}
	for (i = 0; i < 16; i++) {
		for (j = 0; j < (1 << 16); j++) {
			dp[i][j] = -2e9;
		}
	}
	double ans = TSP(0, 0);
	printf("%lf", ans);
	return 0;
}