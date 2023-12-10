#include <bits/stdc++.h>
#include <algorithm>

using i64 = long long;

const int N = 3000;

struct edge{int v, w;};

int n, m;
int dist[N];
bool st[N];

std::vector<edge> v1[N];

int gcd(int a, int b) {
	return b == 0?a:gcd(b, a % b);
}

void add(int a, int b, int z) {
	v1[a].push_back({b, z});
	v1[b].push_back({a, z});
}

void init() {
	n = 2021;
	for(int i = 1; i <= 2021; i ++) {
		for(int j = i + 1; j <= 2021; j ++) {
			if(j - i <= 21) {
				int k = (i * j) / gcd(i, j);

				add(i, j, k);

				m ++;

				// std::cout << i << " " << j << " " << k << "\n";
			}
		}
	}
}

void dijkstra(int s) {
	memset(dist, 0x3f, sizeof dist);
	
	dist[s] = 0;

	for(int i = 0; i < n - 1; i ++) {
		int t = -1;

		for(int j = 1; j <= n; j ++)
			if(!st[j] && (t == -1 || dist[t] > dist[j]))
				t = j;

		st[t] = true;

		// dist[j] = dist[t] + g[t][j]

		for(auto &x: v1[t]) {
			int u = x.v, w = x.w;
			if(dist[u] > dist[t] + w) {
				dist[u] = dist[t] + w;
			}	
		}
	}
}

int main() {
	// std::cin >> n >> m;

	// for test

	// for(int i = 1; i <= m; i ++) {
	// 	int x, y, z;

	// 	std::cin >> x >> y >> z;

	// 	add(x, y, z);
	// }

	// std::cout << gcd(11, 15);

	init();

	dijkstra(1);

	// for(int i = 1; i <= n; i ++) {
	// 	std::cout << dist[i] << "\n";
	// }

	std::cout << dist[2021];
}