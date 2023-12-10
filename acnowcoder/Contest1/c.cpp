#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
inline T nxt() {
	T x;
	std::cin >> x;
	return x;
}

const int N = 6e3 + 10;

int g[N][N];

void solve() {
    int n = nxt<int>();

    int ans = 0;

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            std::cin >> g[i][n + j];
            if (g[i][n + j]) ans ++;
        }
    }

    std::cout << ans << "\n";
}

int main() {
    int _ = nxt<int>();
    while (_ --) { solve(); }
}