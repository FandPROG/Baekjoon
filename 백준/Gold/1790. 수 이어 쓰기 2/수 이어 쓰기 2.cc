#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using lD = long double;
using D = double;

ll getsq(ll n, int x) {
	ll res = 1;
	for(int i=0;i<x;i++) {
		res *= n;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int i, j;
	ll n, k;
	cin >> n >> k;
	for(i=1;;i++) {
		ll nowDetect = 9 * getsq(10, i - 1) * i;
		if(k <= nowDetect) {
			int tracker;
			if(k % i > 0) tracker = k / i;
			else tracker = k / i - 1;
			tracker = getsq(10, i - 1) + tracker;
			if(tracker > n) {
				cout << "-1";
				return 0;
			}
			vector <int> num;
			while(tracker > 0) {
				num.push_back(tracker % 10);
				tracker /= 10;
			}
			//num.push_back(tracker);
			if(k % i == 0) cout << num[0];
			else {
				cout << num[i - (k % i)];
			}
			break;
		}
		k -= nowDetect;
	}
	return 0;
}