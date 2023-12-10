#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e5 + 10, M = 2e5 + 10;

int n;

int h[N], ne[M], e[M], idx;

int en[N];

bool st[N];

void add(int a, int b) {
	ne[idx] = h[a], h[a] = idx, e[idx ++] = b;
}

void bfs() {
	std::queue<int> q1;

	for (int i = 1; i <= n; i ++) {
		if (en[i] == 1) q1.push(i);
	}

	if (!q1.size()) q1.push(n + 1);

	while (q1.size()) {
		int u = q1.front(); q1.pop();

		st[u] = true;
		
		for (int i = h[u]; ~i; i = ne[i]) {
			int v = e[i];

			en[v] --;

			if (en[v] == 1)
				q1.push(v);
		}
	}
}

int main() {
	memset(h, -1, sizeof h);
	
	std::cin >> n;

	for (int i = 1; i <= n; i ++) {
		int a, b;

		std::cin >> a >> b;

		add(a, b), add(b, a);

		en[b] ++, en[a] ++;
	}	

	bfs();

	for (int i = 1; i <= n; i ++) {
		if (!st[i]) {
			std::cout << i << " ";
		}
	}
}