#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
inline T nxt() {
	T x;
	std::cin >> x;
	return x;
}

struct dsu {
	std::vector<size_t> pa, size;

	explicit dsu(size_t size_) : pa(size_), size(size_, 1) { iota(pa.begin(), pa.end(), 0); }

	size_t find(size_t x) { return pa[x] == x? x: pa[x] = find(pa[x]); }

	void unite(size_t x, size_t y) {
		x = find(x), y = find(y);
		if (x == y) return;
		if (size[x] < size[y]) std::swap(x, y);
		pa[y] = x, size[x] += size[y];
	}

	bool check(size_t x, size_t y) {
		return find(x) == find(y);
	}
};

void solve() {
	int n, m;

	std::cin >> n >> m;

	std::vector<int> h(n + 1);

	for (int i = 1; i <= n; i ++) std::cin >> h[i];

	std::vector<std::pair<int, int>> edges(m);

	for (auto &[u, v]: edges) std::cin >> u >> v;

	std::sort(edges.begin(), edges.end(), [&](const std::pair<int, int>& A, const std::pair<int, int>& B) {
		auto [uA, vA] = A; auto [uB, vB] = B;
		return std::max(h[uA], h[vA]) < std::max(h[uB], h[vB]);
	});
	
	int q;
	
	std::cin >> q;
	
	std::vector<std::tuple<int, int, int, int>> query(q);

	for (int i = 0; i < q; i ++) {
		auto& [a, b, e, idx] = query[i];
		std::cin >> a >> b >> e;
		idx = i;
	}

	std::sort(query.begin(), query.end(), [&](const std::tuple<int, int, int, int>& A, const std::tuple<int, int, int, int> &B) {
		auto [aA, bA, eA, iA] = A; auto [aB, bB, eB, iB] = B;
		return h[aA] + eA < h[aB] + eB;
	});

	std::vector<std::string> ans(q, "NO");

	dsu tree(n + 1);

	for (int i = 0, j = 0; i < q; i ++) {
		auto [a, b, e, idx] = query[i];
		int lim = h[a] + e;

		while (j < m) {
			auto [u, v] = edges[j];
			int w = std::max(h[u], h[v]);

			if (w <= lim) {
				tree.unite(u, v);
				j ++;
			} else break;
		}	

		if (tree.check(a, b))  ans[idx] = "YES";
	}

	for (auto ai: ans) std::cout << ai << "\n";
}

int main() {
    int _ = nxt<int>();
    while (_ --) { solve(); }
}