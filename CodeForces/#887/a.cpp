#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
inline T nxt() {
	T x;
	std::cin >> x;
	return x;
}

void solve() {
    int n; std::cin >> n;

    std::vector<int> a(n);

    for (auto &x: a) std::cin >> x;


    int ans = 1e9;

    for (int i = 1; i < n; i ++) {
    	ans = std::min(a[i] - a[i - 1], ans);
    }
    
    if (ans < 0) {
    	return std::cout << 0 << "\n", void(0);
    }

    std::cout << std::max(0, (ans / 2 + 1)) << "\n";
}

int main() {
    int _ = nxt<int>();
    while (_ --) { solve(); }
}