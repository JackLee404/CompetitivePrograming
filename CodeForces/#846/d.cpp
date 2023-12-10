#include <bits/stdc++.h>

using i64 = long long;

int ask(int x) {
	int t;
	std::cout << "- " << x << std::endl;
	std::cin >> t;
	return t;
}

void solve() {
	int cnt;
	std::cin >> cnt;

	i64 last = 0, ans = 0, ot = 1;

	while(cnt > 0) {
		int curr_cnt = ask(ot);
		ans += 1ll<<(curr_cnt-cnt+1);			
		ot = 1ll<<(curr_cnt-cnt+1);
		cnt --;
	}

	std::cout << "! " << ans << std::endl;
}

int main() {
	int _;
	std::cin >> _;
	while(_ --) {
		solve();
	}
}