#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e5 + 10, M = 2e5 + 10;

int n, m;

int h[N], e[M], ne[M], idx;

int en[N];

std::vector<int> v1;

bool ok = true;

void add(int a, int b) {
	ne[idx] = h[a], h[a] = idx, e[idx ++] = b;
}

void bfs() {
	std::queue<int> q1;

	int ck = 0;

	for (int i = 1; i <= n; i ++) {
		if (!en[i]) {
			q1.push(i);
		}
	}

	if (q1.size() != 1) return ok = false, void(0);

	while (q1.size()) {
		int u = q1.front(); q1.pop();


		v1.push_back(u);

		ck ++;

		for (int i = h[u]; ~i; i = ne[i]) {
			int v = e[i];
			

			if (-- en[v] == 0) {
				q1.push(v);
			}
		}
	}

	if (ck != n) ok = false;
}

int main() {
	memset(h, -1, sizeof h);

	std::cin >> n >> m;

	std::vector<int> ans(n + 1);

	for (int i = 1; i <= m; i ++) {
		int x, y;
		
		std::cin >> x >> y;

		add(x, y);

		en[y] ++;
	}

	bfs();

	int cnt = 0;

	if (!ok) {
		puts("No");
	} else {
		puts("Yes");
		
		for (auto x: v1) {
			ans[x] = ++ cnt;
		}

		for (int i = 1; i <= n; i ++) {
			std::cout << ans[i] << " \n"[i == n];
		}
	}
}