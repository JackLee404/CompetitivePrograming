#include <bits/stdc++.h>
#define PII std::pair<int, int>
using i64 = long long;

const int N = 1e5 + 10;

int n;

std::vector<int> g[N];

int d[N], d2[N], pre[N], en[N], start;

void bfs(int s) {
	memset(d, -1, sizeof d);
	std::queue<int> q1;

	q1.push(s);

	d[s] = 0;
	d2[s] = 0;

	while (q1.size()) {
		int t = q1.front(); q1.pop();

		int cnt = 0;

		for (auto x: g[t]) {
			if (d[x] == -1) {
				d[x] = d[t] + 1;
				d2[x] = d2[t] + cnt;
				pre[x] = t;
				q1.push(x);
			}
			cnt ++;
		}
	}
}

void out(int x) {
	if (x == start) {
		std::cout << start;
		return;
	}

	out(pre[x]);

	std::cout << " " << x;
}

int main() {
	std::cin >> n;

	for (int i = 0; i < n; i ++) {
		int k;
		std::cin >> k;

		for (int j = 1; j <= k; j ++) {
			int x;
			std::cin >> x;
			g[i].push_back(x);
			en[x] ++;
		}
	}

	// bfs(0);

	int ans = 0, mx = start;

	for (int i = 0; i < n; i ++) {
		if (!en[i]) {
			bfs(i);
			start = i;

			for (int i = 0; i <= n - 1; i ++) {
				if (d[i] > ans) {
					ans = d[i];
					mx = i;
				} else if(d[i] == ans && d2[i] < d2[mx]) {
					mx = i;
				}
			}
			break;
			// for (int i = 0; i <= n - 1; i ++) {
			// 	std::cout << d[i] << " \n"[i == n - 1];
			// }
			// for (int i = 0; i <= n - 1; i ++) {
			// 	std::cout << d2[i] << " \n"[i == n - 1];
			// }
		}
	}

	std::cout << ans << "\n";
	out(mx);
}