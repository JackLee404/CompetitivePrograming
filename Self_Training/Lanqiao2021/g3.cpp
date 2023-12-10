#include <iostream>
#include <cstring>

using i64 = long long;

const int N = 1e3 + 10;

int n, m, s, e;
int dist[N], g[N][N];
bool st[N];


void dijkstra(int s) {
	memset(dist, 0x3f, sizeof dist);

	dist[s] = 0;	

	for(int i = 0; i < n - 1; i ++) {
		int t = -1;

		for(int j = 1; j <= n; j ++)
			if(!st[j] && (t == -1 || dist[t] > dist[j]))
				t = j;

		st[t] = true;

		for(int j = 1; j <= n; j ++)
			dist[j] = std::min(dist[j], dist[t] + g[t][j]);
	}
}

int main() {
	memset(g, 0x3f, sizeof g);
	
	std::cin >> n >> m;

	for(int i = 1; i <= m; i ++) {
		int x, y, z;

		std::cin >> x >> y >> z;

		g[x][y] = std::min(g[x][y], z);
	}

	s = 1, e = n;

	dijkstra(s);

	std::cout << (dist[e] == 0x3f3f3f3f?-1:dist[e]);
}