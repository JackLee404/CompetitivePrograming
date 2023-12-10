#include <iostream>
#include <cstring>

using i64 = long long;

const double EPS = 1e-8;

int n, m;

int e[200010], ne[200010], h[2010], w[200010], idx;

double dist[2010];

bool st[2010];

void add(int a, int b, int k) {
	ne[idx] = h[a], h[a] = idx, w[idx] = k, e[idx ++] = b;
}

void dijkstra(int s) {
	for (int i = 1; i <= n; i ++) dist[i] = 0x3f3f3f3f;

	dist[s] = 100;

	for (int i = 0; i < n - 1; i ++) {
		int t = -1;

		for (int j = 1; j <= n; j ++)
			if (!st[j] && (t == -1 || dist[t] > dist[j]))	
				t = j;
		
		st[t] = true;


		for (int j = h[t]; ~j; j = ne[j]) {
			int &v = e[j], w1 = w[j];

			if (dist[v] - dist[t] / (1 - (w1 * 1.0 / 100)) > EPS) {
				dist[v] = dist[t] / (1 - (w1 * 1.0 / 100));
			}
		}
	}
}

int main() {
	memset(h, -1, sizeof h);

	std::cin >> n >> m;

	for (int i = 1; i <= m; i ++) {
		int x, y, z;

		std::cin >> x >> y >> z;

		add(x, y, z);
		add(y, x, z);
	}

	int s1, e1;

	std::cin >> s1 >> e1;

	dijkstra(e1);

	printf("%.8lf", dist[s1]);
}