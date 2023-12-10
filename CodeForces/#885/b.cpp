#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
inline T nxt() {
	T x;
	std::cin >> x;
	return x;
}

void solve() {
	int n, k;

	std::cin >> n >> k;

	std::vector<int> lst(n, -1);

	std::vector<std::vector<int>> f(n);

	for (int i = 0; i < n; i ++) {
		int c = nxt<int>();
		c --;

		f[c].push_back(i - 1 - lst[c]);
		lst[c] = i;
	}

	int ans = n;

	for (int i = 0; i < k; i ++) {
		f[i].push_back(n - 1 - lst[i]);

		std::sort(f[i].begin(), f[i].end(), std::greater<int>());

		int res = f[i][0] / 2;

		if (f.size() > 1) res = std::max(res, f[i][1]);

		ans = std::min(res, ans);
	}

	std::cout << ans << "\n";
}

int main() {
    int _ = nxt<int>();
    while (_ --) { solve(); }
}