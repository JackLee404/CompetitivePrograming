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

    std::vector<int> a(n + 1), cost(n + 1, -1);

    std::vector<std::vector<int>> G(n + 1);

    std::vector<i64> dp(n + 1, -1);

    for (int i = 1; i <= n; i ++) cost[i] = nxt<int>();
    for (int i = 1; i <= k; i ++) cost[nxt<int>()] = 0;
    	
    for (int i = 1; i <= n; i ++) {
    	G[i].resize(nxt<int>());

    	for (auto &x: G[i]) std::cin >> x;
    }

	std::function<i64(int)> dfs = [&](int u) {
		if (~dp[u]) return dp[u];
		if (G[u].empty()) return (i64) cost[u];

		i64 ans = 0;

		for (auto &x: G[u]) {
			ans += dfs(x);
		}

		return dp[u] = std::min(ans, (i64) cost[u]);
	};

	for (int i = 1; i <= n; i ++) {
		std::cout << dfs(i) << " \n"[i == n];
	}
}

int main() {
    int _ = nxt<int>();
    while (_ --) { solve(); }
}