#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <utility>
using namespace std;

const int N = 2e5 + 10;

int a[N];

/* 
	1 1 0 0
	0 1 0 0
*/

void solve() {
	map<int, int> mp;
	int n;
	cin >> n;
	vector<vector<int>> c(n);
	for(auto &x: c) {
		int k;
		cin >> k;
		x.resize(k);
		for(auto &y: x)
			cin >> y, mp[y] ++;
	}

	for(auto &x: c) {
		int ok = 1;
		for(auto &y: x) {
			if(mp[y] == 1) {
				ok = 0;
			}
		}
		if (ok) {
			cout << "Yes\n";
			return;
		}
	}
	cout << "No\n";
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while(t --) {
		solve();
	}
}