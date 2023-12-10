#include <bits/stdc++.h>
#include <bitset>
#include <sstream>

using i64 = long long;

const int N = 1e5 + 10, M = 2e5 + 10;

int n, m;

int h[N], ne[M], e[M], en[N], idx;

bool st[N], st2[N];

std::bitset<N> f[N];

std::vector<int> v1;

void add(int a, int b) {
	ne[idx] = h[a], h[a] = idx, e[idx ++] = b;
}

void topsort() {
	std::queue<int> q1;

	for (int i = 1; i <= n; i ++)
		if (!en[i]) q1.push(i);

	while (q1.size()) {
		int u = q1.front(); q1.pop();

		v1.push_back(u);

		for (int i = h[u]; ~i; i = ne[i]) {
			int v = e[i];

			if (-- en[v] == 0)  {
				q1.push(v);	
			}
		}
	}
}

int main() {
	memset(h, -1, sizeof h);

	std::cin >> n >> m;

	for (int i = 0; i < m; i ++) {
		int a, b;
		
		std::cin >> a >> b;

		add(a, b), en[b] ++;		
	}

	topsort();

	std::reverse(v1.begin(), v1.end());

	for (auto &x: v1) {
		for (int i = h[x]; ~i; i = ne[i]) {
			int v = 	
		}
	}
}
