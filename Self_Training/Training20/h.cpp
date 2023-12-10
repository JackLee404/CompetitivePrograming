#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e5 + 10;

int n, m;

int en[N];

bool st[N];

std::vector<int> g[N];


void topsort() {
	std::priority_queue<int> q1;

	std::vector<int> ans;


	for (int i = 1; i <= n; i ++) {
		if (!en[i]) {
			q1.push(i);
		}
	}

	// if (!q1.size()) {
	// 	for (int i = 1; i <= 5; i ++) {
	// 		std:
	// 	}
	// }


	while (q1.size()) {
		int t = q1.top(); q1.pop();

		ans.push_back(t);

		// bool
		// if ()

		// std::cout << t << " ";

		for (auto x: g[t]) {
			if (-- en[x] == 0) {
				q1.push(x);
			}
		}
	}

	if (ans.size() != n || !ans.size()) {
		puts("-1 ");
	} else {
		for (int i = 0; i < n; i ++) {
			std::cout << ans[i] << " ";
		}

		std::cout << "\n";
	}
}

void solve() {
	memset(en, 0, sizeof en);
	std::cin >> n >> m;

	for (int i = 1; i <= n; i ++) g[i].clear();

	while (m --) {
		int a, b;

		std::cin >> a >> b;

		en[a] ++;

		g[b].push_back(a);
	}

	topsort();
}

int main() {
	int t;

	std::cin >> t;

	while (t --) {
		solve();
	}
}