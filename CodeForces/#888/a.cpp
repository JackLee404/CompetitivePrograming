#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
inline T nxt() {
	T x;
	std::cin >> x;
	return x;
}

std::map<i64, bool> mp;

void solve() {

    int n, m, k, h;

    std::cin >> n >> m >> k >> h;

    int ans = 0;

    for (int i = 1; i <= n; i ++) {
        int x = nxt<int>();

        int diff = std::abs(h - x);

        if (!diff || diff % k) continue;

        diff /= k;

        // std::cout << diff << "\n";

        if (diff <= (m - 1) && diff >= 1) {
            ans ++;
        }
    }

    std::cout << ans << "\n";
}

int main() {
    int _ = nxt<int>();
    while (_ --) { solve(); }
}