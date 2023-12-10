#include <iostream>
#include <cstring>

using i64 = long long;

int n, m, k, dist[10010], backup[10010];

struct node {
	int a, b, w;
} e[10010];

int bellman(int s) {
	memset(dist, 0x3f, sizeof dist);

	dist[s] = 0;

	for (int i = 0; i < k - 1; i ++) {
		memcpy(backup, dist, sizeof backup);
		for (int j = 1; j <= m; j ++) {
			int a = e[i].a, b = e[i].b, w = e[i].w;
			dist[b] = std::min(dist[b], backup[a] + w);
		}
	}

	if (dist[n] > 0x3f3f3f3f / 2) return -1; 
	else return dist[n];
}

int main() {
	std::cin >> n >> m >> k;

	for (int i = 1; i <= m; i ++) {
		int x, y, z;

		std::cin >> x >> y >> z;

		e[i] = {x, y, z};
	}
}