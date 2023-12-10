#include <iostream>
#include <cmath>
#include <queue>
#include <map>
#define ff first
#define ss second
using i64 = long long;

const int N = 1e5 + 10;

double dist(int x1, int y1, int x2, int y2) {
	int a1 = (x1 - x2), a2 = (y1 - y2);
	return a1 * a1 + a2 * a2;
}

int n, d;

std::map<std::pair<int, int>, int> mp;

std::pair<int, int> a[N];

bool st[N];

std::vector<int> v1[2100];

void dfs(int u) {
	st[u] = true;

	for (auto &x: v1[u]) {
		if (st[x]) continue;
		dfs(x);
	}
}

int main() {
	std::cin >> n >> d;

	for (int i = 1; i <= n; i ++) {
		std::cin >> a[i].ff >> a[i].ss;
	}

	for (int i = 1; i <= n; i ++) {
		for (int j = i + 1; j <= n; j ++) {
			if (dist(a[i].ff, a[i].ss, a[j].ff, a[j].ss) <= d * d) {
				v1[i].push_back(j);
				v1[j].push_back(i);
			}
		}
	}

	dfs(1);

	for (int i = 1; i <= n; i ++) {
		puts(st[i]?"Yes":"No");
	}
}