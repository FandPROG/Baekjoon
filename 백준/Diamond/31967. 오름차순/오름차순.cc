#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using lD = long double;
using D = double;

int n, q, arr[250010];
int d[250010], s[250010], p[250010];
ll s2[250010], c[250010];
stack<int> st;

ll func(int l, int r) {
	if(l > r) return 0;
	return (s2[r] - s2[l - 1]) + (ll)(r + 1) * (s[r] - s[l - 1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int i, j;
    cin >> n >> q;
	for(i = 1; i <= n; i++) cin >> arr[i];
	for(i = 1; i < n; i++) {
		int v = arr[i + 1];
		while(arr[i] > v) {
			v *= 2;
			d[i]++;
		}
		while(arr[i] <= v / 2) {
			v /= 2;
			d[i]--;
		}
		s[i] = s[i - 1] + d[i];
		s2[i] = s2[i - 1] - (ll)i * d[i];
	}
    // for(i=1;i<n;i++) {
    //     cout << s[i] << ' ';
    // }
    // cout << endl;
    // for(i=0;i<n;i++) {
    //     cout << d[i] << ' ';
    // }
    // cout << endl;
	p[n] = n;
	for(i = n - 1; i >= 0; i--) {
		while(st.size() && s[st.top()] >= s[i]) st.pop();
		if(st.size()) {
			p[i] = st.top();
			c[i] = func(i + 1, p[i] - 1);
		}
		else p[i] = n;
		st.push(i);
	}
    // for(i=0;i<n;i++) {
    //     cout << p[i] << ' ';
    // }
    // cout << endl;
	while(q--) {
        int l, r;
		cin >> l >> r;
		int x = l - 1;
		ll ans = 0;
		while(p[x] <= r - 1) {
			ans += c[x];
			x = p[x];
		}
		ans += func(x + 1, r - 1);
		cout << ans << '\n';
	}
	return 0;
}