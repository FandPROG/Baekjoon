#include <queue>
#include <string>
#include <iostream>

using namespace std;

int n;
queue <int> q;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
	int i, j;
	cin >> n;
	for (i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s == "push") {
			int x;
			cin >> x;
			q.push(x);
		}
		else if (s == "pop") {
			if (q.empty()) cout << "-1\n";
			else {
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (s == "size") {
			cout << q.size() << '\n';
		}
		else if (s == "empty") {
			if (q.empty()) cout << "1\n";
			else cout << "0\n";
		}
		else if (s == "front") {
			if (q.empty()) cout << "-1\n";
			else cout << q.front() << '\n';
		}
		else if (s == "back") {
			if (q.empty()) cout << "-1\n";
			else cout << q.back() << '\n';
		}
	}
	return 0;
}