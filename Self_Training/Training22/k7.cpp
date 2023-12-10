#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define debug(x) std::cout << x << "\n"
using i64 = long long;

const int N = 3e4, M = 2e5;

int t, r, p, s;

int h[N], ne[M], e[M], w[M], idx;

int dist[N], id[N], en[N], bcnt;

std::vector<int> block[N];

std::queue<int> q1;

bool st[N];

void add(int a, int b, int c) {
	ne[idx] = h[a], h[a] = idx, e[idx] = b, w[idx ++] = c;
}

void dfs(int u, int cnt) {
	block[cnt].push_back(u);
	id[u] = cnt;

	// debug(u);
	
	for (int i = h[u]; ~i; i = ne[i]) {
		int j = e[i];
		if (!id[j]) {
			dfs(j, cnt);
		}
	}
}

void dijkstra(int t) {
	std::priority_queue<std::pair<int, int>> h1;

	for (auto x: block[t]) h1.push({-dist[x], x});

	while (h1.size()) {
		auto t = h1.top(); h1.pop();

		int u = t.second;

		if (st[u]) continue;
		st[u] = true;

		for (int i = h[u]; ~i; i = ne[i]) {
			int j = e[i];

			// 不是一个连通块入度--
			if (id[j] != id[u] && -- en[id[j]] == 0) {
				q1.push(id[j]);
			}

			if (dist[j] > dist[u] + w[i]) {
				// 不管是不是都要更新边权， 应为拓扑序保证了更新结果为最短路
				dist[j] = dist[u] + w[i];

				// 是一个连通块就入堆
				if (id[j] == id[u])
					h1.push({-dist[j], j});
			}
		}
	}
}

void topsort() {
	memset(dist, 0x3f, sizeof dist);

	dist[s] = 0;

	for (int i = 1; i <= bcnt; i ++)
		if (!en[i])
			q1.push(i);	
		
	while (q1.size()) {
		int t = q1.front();
		q1.pop();
		dijkstra(t);
	}
}

int main() {

	std::ios::sync_with_stdio(false);
	
	memset(h, -1, sizeof h);

	std::cin >> t >> r >> p >> s;

	for (int i = 1; i <= r; i ++) {
		int a, b, c;

		std::cin >> a >> b >> c;

		add(a, b, c);
		add(b, a, c);
	}

	for (int i = 1; i <= t; i ++) {
		if (!id[i]) {
			dfs(i, ++ bcnt);
		}
	}

	for (int i = 1; i <= p; i ++) {
		int a, b, c;

		std::cin >> a >> b >> c;

		add(a, b, c);

		en[id[b]] ++;
	}

	topsort();

	for (int i = 1; i <= t; i ++) {
		if (dist[i] >= 0x3f3f3f3f / 2) std::cout << "NO PATH\n";
		else std::cout << dist[i] << "\n";
	}
}