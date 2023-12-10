#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int a, b, c;

	std::cin >> a >> b >> c;

	if (std::max({a + b, a + c, b + c}) >= 10) {
		puts("YES");
	} else {
		puts("NO");
	}
}



int main() {
	int _;

	std::cin >> _;

	while (_ --) { solve(); }
}