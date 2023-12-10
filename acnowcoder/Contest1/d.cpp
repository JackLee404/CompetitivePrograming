#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
inline T nxt() {
	T x;
	std::cin >> x;
	return x;
}

void solve() {
    int k, c, n;

    std::cin >> k >> c >> n;

    int ans = 0;

    std::map<std::pair<int, int>, int> mp;

    auto act = [&](int b) {
        if ((c - b) % k != 0) return;
         
        int a = (c - b) / k;

        if (mp[{a, b}]) return;

        if (!a || !b) return;

        if (std::__gcd(a, b) >= n) {
            ans ++;
            mp[{a, b}] = 1;
        }
    };

    for (int i = 1; i <= std::sqrt(c); i ++) {
        if (c % i != 0) continue;

        act(i), act(c / i);
    }

    std::cout << ans << "\n";
}

int main() {
    int _ = nxt<int>();
    while (_ --) { solve(); }
}