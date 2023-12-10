#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
inline T nxt() {
	T x;
	std::cin >> x;
	return x;
}

void solve() {
    int n = nxt<int>();

    std::vector<int> a(n), b(n);

    for (auto &x: a) std::cin >> x;

    for (auto &x: b) std::cin >> x;

    // a - b --> b - (a - b) --> (a - b) - (b - (a - b)) -->
    // a - b -> 2b - a -> 2a - 3b -->  (2b - a) - (2a - 3b)
}

int main() {
    int _ = nxt<int>();
    while (_ --) { solve(); }
}