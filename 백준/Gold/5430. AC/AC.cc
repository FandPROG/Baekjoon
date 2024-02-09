#include <stdio.h>
#include <deque>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

int t, n;

int main()
{
	int i, j;
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		char s[100010];
		scanf("%s", s);
		scanf("%d", &n);
		char s2[300000];
		scanf("%s", s2);
		deque <int> dq;
		int l1 = strlen(s), l2 = strlen(s2);
		int cnt = 0, ch = 0;
		vector <int> k;
		for (j = 0; j < l2; j++) {
			int k_size = k.size();
			if (s2[j] == '[' || s2[j] == ']') continue;
			if (s2[j] == ',') {
				int k_sum = 0;
				for (int l = 0; l < k_size; l++) {
					k_sum += k[l] * pow(10, k.size() - l - 1);
				}
				dq.push_back(k_sum);
				cnt = 0;
				for (int l = 0; l < k_size; l++) k.pop_back();
			}
			else {
				k.push_back(s2[j] - '0');
				ch = 1;
			}
		}
		if (ch == 1) {
			int k_sum = 0;
			for (int l = 0; l < k.size(); l++) {
				k_sum += k[l] * pow(10, k.size() - l - 1);
			}
			dq.push_back(k_sum);
		}
		int error = 0, rev = 0;
		for (j = 0; j < l1; j++) {
			if (s[j] == 'R') {
				if (rev == 1) rev = 0;
				else rev = 1;
			}
			else {
				if (dq.size() <= 0) {
					printf("error\n");
					error = 1;
					break;
				}
				else if (rev == 1) dq.pop_back();
				else dq.pop_front();
			}
		}
		if (rev == 1) reverse(dq.begin(), dq.end());
		if (error == 0) {
			printf("[");
			for (j = 0; j < dq.size(); j++) {
				printf("%d", dq[j]);
				if (j < dq.size() - 1) printf(",");
			}
			printf("]\n");
		}
	}
	return 0;
}