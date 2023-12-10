#include <bits/stdc++.h>
#include <numeric>

using i64 = long long;

struct DSU {
	std::vector<int> pa, f;

	int ans = 0x3f3f3f3f;

	explicit DSU(size_t size_): pa(size_ + 1), f(size_ + 1) {
		std::iota(pa.begin(), pa.end(), 0);
	}

	int find(size_t x) {
		if (pa[x] != x) {
			int t = find(pa[x]);
			f[x] += f[pa[x]];
			pa[x] = t;
		}	
		return pa[x];
	}

	void unite(size_t a, size_t b) {
		int fa = find(a), fb = find(b);
		if (fa != fb) {
			pa[fa] = pa[fb];
			f[fa] = f[b] - f[a] + 1;
		} else {
			ans = std::min(ans, f[a] + f[b] + 1);
		}
	}
};

void solve() {
	int n; std::cin >> n;

	DSU dsu(n + 1);

	for (int i = 1; i <= n; i ++) {
		int x; std::cin >> x;

		dsu.unite(i, x);
	}

	std::cout << dsu.ans;
}

int main() {
	int _ = 1;
	while (_ --) { solve(); }	
}