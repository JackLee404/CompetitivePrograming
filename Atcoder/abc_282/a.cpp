#include <iostream>
#include <map>

using namespace std;

map<pair<int, int>, bool> mp;

int main() {
	int n, m, ans = 0;
	string a[40];
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			if (j == i || mp[make_pair(i, j)] || mp[make_pair(j, i)]) continue;		
			bool check = true;
			for (int l = 0; l < m; l ++) {
				if (a[i][l] == 'x' && a[j][l] == 'x') {
					check = false;
					break;
				}
			}
			mp[make_pair(i, j)] = true, mp[make_pair(j, i)] = true;
			if (check)  ans ++;
		}
	}
	cout << ans;
}