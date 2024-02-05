#include <stdio.h>
#include <string>

struct shark {
	int a, b, c; 
};

shark arr[55];
int brr[55];
bool vis[55];
int n;

int dfs(int a) {
	int i;
	vis[a] = 1;
	for (i = 0; i < n; i++) {
		if (arr[a].a == arr[i].a && arr[a].b == arr[i].b && arr[a].c == arr[i].c && a < i) continue;
		if (i == a || (arr[a].a < arr[i].a || arr[a].b < arr[i].b || arr[a].c < arr[i].c)) continue;
		if (brr[i] == -1 || vis[brr[i]] == 0 && dfs(brr[i]) == 1) {
			brr[i] = a;
			return 1;
		}
	}
	return 0;
}

int main() 
{
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		int a, b, c; 
		scanf("%d %d %d", &a, &b, &c);
		arr[i] = { a, b, c };
	}
	for (i = 0; i < 55; i++) brr[i] = -1;
	int ret = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < 2; j++) {
			for (int k = 0; k < 55; k++) vis[k] = 0;
			if (dfs(i)  == 1) ret++;
		}
	}
	printf("%d", n - ret);
}
