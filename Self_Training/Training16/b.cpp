#include <iostream>
#include <cstring>

using i64 = long long;

const int N = 500;

int n, m;
int g[N][N], dist[N];
bool st[N];

void dijkstra(int s) {
	dist[s] = 0;
	
	for (int i = 0; i < 30; i++) {
		int t = -1;

		for (int j = 1; j <= n; j++)
			if (!st[j] && (t == -1 || dist[t] > dist[j]))
				t = j;
		
		st[t] = true;

		for (int j = 1; j <= n; j ++)
			dist[j] =  std::min(dist[j], dist[t] + g[t][j]);
	}
}

int main() {
	// std::cin >> n;

	memset(dist, 0x3f, sizeof dist);

	int s = 'A' - 'A', e = 'S' - 'A';

	n = e + 1, m = 18 + 8 + 8;

	for (int i = 1; i <= m; i++) {
		char c1, c2;
		int a, b, c;

		std::cin >> c1 >> c2 >> c;
		a = c1 - 'A' + 1, b = c2 - 'A' + 1;
		g[a][b] = g[b][a] = c;
	}

	dijkstra(s);

	std::cout << dist[e];
}