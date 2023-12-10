#include <bits/stdc++.h>

using i64 = long long;

std::string a = "314159265358979323846264338327950288419716939937510";

void solve() {
	std::string t;

	std::cin >> t;

	int ans = 0;

	while(ans < t.size() && t[ans] == a[ans]) {
		ans ++;
	}

	std::cout << ans << "\n";
}

int main() {
	int _;
	std::cin >> _;
	while(_ --){
		solve();
	}
}