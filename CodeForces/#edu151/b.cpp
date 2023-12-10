#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
inline T nxt() {
	T x;
	std::cin >> x;
	return x;
}

void out(int n, int x) {
   	std::cout << "YES\n" << n << "\n";
	for (int i = 1; i <= n; i ++) {
		std::cout << x << " \n"[i == n];
	}
}

void solve() {
	int x[4], y[4];

	for (int i = 0; i <= 2; i ++) std::cin >> y[i] >> x[i];
	
	int t = 0;

	if ((y[0] <= y[1]) == (y[0] <= y[2])) {
		t += std::min(std::abs(y[0] - y[1]), std::abs(y[0] - y[2])) + 1;
	} else t ++;

	if ((x[0] <= x[1]) == (x[0] <= x[2])) {
		t += std::min(std::abs(x[0] - x[1]), std::abs(x[0] - x[2])) + 1;
	} else t ++;

	std::cout << t - 1 << "\n";
}

int main() {
    int _ = nxt<int>();
    while (_ --) { solve(); }
}