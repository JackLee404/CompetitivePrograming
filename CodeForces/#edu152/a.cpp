#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
inline T nxt() {
	T x;
	std::cin >> x;
	return x;
}

void solve() {
    int b, c, h;

    std::cin >> b >> c >> h;

    if (c + h >= b - 1) {
    	std::cout << 2 * b - 1 << "\n";
    } else {
    	std::cout << 2 * (c + h) + 1 << "\n";
    }
}

int main() {
    int _ = nxt<int>();
    while (_ --) { solve(); }
}