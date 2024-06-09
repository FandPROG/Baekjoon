#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int n, check_1 = 0;
int arr[110][110];
vector <vector<int>> ans;
int ch[110], check[110];
vector <int> vec;

int pand(int x) {
	int i, j;
	for (i = 1; i <= n; i++) {
		if (arr[x][i] == 0) {
			if (check[i] == 0) return 1;
		}
	}
	for (i = 0; i < vec.size(); i++) {
		int t = vec[i];
		if (t == x) continue;
		if (arr[x][t] == 0 && arr[t][x] == 0) continue;
		else return 1;
	}
	return 0;
}

int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (i = 1; i <= n; i++) {
		if (ch[i] == 1) continue;
		for (j = 1; j <= n; j++) check[j] = 0;
		vec.push_back(i);
		check[i] = 1;
		for (j = 1; j <= n; j++) {
			if (i == j || ch[j] == 1) continue;
			if (arr[i][j] == 0) {
				vec.push_back(j);
				check[j] = 1;
			}
		}
		if (vec.size() == 1) {
			printf("0");
			return 0;
		}
		for (j = 0; j < vec.size(); j++) {
			int t = vec[j];
			int res = pand(t);
			if (res == 1) {
				printf("0");
				return 0;
			}
		}
		for (j = 0; j < vec.size(); j++) {
			int t = vec[j];
			ch[t] = 1;
		}
		ans.push_back(vec);
		vec.clear();
	}
	vector <pair<int, int>> numb;
	for (i = 0; i < ans.size(); i++) {
		sort(ans[i].begin(), ans[i].end());
		numb.push_back({ ans[i][0], i });
	}
	sort(numb.begin(), numb.end());
	printf("%d\n", ans.size());
	for (i = 0; i < numb.size(); i++) {
		for (j = 0; j < ans[numb[i].second].size(); j++) {
			printf("%d ", ans[numb[i].second][j]);
		}
		printf("\n");
	}
	return 0;
}