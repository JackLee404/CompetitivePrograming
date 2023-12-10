#include <bits/stdc++.h>

const int N = 1e5 + 10;

using namespace std;

map<string, int> mp;
stack<int> s1[N];

int main() {
	int n, s;
	cin >> n >> s;
	vector<string> v1(n);
	for (auto &x: v1) {
		cin >> x;
	}
	for (int i = 1; i <= n / s; i ++) {
		for (int j = 1; j <= s; j ++) {
			int t; cin >> t; s1[i].push(t);
		}
	}
	int pos = 1;
	for (auto &x: v1) {
		while (s1[pos].size() == 0) {
			pos ++;
		}
		if (s1[pos].size()) {
			mp[x] = s1[pos].top();
		}
	}
	int q; cin >> q;
	while (q --){
		string t; cin >> t;
		if (mp.count(t)) {
			cout << mp[t];
		} else {
			cout << "Wrong Number";
		}
		cout << "\n";
	}
}