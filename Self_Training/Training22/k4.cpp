#include <bits/stdc++.h>
#define PII std::pair<int, int>
#define ff first
#define ss second

using i64 = long long;

const int N = 5e4 + 10, M = 1e5 + 10;

int n, m, a[10], dist[N];

int ne[M], e[M], h[N], w[N], idx;

int d[10][10];

std::unordered_map<int, int> pos;

bool st[N];

void add(int a, int b, int c) {
	ne[idx] = h[a], h[a] = idx, e[idx] = b, w[idx ++] = c;
}

void dijkstra(int s) {
	memset(st, false, sizeof st);
	memset(dist, 0x3f, sizeof dist);

	std::priority_queue<PII> q1;

	dist[s] = 0;

	q1.push({0, s});

	while (q1.size()) {
		PII t = q1.top(); q1.pop();
		
		int u = t.ss;

		if (st[u]) continue;

		st[u] = true;

		for (int i = h[u]; ~i; i = ne[i]) {
			int v = e[i];
			if (dist[v] > dist[u] + w[i]) {
				dist[v] = dist[u] + w[i];
				q1.push({-dist[v], v});
			}	
		}
	}
}

int main() {
	memset(h, -1, sizeof h);
	
	std::cin >> n >> m;

	for (int i = 1; i <= 5; i ++) 
		std::cin >> a[i], pos[a[i]] = i;

	for (int i = 1; i <= m; i ++) {
		int x, y, t;
		
		std::cin >> x >> y >> t;	

		add(x, y, t);
		add(y, x, t);		
	}

	for (int i = 1; i <= 5; i ++) {
		dijkstra(a[i]);

		for (int j = 1; j <= 5; j ++) {
			d[i][j] = dist[a[j]];
		}
	}

	dijkstra(1);

	i64 ans = 0x3f3f3f3f;
	
	do {
		i64 res = dist[a[1]];
		for (int i = 2; i <= 5; i ++) {
			res += d[pos[a[i - 1]]][pos[a[i]]];
		}
		ans = std::min(ans, res);
	} while (std::next_permutation(a + 1, a + 1 + 5));

	std::cout << ans << "\n";
}