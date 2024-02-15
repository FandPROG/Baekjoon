#include <stdio.h>
#include <string.h>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int i, j;
	while (1) {
		char s[30];
		vector <int> v1, v2;
		vector <int> ans_m;
		int n = 0, m = 0;
		scanf("%s", s);
		int l = strlen(s);
		int ch = 0;
		for (i = 0; i < l; i++) {
			if (s[i] == 'R') ch = 1;
			else if (s[i] == 'C') ch = 2;
			else {
				if (ch == 1) {
					v1.push_back(s[i] - '0');
				}
				if (ch == 2) {
					v2.push_back(s[i] - '0');
				}
			}
		}
		for (i = 0; i < v1.size(); i++) n += (v1[v1.size() - 1 - i] * pow(10, i));
		for (i = 0; i < v2.size(); i++) m += (v2[v2.size() - 1 - i] * pow(10, i));
		if (n == 0 && m == 0) break;// n = 그대로
		while(m > 0) {
			m--;
			ans_m.push_back(m % 26);
			m = m / 26;
		}
		for (i = ans_m.size() - 1; i >= 0; i--) printf("%c", 'A' + ans_m[i]);
		printf("%d\n", n);
	}
	return 0;
}