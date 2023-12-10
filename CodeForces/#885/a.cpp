#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
inline T nxt() {
	T x;
	std::cin >> x;
	return x;
}

void solve() {
	int n, m, k;

	std::cin >> n >> m >> k;


	bool caught = false;

	int x1, y1;

	std::cin >> x1 >> y1;

	for (int i = 0; i < k; i ++) {
		int x, y;

		std::cin >> x >> y;

		if ((x + y) % 2 == (x1 + y1) % 2)  caught = true;
	}

	puts(!caught? "YES": "NO");
}

int main() {
    int _ = nxt<int>();
    while (_ --) { solve(); }
}