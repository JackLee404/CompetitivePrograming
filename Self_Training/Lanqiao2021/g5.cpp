#include <iostream>
#include <cstring>
#define INF 0x3f3f3f3f
using i64 = long long;

const int N = 600, M = 1e4 + 10;

struct edge{int a, b, w;};

int n, m, k;
int dist[N], backup[N];
edge e[M];

bool bellman_ford(int k) {
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	bool flag;

	for(int i = 1; i <= k; i ++) {
		memcpy(backup, dist, sizeof dist);
		flag = false;
		for(int j = 1; j <= m; j ++) {
			int a = e[j].a, b = e[j].b, w = e[j].w;
			if(dist[b] > dist[a] + w)
				dist[b] = dist[a] + w, flag = true;
		}
	}

	if(flag) return false;

	return true;
}

int main() {
	std::cin >> n >> m >> k;

	for(int i = 1; i <= m; i ++) {
		int x, y, z;

		std::cin >> x >> y >> z;

		e[i] = {x, y, z};
	}

	bellman_ford(k);

	std::cout << (dist[n] > INF / 2?-1:dist[n]);
}