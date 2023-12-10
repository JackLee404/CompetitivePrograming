#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n), ans;

	std::vector<std::pair<int, int>> a1, a2;

	int c1, c2;
	c1 = c2 = 0;

	for(int i = 0; i < n; i ++) {
		std::cin >> a[i];
		if(a[i] % 2 == 0) c2 ++, a2.push_back({a[i], i + 1});
		else c1 ++, a1.push_back({a[i], i + 1});
	}
	if(a1.size() >= 3) {
		puts("YES");
		for(int i = 0; i < 3; i ++) {
			std::cout << a1[i].second << " \n"[i == 2];
		}
	} else if(a2.size() >= 2 && a1.size() >= 1) {
		std::vector<int> t;
		t.push_back(a2[0].second);
		t.push_back(a2[1].second);
		t.push_back(a1[0].second);
		std::sort(t.begin(), t.end());
		puts("YES");
		for(int i = 0; i < 3; i ++) {
			std::cout << t[i] << " \n"[i == 2];
		}
	} else {
		puts("NO");
	}
 }

int main() {
	int _;
	std::cin >> _;
	while(_ --) {
		solve();
	}
}