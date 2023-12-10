#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using i64 = long long;

const int N = 1e3 + 10, M = 2e4 + 10;

int n, m, dist[N][2], cnt[N][2];

bool st[N][2];

int h[N], ne[M], w[M], e[M], idx;

int S, T;

void add(int a, int b, int c) {
	ne[idx] = h[a], h[a] = idx, e[idx] = b, w[idx ++] = c;
}

struct Ver {
	int x, type, val;

	bool operator>(const Ver &b) const {
		return val > b.val;
	}
};

int dijkstra() {
	memset(dist, 0x3f, sizeof dist);
	memset(st, 0, sizeof st);
	memset(cnt, 0, sizeof cnt);

	std::priority_queue<Ver, std::vector<Ver>, std::greater<Ver>> h1;

	h1.push({S, 0, 0});

	dist[S][0] = 0;

	cnt[S][0] = 1;

	while (h1.size()) {
		Ver t = h1.top(); h1.pop();

		int x = t.x, type = t.type, val = t.val, count = cnt[x][type];

		if (st[x][type]) continue;

		st[x][type] = true;

		// std::cout << x << " " << type << "\n";

		for (int i = h[x]; ~i; i = ne[i]) {
			int v = e[i];

			if (dist[v][0] > val + w[i]) {
				dist[v][1] = dist[v][0], cnt[v][1] = cnt[v][0];
				h1.push({v, 1, dist[v][1]});
				dist[v][0] = val + w[i], cnt[v][0] = count;
				h1.push({v, 0, dist[v][0]});
			} else if (dist[v][0] == val + w[i]) {
				cnt[v][0] += count;
				h1.push({v, 0, dist[v][0]});
			} else if (dist[v][1] > val + w[i]) {
				dist[v][1] = val + w[i], cnt[v][1] = count;
				h1.push({v, 1, dist[v][1]});
			} else if (dist[v][1] == val + w[i]) {
				cnt[v][1] += count;
				h1.push({v, 1, dist[v][1]});
			}
		}
	}

	int res = cnt[T][0];

	if (dist[T][0] + 1 == dist[T][1]) res += cnt[T][1];

	return res;
}

void solve() {
	memset(h, -1, sizeof h);
    idx = 0;
    
	std::cin >> n >> m;

	for (int i = 1; i <= m; i ++) {
		int a, b, l;

		std::cin >> a >> b >> l;

		add(a, b, l);
	}

	std::cin >> S >> T;

	std::cout << dijkstra() << "\n";
}

int main() {
	int _;

	std::cin >> _;

	while (_ --) {
		solve();
	}
}