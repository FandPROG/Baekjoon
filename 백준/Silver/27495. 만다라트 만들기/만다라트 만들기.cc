#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct dat{
	int idx;
	string s;
};

string mp[10][10];
vector <string> vec[10];
vector <dat> vc;

bool comp(dat a, dat b)
{
	return a.s < b.s;
}

int main()
{
	int i, j;
	for (i = 1; i <= 9; i++) {
		for (j = 1; j <= 9; j++) {
			cin >> mp[i][j];
		}
	}
	vc.push_back({ 0, mp[4][4] });
	vc.push_back({ 1, mp[4][5] });
	vc.push_back({ 2, mp[4][6] });
	vc.push_back({ 3, mp[5][4] });
	vc.push_back({ 4, mp[5][6] });
	vc.push_back({ 5, mp[6][4] });
	vc.push_back({ 6, mp[6][5] });
	vc.push_back({ 7, mp[6][6] });
	for (i = 1; i <= 3; i++) {
		for (j = 1; j <= 3; j++) {
			if (mp[i][j] == mp[4][4]) continue;
			vec[0].push_back(mp[i][j]);
		}
	}

	for (i = 1; i <= 3; i++) {
		for (j = 4; j <= 6; j++) {
			if (mp[i][j] == mp[4][5]) continue;
			vec[1].push_back(mp[i][j]);
		}
	}

	for (i = 1; i <= 3; i++) {
		for (j = 7; j <= 9; j++) {
			if (mp[i][j] == mp[4][6]) continue;
			vec[2].push_back(mp[i][j]);
		}
	}

	for (i = 4; i <= 6; i++) {
		for (j = 1; j <= 3; j++) {
			if (mp[i][j] == mp[5][4]) continue;
			vec[3].push_back(mp[i][j]);
		}
	}

	for (i = 4; i <= 6; i++) {
		for (j = 7; j <= 9; j++) {
			if (mp[i][j] == mp[5][6]) continue;
			vec[4].push_back(mp[i][j]);
		}
	}

	for (i = 7; i <= 9; i++) {
		for (j = 1; j <= 3; j++) {
			if (mp[i][j] == mp[6][4]) continue;
			vec[5].push_back(mp[i][j]);
		}
	}

	for (i = 7; i <= 9; i++) {
		for (j = 4; j <= 6; j++) {
			if (mp[i][j] == mp[6][5]) continue;
			vec[6].push_back(mp[i][j]);
		}
	}

	for (i = 7; i <= 9; i++) {
		for (j = 7; j <= 9; j++) {
			if (mp[i][j] == mp[6][6]) continue;
			vec[7].push_back(mp[i][j]);
		}
	}

	sort(vc.begin(), vc.end(), comp);
	for (i = 0; i < 10; i++) sort(vec[i].begin(), vec[i].end());
	
	for (i = 0; i < vc.size(); i++) {
		printf("#%d. ", i + 1);
		cout << vc[i].s << '\n';
		for (j = 0; j < vec[vc[i].idx].size(); j++) {
			printf("#%d-%d. ", i + 1, j + 1);
			cout << vec[vc[i].idx][j] << '\n';
		}
	}
	return 0;
}