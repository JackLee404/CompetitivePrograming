#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
inline T nxt() {
	T x;
	std::cin >> x;
	return x;
}

void solve() {
    int n;

    std::cin >> n;

    if (n > 4) {
    	puts("Alice");
    } else {
    	puts("Bob");
    }
}

int main() {
    int _ = nxt<int>();
    while (_ --) { solve(); }
}