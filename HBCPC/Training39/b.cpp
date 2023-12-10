#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	std::string l, r, lead;

	int d1, d2;

	std::cin >> l >> r;

	d1 = l.size(), d2 = r.size();

	lead = std::string((int) r.size() - (int) l.size(), '0');

	l = lead + l;

	int pos = 0, ans = 0;

	int ok = 0;

	for (int i = pos; i < r.size(); i ++) {
		if (ok == 1) {
			ans += 9;
		} else {
			if (r[i] != l[i]) ok = 1;
			ans += std::abs(r[i] - l[i]);	
		}
	}

	std::cout << ans << "\n";
}

int main() {
	int _;

	std::cin >> _;

	while (_ --) { solve(); }
}