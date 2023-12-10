#include <bits/stdc++.h>
#include <numeric>

#define all(x) (x).begin(), (x).end()

using i64 = long long;

bool ok;

struct dsu {
	std::vector<size_t> pa, size;

	std::vector<i64> sum;

	explicit dsu(size_t size_) : pa(size_ + 1), size(size_ + 1, 1), sum(size_ + 1, 0) {
		iota(pa.begin(), pa.end(), 0);
	}

	void unite(size_t x, size_t y, i64 d) {
		size_t fx = find(x), fy = find(y);
		if (fx == fy && sum[y] - d != sum[x]) ok = false;
		if (fx == fy) {
			return;
		}
		pa[fy] = fx;
		sum[fy] = sum[x] - sum[y] + d;
	}

	size_t find(size_t x) {
		if (x != pa[x]) {
			size_t t = pa[x];
			pa[x] = find(pa[x]);
			sum[x] += sum[t];
		}
		return pa[x];
	}
};

inline int nxt() {
	int x; 
	std::cin >> x;
	return x;
}

void solve() {
	int n = nxt(), m = nxt();

	ok = true;

	dsu tree(n + 1);

	while (m --) {
		int a = nxt(), b = nxt(), c = nxt();

		tree.unite(a, b, c);
	}

	puts(ok?"YES":"NO");
}

int main() {
	int _;

	std::cin >> _;

	while (_ --) { solve(); }
}